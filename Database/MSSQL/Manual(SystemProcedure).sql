
	-- ���� �߰��ϱ� ==> sp_addlogin 'User', 'password', 'defaut DatabaseName'
	sp_addlogin 'user', 'pass', 'atum2_db_account'

	-- �ش� DB�� ������ ����Ѵ�.<�α����� ������ ����> ==>
	sp_adduser 'user'


	-- ������ Database�� �������� sa �� �����Ѵ�. ==> 
	sp_changedbowner 'sa'

	-- ������ Database�� proexe ������ ���� Ȯ���ϱ�
	sp_helprotect null, 'proexe'

