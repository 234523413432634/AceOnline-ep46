2014-02-12 by ymjoo AOWatchProcess를 제작하였습니다.

	사용 방법 : 
	1.	AOWatchProcess와 같은 디렉토리에 WatchProcessConfig.txt 파일을 만들고 다음과 같이 작성한다.
		(그룹과 그룹 사이는 개행 두번으로 구분한다.)
		(ProcessPath는 한 그룹에 같은 경로가 두 개 이상 있으면 안된다. - 자동 되살리기시 에러남)
======================
WatchProcessConfig.txt
======================
GroupName1
ProcessPath1
ProcessPath2

GroupName2
ProcessPath3

GroupName3
ProcessPath4
ProcessPath5
======================
	2.	실행한다.
	3.	큰 버튼(서버군 이름이 적혀 있는 버튼)을 눌러 서버를 올린다.
	4.	작은 버튼을 눌러 서버를 내린다.
	5.	자동 되살리기를 체크해두면, 도중에 죽은 서버를 자동으로 되살린다.