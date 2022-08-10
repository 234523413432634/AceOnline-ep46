using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;

namespace ServerMonitor
{
    public partial class ServerEdit : Form
    {
        private ServerObject so;
        private ServerMonitor sm;
        public ServerEdit(ServerMonitor _sm, ServerObject _so)
        {
            InitializeComponent();
            so = _so;
            sm = _sm;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            IPAddress ip;
            UInt16 port;
            try
            {
                ip = IPAddress.Parse(txtAddr.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("아이피가 올바르지 않습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            try
            {
                port = Convert.ToUInt16(txtPort.Text);
            }
            catch (Exception ee)
            {
                MessageBox.Show("포트가 올바르지 않습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (port <= 0 || port > 65535)
            {
                MessageBox.Show("포트가 올바르지 않습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            bool add = false;
            if (so == null)
            {
                if (txtName.Text.Length == 0)
                {
                    MessageBox.Show("이름을 입력해주세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                add = true;
                so = new ServerObject();
                so.Name = txtName.Text;
            }
            else if (!so.Addr.Equals(ip) || so.Port != port)
            {
                so.Changed = true;
                if (so.s != null) so.s.Close();
            }
            so.Addr = ip;
            so.Port = port;
            so.Groups.Clear();
            foreach(String a in viewGroup.Items)
            {
                if(sm.Groups.ContainsKey(a)) so.Groups.Add(a);
            }
            if (add)
            {
                try
                {
                    sm.Servers.Add(so.Name, so);
                }
                catch (Exception ee)
                {
                    MessageBox.Show("해당 이름이 이미 있습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            sm.RefreshData();
            Close();
        }

        private void ServerEdit_Load(object sender, EventArgs e)
        {
            if (so != null)
            {
                txtName.Text = so.Name;
                txtName.Enabled = false;
                txtAddr.Text = so.Addr.ToString();
                txtPort.Text = so.Port.ToString();
                foreach (String entry2 in so.Groups)
                {
                    viewGroup.Items.Add(entry2);
                }

            }
            foreach (KeyValuePair<string, GroupObject> entry in sm.Groups)
            {
                groupList.Items.Add(entry.Value.Name);
            }

        }


        private void btnGroupAdd_Click(object sender, EventArgs e)
        {
            object sel = groupList.SelectedItem;
            if (sel == null) return;
            if (viewGroup.FindString(sel.ToString())==-1) viewGroup.Items.Add(sel.ToString());
        }

        private void 삭제ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            object sel = viewGroup.SelectedItem;
            if (sel == null) return;
            viewGroup.Items.Remove(sel.ToString());
        }

        private void viewGroup_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right && viewGroup.SelectedItem != null)
            {
                groupListMenuStrip.Show(Cursor.Position);
            }
        }

        private void viewGroup_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
