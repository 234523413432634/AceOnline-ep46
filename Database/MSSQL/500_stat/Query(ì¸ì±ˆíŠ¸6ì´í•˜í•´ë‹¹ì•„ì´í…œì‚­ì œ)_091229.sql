
-----------------------------------------------------------------------------------------------------------------------
-- �ش� �����׷�DB(atum2_db_[n], atum2_db_arena ����)���� �Ʒ��� ������ �ݵ�� ����(1, 2, 3)��� ����Ǿ�� ��.
-- ���� ����: �Ʒ��� ItemNum(��22��) �߿� ��æƮ�� 6�� ������ �����۰� �ش� �������� ��æƮ�� �����Ѵ�.

        -- 1. �Ʒ��� ItemNum �߿� ��æƮ�� 6�� ������ �������� �����Ѵ�.
        DELETE td_store
        FROM td_store s INNER JOIN (SELECT e.TargetItemUniqueNumber, COUNT(e.TargetItemUniqueNumber) as EnchantCount
                                       FROM td_enchant e WITH(NOLOCK) INNER JOIN td_store s WITH(NOLOCK) ON e.TargetItemUniqueNumber = s.UniqueNumber
                                       WHERE (s.itemnum = 7025730 OR s.itemnum = 7025740 OR s.itemnum = 7027145 OR s.itemnum = 7027320 OR s.itemnum = 7027495 OR s.itemnum = 7027670 OR s.itemnum = 7027845
                                                OR s.itemnum = 7028020 OR s.itemnum = 7028195 OR s.itemnum = 7028370 OR s.itemnum = 7028545 OR s.itemnum = 7028720 OR s.itemnum = 7910060 OR s.itemnum = 7911100
                                                OR s.itemnum = 7911110 OR s.itemnum = 7911120 OR s.itemnum = 7911130 OR s.itemnum = 7911140 OR s.itemnum = 7910070 OR s.itemnum = 7911150 OR s.itemnum = 7911160 OR s.itemnum = 7911170)
                                                GROUP BY e.TargetItemUniqueNumber
                                                HAVING COUNT(e.TargetItemUniqueNumber) <= 6) tme
            ON s.UniqueNumber = tme.TargetItemUniqueNumber
        
        -- 2. ��æƮ Ÿ�� �������� ���� ��æƮ ������ ��� ���� �Ѵ�.
        DELETE e 
        FROM td_enchant e
        WHERE e.TargetItemUniqueNumber NOT IN (SELECT UniqueNumber FROM td_store WITH(NOLOCK))

        -- 3. �Ʒ��� ItemNum �߿� ��æƮ�� ���� ������ ����
        DELETE td_store 
        FROM td_store s 
        WHERE (s.itemnum = 7025730 OR s.itemnum = 7025740 OR s.itemnum = 7027145 OR s.itemnum = 7027320 OR s.itemnum = 7027495 OR s.itemnum = 7027670 OR s.itemnum = 7027845
                OR s.itemnum = 7028020 OR s.itemnum = 7028195 OR s.itemnum = 7028370 OR s.itemnum = 7028545 OR s.itemnum = 7028720 OR s.itemnum = 7910060 OR s.itemnum = 7911100
                OR s.itemnum = 7911110 OR s.itemnum = 7911120 OR s.itemnum = 7911130 OR s.itemnum = 7911140 OR s.itemnum = 7910070 OR s.itemnum = 7911150 OR s.itemnum = 7911160 OR s.itemnum = 7911170)
                AND s.UniqueNumber NOT IN (SELECT TargetItemUniqueNumber FROM td_Enchant WITH(NOLOCK));
--
-----------------------------------------------------------------------------------------------------------------------