using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ServerMonitor
{
    public partial class GroupEdit : Form
    {
        public ServerMonitor sm;
        private GroupObject selectedGroup;
        public GroupEdit(ServerMonitor _sm)
        {
            InitializeComponent();
            sm = _sm;
        }
        public void ShowGroup() {
            groupList.BeginUpdate();
            groupList.Items.Clear();
            foreach (KeyValuePair<string, GroupObject> entry in sm.Groups)
            {
                groupList.Items.Add(entry.Value.Name);
            }
            groupList.EndUpdate();
            ShowPeople(null);
        }
        private void GroupEdit_Load(object sender, EventArgs e)
        {
            ShowGroup();
        }
        public void ShowPeople(GroupObject go)
        {
            if(go == null) {
                selectedGroup = null;
                peopleList.Items.Clear();
                peopleList.Enabled = false;
                return;
            }
            selectedGroup = go;
            peopleList.Enabled = true;
            peopleList.BeginUpdate();
            peopleList.Items.Clear();
            foreach (KeyValuePair<string, PeopleObject> entry in selectedGroup.Peoples)
            {
                ListViewItem iItem = new ListViewItem(entry.Value.Name);
                iItem.SubItems.Add(entry.Value.Phone);
                peopleList.Items.Add(iItem);
            }
            peopleList.EndUpdate();
        }
        private void groupList_SelectedIndexChanged(object sender, EventArgs e)
        {
            GroupObject go;
            if (groupList.SelectedItem == null || !sm.Groups.TryGetValue(groupList.SelectedItem.ToString(),out go)) {
                ShowPeople(null);
                return;
            }
            ShowPeople(go);
        }

        private void 추가ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new AddGroup(this).ShowDialog();
        }

        private void groupList_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                if (groupList.SelectedItem != null) groupMenu.Items[1].Visible = true;
                else groupMenu.Items[1].Visible = false;
                groupMenu.Show(Cursor.Position);
            }
        }

        private void 삭제ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            object obj = groupList.SelectedItem;
            GroupObject go;
            if (obj == null || !sm.Groups.TryGetValue(obj.ToString(), out go)) return;
            if (MessageBox.Show("'" + go.Name + "' 그룹을 삭제하시겠습니까?", "삭제", MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes) return;
            sm.Groups.Remove(go.Name);
            foreach (KeyValuePair<string, ServerObject> entry in sm.Servers)
            {
                entry.Value.Groups.Remove(go.Name);
            }
            sm.RefreshData();
            ShowGroup();
        }

        private void peopleList_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                ListViewItem item = peopleList.GetItemAt(e.X, e.Y);
                if (item != null)
                {
                    peopleMenu.Items[1].Visible = true;
                    peopleMenu.Items[2].Visible = true;
                    peopleMenu.Show(Cursor.Position);
                }
                else
                {
                    peopleMenu.Items[1].Visible = false;
                    peopleMenu.Items[2].Visible = false;
                    peopleMenu.Show(Cursor.Position);
                }
            }
        }

        private void 추가ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (selectedGroup == null) return;
            new PeopleEdit(this, selectedGroup, null).ShowDialog();
        }

        private void 수정ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (selectedGroup == null) return;
            PeopleObject po;
            if (peopleList.FocusedItem == null || !selectedGroup.Peoples.TryGetValue(peopleList.FocusedItem.Text, out po)) return;
            new PeopleEdit(this, selectedGroup, po).ShowDialog();
        }

        private void 삭제ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (selectedGroup == null) return;
            PeopleObject po;
            if (peopleList.FocusedItem == null || !selectedGroup.Peoples.TryGetValue(peopleList.FocusedItem.Text, out po)) return;
            if (MessageBox.Show("'" + po.Name + "'을 삭제하시겠습니까?", "삭제", MessageBoxButtons.YesNo, MessageBoxIcon.Question) != DialogResult.Yes) return;
            selectedGroup.Peoples.Remove(po.Name);
            sm.RefreshData();
            ShowPeople(selectedGroup);
        }
    }
}
