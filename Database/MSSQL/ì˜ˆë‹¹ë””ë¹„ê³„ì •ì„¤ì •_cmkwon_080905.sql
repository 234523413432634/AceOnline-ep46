-- // 예당 보안 계정 설정하기 - SQL Server 2005 에서만 지원됨

-- 1. 게임서버 사용 계정 추가하기 <계정 추가만 해서는 로그인이 불가능하다>
	-- 1.1 계정 추가하기 - sp_addlogin 'User', 'password', 'defaut DatabaseName'
		sp_addlogin 'atum', 'callweb', 'atum2_db_account'

	-- 1.2 각 디비에 추가된 유저를 등록 하고 실행권한만 주기 - atum2_db_account, atum2_db_1, atum2_db_arena
		USE atum2_db_account
		GO
		sp_adduser 'atum'					-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE TO atum

		USE atum2_db_1
		GO
		sp_adduser 'atum'					-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE TO atum

		USE atum2_db_arena
		GO
		sp_adduser 'atum'					-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE TO atum


-- 2. 숨긴 계정 추가하기
	-- 2.1 계정 추가하기 - sp_addlogin 'User', 'password', 'defaut DatabaseName'
		sp_addlogin 'proexe', 'callweb', 'atum2_db_account'

	-- 2.2 각 디비에 추가된 유저를 등록 하고 실행(EXECUTE), 일반쿼리(SELECT, UPDATE, DELETE, INSERT) - atum2_db_account, atum2_db_1, atum2_db_arena
		USE atum2_db_account
		GO
		sp_adduser 'proexe'											-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- 실행(EXECUTE), 일반쿼리(SELECT, UPDATE, DELETE, INSERT) 권한 주기
		GO
		sp_helprotect null, 'proexe'								-- 설정된 권한 확인하기
		GO

		USE atum2_db_1
		GO
		sp_adduser 'proexe'											-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- 실행(EXECUTE), 일반쿼리(SELECT, UPDATE, DELETE, INSERT) 권한 주기
		GO
		sp_helprotect null, 'proexe'								-- 설정된 권한 확인하기
		GO

		USE atum2_db_arena
		GO
		sp_adduser 'proexe'											-- 현재 DB에 계정을 등록한다.<로그인이 가능해 진다>
		GRANT EXECUTE, SELECT, UPDATE, DELETE, INSERT TO proexe		-- 실행(EXECUTE), 일반쿼리(SELECT, UPDATE, DELETE, INSERT) 권한 주기
		GO
		sp_helprotect NULL, 'proexe'								-- 설정된 권한 확인하기
		GO

	-- 2.3 각 DB 에 다른 DB에 테이블 접근 권한 주기
		ALTER DATABASE atum2_db_account		SET TRUSTWORTHY ON			-- 다른 DB에서 해당 DB에 접근을 허용 한다.
		ALTER DATABASE atum2_db_1			SET TRUSTWORTHY ON			-- 다른 DB에서 해당 DB에 접근을 허용 한다.
		ALTER DATABASE atum2_db_arena		SET TRUSTWORTHY ON			-- 다른 DB에서 해당 DB에 접근을 허용 한다.


