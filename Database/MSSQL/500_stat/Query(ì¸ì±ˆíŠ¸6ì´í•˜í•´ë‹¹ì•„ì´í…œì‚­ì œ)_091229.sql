
-----------------------------------------------------------------------------------------------------------------------
-- 해당 서버그룹DB(atum2_db_[n], atum2_db_arena 제외)에서 아래의 쿼리를 반드시 순서(1, 2, 3)대로 진행되어야 함.
-- 쿼리 정보: 아래의 ItemNum(총22개) 중에 인챈트가 6개 이하인 아이템과 해당 아이템의 인챈트를 삭제한다.

        -- 1. 아래의 ItemNum 중에 인챈트가 6개 이하인 아이템을 삭제한다.
        DELETE td_store
        FROM td_store s INNER JOIN (SELECT e.TargetItemUniqueNumber, COUNT(e.TargetItemUniqueNumber) as EnchantCount
                                       FROM td_enchant e WITH(NOLOCK) INNER JOIN td_store s WITH(NOLOCK) ON e.TargetItemUniqueNumber = s.UniqueNumber
                                       WHERE (s.itemnum = 7025730 OR s.itemnum = 7025740 OR s.itemnum = 7027145 OR s.itemnum = 7027320 OR s.itemnum = 7027495 OR s.itemnum = 7027670 OR s.itemnum = 7027845
                                                OR s.itemnum = 7028020 OR s.itemnum = 7028195 OR s.itemnum = 7028370 OR s.itemnum = 7028545 OR s.itemnum = 7028720 OR s.itemnum = 7910060 OR s.itemnum = 7911100
                                                OR s.itemnum = 7911110 OR s.itemnum = 7911120 OR s.itemnum = 7911130 OR s.itemnum = 7911140 OR s.itemnum = 7910070 OR s.itemnum = 7911150 OR s.itemnum = 7911160 OR s.itemnum = 7911170)
                                                GROUP BY e.TargetItemUniqueNumber
                                                HAVING COUNT(e.TargetItemUniqueNumber) <= 6) tme
            ON s.UniqueNumber = tme.TargetItemUniqueNumber
        
        -- 2. 인챈트 타겟 아이템이 없는 인챈트 정보를 모두 제거 한다.
        DELETE e 
        FROM td_enchant e
        WHERE e.TargetItemUniqueNumber NOT IN (SELECT UniqueNumber FROM td_store WITH(NOLOCK))

        -- 3. 아래의 ItemNum 중에 인챈트가 없는 아이템 제거
        DELETE td_store 
        FROM td_store s 
        WHERE (s.itemnum = 7025730 OR s.itemnum = 7025740 OR s.itemnum = 7027145 OR s.itemnum = 7027320 OR s.itemnum = 7027495 OR s.itemnum = 7027670 OR s.itemnum = 7027845
                OR s.itemnum = 7028020 OR s.itemnum = 7028195 OR s.itemnum = 7028370 OR s.itemnum = 7028545 OR s.itemnum = 7028720 OR s.itemnum = 7910060 OR s.itemnum = 7911100
                OR s.itemnum = 7911110 OR s.itemnum = 7911120 OR s.itemnum = 7911130 OR s.itemnum = 7911140 OR s.itemnum = 7910070 OR s.itemnum = 7911150 OR s.itemnum = 7911160 OR s.itemnum = 7911170)
                AND s.UniqueNumber NOT IN (SELECT TargetItemUniqueNumber FROM td_Enchant WITH(NOLOCK));
--
-----------------------------------------------------------------------------------------------------------------------