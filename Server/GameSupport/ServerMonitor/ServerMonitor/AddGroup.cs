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
    public partial class AddGroup : Form
    {
        private GroupEdit ge;
        public AddGroup(GroupEdit _ge)
        {
            InitializeComponent();
            ge = _ge;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (txtName.Text.Length == 0)
            {
                MessageBox.Show("이름을 입력해주세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            GroupObject go = new GroupObject();
            go.Name = txtName.Text;
            try
            {
                ge.sm.Groups.Add(go.Name, go);
            }
            catch (Exception ee)
            {
                MessageBox.Show("해당 이름이 이미 있습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            ge.sm.RefreshData();
            ge.ShowGroup();
            Close();
        }

        private void AddGroup_Load(object sender, EventArgs e)
        {
            txtName.Focus();
        }
    }
}
