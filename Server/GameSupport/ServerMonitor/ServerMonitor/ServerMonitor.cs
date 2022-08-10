using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using System.Net;
using System.Net.Sockets;
using CookComputing.XmlRpc;
using System.Collections.Concurrent;


namespace ServerMonitor
{
    public partial class ServerMonitor : Form
    {
        private volatile bool SMSthreadEnd = false;
        delegate void LogCallback(String a);
        delegate void ConnectCallback(ServerObject so,bool result);
        public Dictionary<String, ServerObject> Servers = new Dictionary<String, ServerObject>();
        public Dictionary<String, GroupObject> Groups = new Dictionary<String, GroupObject>();
        private BlockingCollection<SMSObject> smsList = new BlockingCollection<SMSObject>();
        private Thread smsThread;
        public ServerMonitor()
        {
            InitializeComponent();
        }
        private static string Base64Encode(string src)
        {
            return Convert.ToBase64String(Encoding.UTF8.GetBytes(src));
        }

        private static string Base64Decode(string src)
        {
            return Encoding.UTF8.GetString(Convert.FromBase64String(src));
        }
        private void SMSWokrer()
        {
            IGabiaSMS sms = XmlRpcProxyGen.Create<IGabiaSMS>();
            while(true)
            {
                SMSObject s;
                if (SMSthreadEnd) break;
                if(!smsList.TryTake(out s, 100)) continue;
                if(s==null || s.text == null) break;

                foreach (String phone in s.phones)
                {
                    String req = MakeSMSRequest("025882665", phone, s.text);
                    //Log("DEBUG: SMSWorker req:" + req);
                    try
                    {
                        String result = sms.Sms(req);
                        if(result.IndexOf("<code>0000</code>") == -1) {
                            Log("Failed to Send SMS text:" + s.text + " to:" + phone + " result:" + result);
                        }
                    }
                    catch (Exception ex)
                    {
                        Log("Failed to Send SMS text:" + s.text + " to:" + phone + " e:" + ex.ToString());
                    }
                }
            }
        }
        private void SaveConfig()
        {
            StreamWriter sw = new StreamWriter("config.txt", false, Encoding.UTF8);
            foreach (KeyValuePair<string, GroupObject> entry in Groups)
            {
                sw.WriteLine("GROUP|" + Base64Encode(entry.Value.Name));
                foreach (KeyValuePair<string, PeopleObject> entry2 in entry.Value.Peoples)
                {
                    sw.WriteLine("PEOPLE|" + Base64Encode(entry.Value.Name) + "|" + Base64Encode(entry2.Value.Name) + "|" + Base64Encode(entry2.Value.Phone));
                }
            }
            foreach (KeyValuePair<string, ServerObject> entry in Servers)
            {
                sw.WriteLine("SERVER|" + Base64Encode(entry.Value.Name) + "|" + BitConverter.ToUInt32(entry.Value.Addr.GetAddressBytes(), 0).ToString() + "|" + entry.Value.Port.ToString());
                foreach (String entry2 in entry.Value.Groups)
                {
                    sw.WriteLine("SERVERGROUP|" + Base64Encode(entry.Value.Name) + "|" + Base64Encode(entry2));
                }
            }
            sw.Close();
        }
        private void LoadConfig()
        {
            try
            {
                StreamReader sr = new StreamReader("config.txt", Encoding.UTF8);
                String line;
                Servers.Clear();
                Groups.Clear();
                while ((line = sr.ReadLine()) != null)
                {
                    String[] tmp = line.Split('|');
                    if (tmp[0] == "GROUP" && tmp.Length == 2)
                    {
                        try
                        {
                            GroupObject go = new GroupObject();
                            go.Name = Base64Decode(tmp[1]);
                            Groups.Add(go.Name, go);
                        }
                        catch (Exception e)
                        {
                        }
                    }
                    else if (tmp[0] == "PEOPLE" && tmp.Length == 4)
                    {
                        GroupObject go;
                        if (!Groups.TryGetValue(Base64Decode(tmp[1]), out go)) continue;
                        try
                        {
                            PeopleObject po = new PeopleObject();
                            po.Name = Base64Decode(tmp[2]);
                            po.Phone = Base64Decode(tmp[3]);
                            go.Peoples.Add(po.Name, po);
                        }
                        catch (Exception e)
                        {
                        }
                    }
                    else if (tmp[0] == "SERVER" && tmp.Length == 4)
                    {
                        try
                        {
                            ServerObject so = new ServerObject();
                            so.Name = Base64Decode(tmp[1]);
                            so.Addr = new IPAddress(Convert.ToUInt32(tmp[2]));
                            so.Port = Convert.ToUInt16(tmp[3]);
                            Servers.Add(so.Name, so);
                        }
                        catch (Exception e) { }
                    }
                    else if (tmp[0] == "SERVERGROUP" && tmp.Length == 3)
                    {
                        GroupObject go;
                        ServerObject so;
                        if (!Servers.TryGetValue(Base64Decode(tmp[1]), out so)) continue;
                        if (!Groups.TryGetValue(Base64Decode(tmp[2]), out go)) continue;
                        try
                        {
                            so.Groups.Add(go.Name);
                        }
                        catch (Exception e) { }
                    }
                }
                sr.Close();
            } catch(Exception e) {
                MessageBox.Show("config.txt을 찾을 수 없습니다.");
                //Close();
                return;
            }
            SaveConfig();
        }
        private void ServerMonitor_Load(object sender, EventArgs e)
        {
            LoadConfig();
            UpdateList();
            smsThread = new Thread(new ThreadStart(SMSWokrer));
            smsThread.Start();
            CheckTimer.Enabled = true;
            Log("서버 모니터링 프로그램이 시작되었습니다.");
            
        }
        public void RefreshData() {
            UpdateList();
            SaveConfig();
        }

