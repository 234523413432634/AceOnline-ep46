
	-- 계정 추가하기 ==> sp_addlogin 'User', 'password', 'defaut DatabaseName'
	sp_addlogin 'user', 'pass', 'atum2_db_account'

	-- 해당 DB에 계정을 등록한다.<로그인이 가능해 진다> ==>
	sp_adduser 'user'


	-- 현재의 Database의 소유권을 sa 로 변경한다. ==> 
	sp_changedbowner 'sa'

	-- 현재의 Database에 proexe 계정의 권한 확인하기
	sp_helprotect null, 'proexe'

