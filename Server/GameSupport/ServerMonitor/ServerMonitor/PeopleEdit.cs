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
    public partial class PeopleEdit : Form
    {
        private GroupEdit ge;
        private GroupObject go;
        private PeopleObject po;
        public PeopleEdit(GroupEdit _ge,GroupObject _go,PeopleObject _po)
        {
            InitializeComponent();
            ge = _ge;
            go = _go;
            po = _po;
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
            if (txtAddr.Text.Length == 0)
            {
                MessageBox.Show("전화번호를 입력해주세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            foreach (char ch in txtAddr.Text)
            {
                if (!Char.IsDigit(ch))
                {
                    MessageBox.Show("전화번호는 숫자만 입력해주세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            bool add = false;
            if (po == null)
            {
                po = new PeopleObject();
                po.Name = txtName.Text;
                add = true;
            }
            po.Phone = txtAddr.Text;
            if (add)
            {
                try
                {
                    go.Peoples.Add(po.Name, po);
                }
                catch (Exception ee)
                {
                    MessageBox.Show("해당 이름이 이미 있습니다.", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            ge.sm.RefreshData();
            ge.ShowPeople(go);
            Close();
        }

        private void PeopleEdit_Load(object sender, EventArgs e)
        {
            if(po != null) {
                txtName.Text = po.Name;
                txtAddr.Text = po.Phone;
                txtName.Enabled = false;
            }
        }

        private void txtAddr_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }
    }
}