        private void UpdateList()
        {
            bool startUpdate=false;
            
            //viewServer.Items.Clear();
            int i = 0;
            foreach (KeyValuePair<string, ServerObject> entry in Servers)
            {
                String status;
                if (entry.Value.firstCheck)
                {
                    status = "확인중..";
                }
                else if (entry.Value.online)
                {
                    status = "온라인";
                }
                else
                {
                    status = "오프라인(" + entry.Value.ChangedTime.ToString() + ")";
                }
                if (i < viewServer.Items.Count)
                {
                    String addr = entry.Value.Addr.ToString() + ":" + entry.Value.Port.ToString();
                    if (viewServer.Items[i].SubItems[0].Text != entry.Value.Name || viewServer.Items[i].SubItems[1].Text != addr || viewServer.Items[i].SubItems[2].Text != status)
                    {
                        if (!startUpdate)
                        {
                            viewServer.BeginUpdate();
                            startUpdate = true;
                        }
                        viewServer.Items[i].SubItems[0].Text = entry.Value.Name;
                        viewServer.Items[i].SubItems[1].Text = addr;
                        viewServer.Items[i].SubItems[2].Text = status;
                    }
                }
                else
                {
                    if(!startUpdate) {
                        viewServer.BeginUpdate();
                        startUpdate=true;
                    }
                    ListViewItem iItem = new ListViewItem(entry.Value.Name);
                    iItem.SubItems.Add(entry.Value.Addr.ToString() + ":" + entry.Value.Port.ToString());
                    iItem.SubItems.Add(status);
                    viewServer.Items.Add(iItem);
                }
                i++;
            }
            int remain= viewServer.Items.Count - i;
            while( remain-- > 0) {
                if (!startUpdate)
                {
                    viewServer.BeginUpdate();
                    startUpdate = true;
                }
                viewServer.Items.RemoveAt(viewServer.Items.Count - 1);
            }
            if(startUpdate)viewServer.EndUpdate();
        }
        public void Log(String a)
        {
            if(txtLog.InvokeRequired) {
                this.Invoke(new LogCallback(Log),new object[] {a});
                return;
            }
            txtLog.Text += "[" + DateTime.Now.ToString("G") + "] " + a + "\r\n";
            txtLog.SelectionStart = txtLog.Text.Length;
            txtLog.ScrollToCaret();
            //txtLog.Scrol
        }
        private void ConnectCall(ServerObject so,bool result)
        {
            so.s.Close();
            so.s.Dispose();
            so.s = null;
            if (so.Changed)
            {
                so.online = false;
                so.firstCheck = true;
                so.Changed = false;
            }
            else
            {
                if (so.firstCheck) so.sentOfflineSMS = true;
                if (so.online != result)
                {
                    so.ChangedTime = DateTime.Now;
                    if (!so.firstCheck)
                    {
                        if (!result)
                        {
                            Log(so.Name + " 서버가 꺼졌습니다.");
                            so.sentOfflineSMS = false;
                            so.OfflineThresold = 1;
                            //sms = DateTime.Now.ToString("HH:mmm:ss") + " " + so.Name + "(" + so.Addr.ToString() + ") 서버가 꺼졌습니다.";
                        } else {
                            Log(so.Name + " 서버가 켜졌습니다.");
                        }
                        if (result && so.sentOfflineSMS)
                        {
                            Log(so.Name + " 서버가 켜졌다고 문자를 보냄.");
                            SMSObject smo = new SMSObject();
                            smo.text = DateTime.Now.ToString("HH:mmm:ss") + " " + so.Name + "(" + so.Addr.ToString() + ") 서버가 켜졌습니다.";
                            foreach (String g in so.Groups)
                            {
                                GroupObject go;
                                if (!Groups.TryGetValue(g, out go)) continue;
                                foreach (KeyValuePair<String, PeopleObject> entry in go.Peoples)
                                {
                                    smo.phones.Add(entry.Value.Phone);
                                }
                            }
                            smsList.TryAdd(smo, -1);
                        }
                    }
                } else if(!result && !so.sentOfflineSMS)
                {
                    so.OfflineThresold++;
                    if(so.OfflineThresold >= 2)
                    {
                        so.sentOfflineSMS = true;
                        Log(so.Name + " 서버가 꺼졌다고 문자를 보냄.");
                        SMSObject smo = new SMSObject();
                        smo.text = so.ChangedTime.ToString("HH:mmm:ss") + " " + so.Name + "(" + so.Addr.ToString() + ") 서버가 꺼졌습니다.";
                        foreach (String g in so.Groups)
                        {
                            GroupObject go;
                            if (!Groups.TryGetValue(g, out go)) continue;
                            foreach (KeyValuePair<String, PeopleObject> entry in go.Peoples)
                            {
                                smo.phones.Add(entry.Value.Phone);
                            }
                        }
                        smsList.TryAdd(smo, -1);
                    }
                }
                so.online = result;
                if (so.firstCheck) so.firstCheck = false;
            }
            so.LastCheck = DateTime.Now;
            UpdateList();
        }
        private void ConnectCompleted(object sender, SocketAsyncEventArgs e)
        {
            this.Invoke(new ConnectCallback(ConnectCall), new object[] { e.UserToken, e.ConnectSocket != null ? true : false });
            e.Dispose();
        }
        private void CheckTimer_Tick(object sender, EventArgs e)
        {
            foreach(KeyValuePair<String,ServerObject> entry in Servers)
            {
                if (entry.Value.s == null && (DateTime.Now - entry.Value.LastCheck).TotalSeconds >= 2)
                {
                    entry.Value.SocketConnectTime = DateTime.Now;
                    entry.Value.s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    SocketAsyncEventArgs ae = new SocketAsyncEventArgs();
                    ae.RemoteEndPoint = new IPEndPoint(entry.Value.Addr, entry.Value.Port);
                    ae.UserToken = entry.Value;
                    ae.Completed += new EventHandler<SocketAsyncEventArgs>(ConnectCompleted);
                    if(!entry.Value.s.ConnectAsync(ae)) {
                        ae.Dispose();
                        //entry.Value.s.Dispose();
                        entry.Value.s = null;
                    }
                }
                else if (entry.Value.s != null && (DateTime.Now - entry.Value.SocketConnectTime).TotalSeconds >= 3)
                {
                    entry.Value.s.Close();
                }

            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            isExiting = true;
            Close();
        }

        private void viewServer_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                ListViewItem item = viewServer.GetItemAt(e.X, e.Y);
                if (item != null)
                {
                    listviewMenu.Items[0].Visible = true;
                    listviewMenu.Items[1].Visible = true;
                    listviewMenu.Show(Cursor.Position);
                }
                else
                {
                    listviewMenu.Items[0].Visible = false;
                    listviewMenu.Items[1].Visible = false;
                    listviewMenu.Show(Cursor.Position);
                }
            }
        }

