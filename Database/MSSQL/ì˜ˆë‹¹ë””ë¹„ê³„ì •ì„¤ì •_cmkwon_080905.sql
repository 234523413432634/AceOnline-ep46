-- // ���� ���� ���� �����ϱ� - SQL Server 2005 ������ ������

-- 1. ���Ӽ��� ��� ���� �߰��ϱ� <���� �߰��� �ؼ��� �α����� �Ұ����ϴ�>
	-- 1.1 ���� �߰��ϱ� - sp_addlogin 'User', 'password', 'defaut DatabaseName'
		sp_addlogin 'atum', 'callweb', 'atum2_db_account'

	-- 1.2 �� ��� �߰��� ������ ��� �ϰ� ������Ѹ� �ֱ� - atum2_db_account, atum2_db_1, atum2_db_arena
		USE atum2_db_account
		GO
		sp_adduser 'atum'					-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE TO atum

		USE atum2_db_1
		GO
		sp_adduser 'atum'					-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE TO atum

		USE atum2_db_arena
		GO
		sp_adduser 'atum'					-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE TO atum


-- 2. ���� ���� �߰��ϱ�
	-- 2.1 ���� �߰��ϱ� - sp_addlogin 'User', 'password', 'defaut DatabaseName'
		sp_addlogin 'proexe', 'callweb', 'atum2_db_account'

	-- 2.2 �� ��� �߰��� ������ ��� �ϰ� ����(EXECUTE), �Ϲ�����(SELECT, UPDATE, DELETE, INSERT) - atum2_db_account, atum2_db_1, atum2_db_arena
		USE atum2_db_account
		GO
		sp_adduser 'proexe'											-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- ����(EXECUTE), �Ϲ�����(SELECT, UPDATE, DELETE, INSERT) ���� �ֱ�
		GO
		sp_helprotect null, 'proexe'								-- ������ ���� Ȯ���ϱ�
		GO

		USE atum2_db_1
		GO
		sp_adduser 'proexe'											-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- ����(EXECUTE), �Ϲ�����(SELECT, UPDATE, DELETE, INSERT) ���� �ֱ�
		GO
		sp_helprotect null, 'proexe'								-- ������ ���� Ȯ���ϱ�
		GO

		USE atum2_db_arena
		GO
		sp_adduser 'proexe'											-- ���� DB�� ������ ����Ѵ�.<�α����� ������ ����>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- ����(EXECUTE), �Ϲ�����(SELECT, UPDATE, DELETE, INSERT) ���� �ֱ�
		GO
		sp_helprotect NULL, 'proexe'								-- ������ ���� Ȯ���ϱ�
		GO

	-- 2.3 �� DB �� �ٸ� DB�� ���̺� ���� ���� �ֱ�
		ALTER DATABASE atum2_db_account		SET TRUSTWORTHY ON			-- �ٸ� DB���� �ش� DB�� ������ ��� �Ѵ�.
		ALTER DATABASE atum2_db_1			SET TRUSTWORTHY ON			-- �ٸ� DB���� �ش� DB�� ������ ��� �Ѵ�.
		ALTER DATABASE atum2_db_arena		SET TRUSTWORTHY ON			-- �ٸ� DB���� �ش� DB�� ������ ��� �Ѵ�.


