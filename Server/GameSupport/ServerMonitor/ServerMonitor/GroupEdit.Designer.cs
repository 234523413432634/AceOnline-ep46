namespace ServerMonitor
{
    partial class GroupEdit
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GroupEdit));
            this.groupList = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.peopleList = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.추가ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.삭제ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.peopleMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.추가ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.수정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.삭제ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.groupMenu.SuspendLayout();
            this.peopleMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupList
            // 
            this.groupList.FormattingEnabled = true;
            this.groupList.ItemHeight = 12;
            this.groupList.Location = new System.Drawing.Point(12, 27);
            this.groupList.Name = "groupList";
            this.groupList.Size = new System.Drawing.Size(202, 268);
            this.groupList.TabIndex = 0;
            this.groupList.SelectedIndexChanged += new System.EventHandler(this.groupList_SelectedIndexChanged);
            this.groupList.MouseDown += new System.Windows.Forms.MouseEventHandler(this.groupList_MouseDown);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "그룹 목록";
            // 
            // peopleList
            // 
            this.peopleList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2});
            this.peopleList.Location = new System.Drawing.Point(222, 27);
            this.peopleList.MultiSelect = false;
            this.peopleList.Name = "peopleList";
            this.peopleList.Size = new System.Drawing.Size(363, 268);
            this.peopleList.TabIndex = 5;
            this.peopleList.UseCompatibleStateImageBehavior = false;
            this.peopleList.View = System.Windows.Forms.View.Details;
            this.peopleList.MouseDown += new System.Windows.Forms.MouseEventHandler(this.peopleList_MouseDown);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "이름";
            this.columnHeader1.Width = 160;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "전화번호";
            this.columnHeader2.Width = 180;
            // 
            // groupMenu
            // 
            this.groupMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.추가ToolStripMenuItem,
            this.삭제ToolStripMenuItem});
            this.groupMenu.Name = "groupMenu";
            this.groupMenu.Size = new System.Drawing.Size(99, 48);
            // 
            // 추가ToolStripMenuItem
            // 
            this.추가ToolStripMenuItem.Name = "추가ToolStripMenuItem";
            this.추가ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.추가ToolStripMenuItem.Text = "추가";
            this.추가ToolStripMenuItem.Click += new System.EventHandler(this.추가ToolStripMenuItem_Click);
            // 
            // 삭제ToolStripMenuItem
            // 
            this.삭제ToolStripMenuItem.Name = "삭제ToolStripMenuItem";
            this.삭제ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.삭제ToolStripMenuItem.Text = "삭제";
            this.삭제ToolStripMenuItem.Click += new System.EventHandler(this.삭제ToolStripMenuItem_Click);
            // 
            // peopleMenu
            // 
            this.peopleMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.추가ToolStripMenuItem1,
            this.수정ToolStripMenuItem,
            this.삭제ToolStripMenuItem1});
            this.peopleMenu.Name = "peopleMenu";
            this.peopleMenu.Size = new System.Drawing.Size(99, 70);
            // 
            // 추가ToolStripMenuItem1
            // 
            this.추가ToolStripMenuItem1.Name = "추가ToolStripMenuItem1";
            this.추가ToolStripMenuItem1.Size = new System.Drawing.Size(98, 22);
            this.추가ToolStripMenuItem1.Text = "추가";
            this.추가ToolStripMenuItem1.Click += new System.EventHandler(this.추가ToolStripMenuItem1_Click);
            // 
            // 수정ToolStripMenuItem
            // 
            this.수정ToolStripMenuItem.Name = "수정ToolStripMenuItem";
            this.수정ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.수정ToolStripMenuItem.Text = "수정";
            this.수정ToolStripMenuItem.Click += new System.EventHandler(this.수정ToolStripMenuItem_Click);
            // 
            // 삭제ToolStripMenuItem1
            // 
            this.삭제ToolStripMenuItem1.Name = "삭제ToolStripMenuItem1";
            this.삭제ToolStripMenuItem1.Size = new System.Drawing.Size(98, 22);
            this.삭제ToolStripMenuItem1.Text = "삭제";
            this.삭제ToolStripMenuItem1.Click += new System.EventHandler(this.삭제ToolStripMenuItem1_Click);
            // 
            // GroupEdit
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(596, 309);
            this.Controls.Add(this.peopleList);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupList);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "GroupEdit";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "그룹 설정";
            this.Load += new System.EventHandler(this.GroupEdit_Load);
            this.groupMenu.ResumeLayout(false);
            this.peopleMenu.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox groupList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView peopleList;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ContextMenuStrip groupMenu;
        private System.Windows.Forms.ToolStripMenuItem 추가ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 삭제ToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip peopleMenu;
        private System.Windows.Forms.ToolStripMenuItem 추가ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 수정ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 삭제ToolStripMenuItem1;
    }
}