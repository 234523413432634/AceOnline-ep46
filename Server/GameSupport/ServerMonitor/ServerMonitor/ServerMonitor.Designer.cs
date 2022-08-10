namespace ServerMonitor
{
    partial class ServerMonitor
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ServerMonitor));
            this.btnExit = new System.Windows.Forms.Button();
            this.cmdSetup = new System.Windows.Forms.Button();
            this.CheckTimer = new System.Windows.Forms.Timer(this.components);
            this.txtLog = new System.Windows.Forms.TextBox();
            this.viewServer = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listviewMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.수정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.삭제ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.추가ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.trayIocn = new System.Windows.Forms.NotifyIcon(this.components);
            this.trayMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.보이기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.종료ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.listviewMenu.SuspendLayout();
            this.trayMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(468, 652);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 1;
            this.btnExit.Text = "종료";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // cmdSetup
            // 
            this.cmdSetup.Location = new System.Drawing.Point(13, 652);
            this.cmdSetup.Name = "cmdSetup";
            this.cmdSetup.Size = new System.Drawing.Size(75, 23);
            this.cmdSetup.TabIndex = 2;
            this.cmdSetup.Text = "그룹 설정";
            this.cmdSetup.UseVisualStyleBackColor = true;
            this.cmdSetup.Click += new System.EventHandler(this.cmdSetup_Click);
            // 
            // CheckTimer
            // 
            this.CheckTimer.Tick += new System.EventHandler(this.CheckTimer_Tick);
            // 
            // txtLog
            // 
            this.txtLog.Location = new System.Drawing.Point(13, 360);
            this.txtLog.Multiline = true;
            this.txtLog.Name = "txtLog";
            this.txtLog.ReadOnly = true;
            this.txtLog.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtLog.Size = new System.Drawing.Size(530, 286);
            this.txtLog.TabIndex = 3;
            // 
            // viewServer
            // 
            this.viewServer.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.viewServer.Location = new System.Drawing.Point(13, 13);
            this.viewServer.MultiSelect = false;
            this.viewServer.Name = "viewServer";
            this.viewServer.Size = new System.Drawing.Size(530, 344);
            this.viewServer.TabIndex = 4;
            this.viewServer.UseCompatibleStateImageBehavior = false;
            this.viewServer.View = System.Windows.Forms.View.Details;
            this.viewServer.SelectedIndexChanged += new System.EventHandler(this.viewServer_SelectedIndexChanged);
            this.viewServer.MouseDown += new System.Windows.Forms.MouseEventHandler(this.viewServer_MouseDown);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "이름";
            this.columnHeader1.Width = 140;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "서버 주소";
            this.columnHeader2.Width = 130;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "상태";
            this.columnHeader3.Width = 230;
            // 
            // listviewMenu
            // 
            this.listviewMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.수정ToolStripMenuItem,
            this.삭제ToolStripMenuItem,
            this.추가ToolStripMenuItem});
            this.listviewMenu.Name = "listviewMenu";
            this.listviewMenu.Size = new System.Drawing.Size(99, 70);
            // 
            // 수정ToolStripMenuItem
            // 
            this.수정ToolStripMenuItem.Name = "수정ToolStripMenuItem";
            this.수정ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.수정ToolStripMenuItem.Text = "수정";
            this.수정ToolStripMenuItem.Click += new System.EventHandler(this.수정ToolStripMenuItem_Click);
            // 
            // 삭제ToolStripMenuItem
            // 
            this.삭제ToolStripMenuItem.Name = "삭제ToolStripMenuItem";
            this.삭제ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.삭제ToolStripMenuItem.Text = "삭제";
            this.삭제ToolStripMenuItem.Click += new System.EventHandler(this.삭제ToolStripMenuItem_Click);
            // 
            // 추가ToolStripMenuItem
            // 
            this.추가ToolStripMenuItem.Name = "추가ToolStripMenuItem";
            this.추가ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.추가ToolStripMenuItem.Text = "추가";
            this.추가ToolStripMenuItem.Click += new System.EventHandler(this.추가ToolStripMenuItem_Click);
            // 
            // trayIocn
            // 
            this.trayIocn.ContextMenuStrip = this.trayMenu;
            this.trayIocn.Icon = ((System.Drawing.Icon)(resources.GetObject("trayIocn.Icon")));
            this.trayIocn.Text = "ServerMonitor";
            this.trayIocn.Visible = true;
            this.trayIocn.DoubleClick += new System.EventHandler(this.trayIocn_DoubleClick);
            // 
            // trayMenu
            // 
            this.trayMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.보이기ToolStripMenuItem,
            this.종료ToolStripMenuItem});
            this.trayMenu.Name = "trayMenu";
            this.trayMenu.Size = new System.Drawing.Size(111, 48);
            // 
            // 보이기ToolStripMenuItem
            // 
            this.보이기ToolStripMenuItem.Name = "보이기ToolStripMenuItem";
            this.보이기ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.보이기ToolStripMenuItem.Text = "보이기";
            this.보이기ToolStripMenuItem.Click += new System.EventHandler(this.보이기ToolStripMenuItem_Click);
            // 
            // 종료ToolStripMenuItem
            // 
            this.종료ToolStripMenuItem.Name = "종료ToolStripMenuItem";
            this.종료ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.종료ToolStripMenuItem.Text = "종료";
            this.종료ToolStripMenuItem.Click += new System.EventHandler(this.종료ToolStripMenuItem_Click);
            // 
            // ServerMonitor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(559, 687);
            this.Controls.Add(this.viewServer);
            this.Controls.Add(this.txtLog);
            this.Controls.Add(this.cmdSetup);
            this.Controls.Add(this.btnExit);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "ServerMonitor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ServerMonitor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ServerMonitor_FormClosing);
            this.Load += new System.EventHandler(this.ServerMonitor_Load);
            this.listviewMenu.ResumeLayout(false);
            this.trayMenu.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Button cmdSetup;
        private System.Windows.Forms.Timer CheckTimer;
        private System.Windows.Forms.TextBox txtLog;
        private System.Windows.Forms.ListView viewServer;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ContextMenuStrip listviewMenu;
        private System.Windows.Forms.ToolStripMenuItem 수정ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 추가ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 삭제ToolStripMenuItem;
        private System.Windows.Forms.NotifyIcon trayIocn;
        private System.Windows.Forms.ContextMenuStrip trayMenu;
        private System.Windows.Forms.ToolStripMenuItem 보이기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 종료ToolStripMenuItem;
    }
}

