
-- // 2008-05-02 by cmkwon
	SELECT TOP 1000 pb.UID, pb.Branch_Name, tp.SumPCBangPlayTime, pb.Branch_RegNo, pb.Branch_Tel, pb.ZipCode, pb.Addr_Sido, pb.Addr_SiGuGun, pb.Addr_Dong, pb.Addr_Detail
	FROM td_PCBang pb, (SELECT l.pcbanguid, SUM(l.pcbangplaytime) as SumPCBangPlayTime
						FROM atum_log_user_game_start_end l
						WHERE l.logtype = 20 and l.pcbanguid > 0 and l.Time > '2008-01-01 00:00:00'
						GROUP BY l.pcbanguid) as tp
	where pb.UID = tp.PCBangUID
	ORDER BY tp.SumPCBangPlayTime DESC