        private void 수정ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ServerObject so;
            if (viewServer.FocusedItem == null || !Servers.TryGetValue(viewServer.FocusedItem.Text, out so)) return;
            new ServerEdit(this,so).ShowDialog();

        }

        private void 삭제ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ServerObject so;
            if (viewServer.FocusedItem == null || !Servers.TryGetValue(viewServer.FocusedItem.Text, out so)) return;
            if (MessageBox.Show("'" + so.Name + "'을 삭제하시겠습니까?", "삭제", MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes) return;
            Servers.Remove(so.Name);
            RefreshData();
            so.Changed = true;
            if (so.s != null) so.s.Close();
        }

        private void 추가ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new ServerEdit(this, null).ShowDialog();
        }

        private void cmdSetup_Click(object sender, EventArgs e)
        {
            new GroupEdit(this).ShowDialog();
        }

        private void viewServer_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        public string CreateMD5Hash(string input)
        {
            // Use input string to calculate MD5 hash
            System.Security.Cryptography.MD5 md5 = System.Security.Cryptography.MD5.Create();
            byte[] inputBytes = System.Text.Encoding.ASCII.GetBytes(input);
            byte[] hashBytes = md5.ComputeHash(inputBytes);

            // Convert the byte array to hexadecimal string
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < hashBytes.Length; i++)
            {
                sb.Append(hashBytes[i].ToString("x2"));
                // To force the hex string to lower-case letters instead of
                // upper-case, use he following line instead:
                // sb.Append(hashBytes[i].ToString("x2")); 
            }
            return sb.ToString();
        }
        private static String SMSUser = "masang";
        private static String SMSKey = "51d53b88e1a88cae4187a25a1145c1eb";
        private String MakeSMSRequest(string callback , string to , string text)
        {
            String nonce = CreateMD5Hash(DateTime.Now.ToString() + "@@@nonce").Substring(0,8);
            String token = nonce + CreateMD5Hash(nonce + SMSKey);
            StringBuilder s = new StringBuilder();
            s.Append("<request>\n<sms-id>");
            s.Append(SMSUser);
            s.Append("</sms-id>\n<access-token>");
            s.Append(token);
            s.Append("</access-token>\n<response-format>xml</response-format>\n<method>SMS.send</method>\n<params>\n<send_type>sms</send_type>\n<ref_key>");
            s.Append("refkey");
            s.Append("</ref_key>\n<subject></subject>\n<message>");
            s.Append(System.Security.SecurityElement.Escape(text));
            s.Append("</message>\n<callback>");
            s.Append(System.Security.SecurityElement.Escape(callback));
            s.Append("</callback>\n<phone>");
            s.Append(System.Security.SecurityElement.Escape(to));
            s.Append("</phone>\n<reserve>0</reserve>\n</params>\n</request>\n");
            return s.ToString();
        }
        private bool isExiting = false;
        private void ServerMonitor_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!isExiting)
            {
                e.Cancel = true;
                this.Visible = false;
                return;
            }
            SMSthreadEnd = true;
            smsList.TryAdd(new SMSObject(), -1);
            smsThread.Join();
        }

        private void 보이기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Visible = true;
        }

        private void 종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            isExiting = true;
            Close();
        }

        private void trayIocn_DoubleClick(object sender, EventArgs e)
        {
            this.Visible = true;
        }
    }
    public class ServerObject
    {
        public IPAddress Addr;
        public UInt16 Port;
        public String Name;
        public List<String> Groups = new List<String>();
        public bool firstCheck = true;
        public bool online = false;
        public bool Changed = false;
        public Socket s;
        public DateTime SocketConnectTime;
        public DateTime ChangedTime=DateTime.Now;
        public DateTime LastCheck;
        public bool sentOfflineSMS = false;
        public int OfflineThresold = 0;
    }
    public class SMSObject
    {
        public String text;
        public List<String> phones = new List<String>();
    }
    public class PeopleObject
    {
        public String Name;
        public String Phone;
    }
    public class GroupObject
    {
        public String Name;
        public Dictionary<String, PeopleObject> Peoples = new Dictionary<String, PeopleObject>();
    }
    [XmlRpcUrl("http://sms.gabia.com/api")]
    public interface IGabiaSMS : IXmlRpcProxy
    {
        [XmlRpcMethod("gabiasms")]
        string Sms(String value);

    }

}
