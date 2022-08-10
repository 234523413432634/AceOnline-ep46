-------------------------------------------------------------------------------
-- DB(atum2_db_account.atum.ti_Item)와 DB(atum2_db_account_test.atum.ti_Item)의 데이타 비교 쿼리

-- 1. atum2_db_account.atum.ti_Item테이블에는 존재하는데 atum2_db_account_test.atum.ti_Item테이블에는 업는 아이템 리스트
	SELECT i1.*
		FROM atum2_db_account.atum.ti_Item i1
		WHERE NOT EXISTS 
				(SELECT * FROM atum2_db_account_test.atum.ti_Item i2 WHERE i1.ItemNum = i2.ItemNum)

-- 2. atum2_db_account_test.atum.ti_Item테이블에는 존재하는데  atum2_db_account.atum.ti_Item테이블에는 업는 아이템 리스트
	SELECT i2.*
		FROM atum2_db_account_test.atum.ti_Item i2
		WHERE NOT EXISTS 
				(SELECT * FROM atum2_db_account.atum.ti_Item i1 WHERE i1.ItemNum = i2.ItemNum)

-- 3. atum2_db_account.atum.ti_Item테이블과 atum2_db_account_test.atum.ti_Item테이블의 데이타 비교
	SELECT i1.*
		FROM atum2_db_account.atum.ti_Item i1, atum2_db_account_test.atum.ti_Item i2
		WHERE i1.ItemNum = i2.ItemNum AND 
			(i1.Kind<>i2.Kind OR i1.ItemName<>i2.ItemName OR i1.AbilityMin<>i2.AbilityMin OR i1.AbilityMax<>i2.AbilityMax
				OR i1.ReqRace<>i2.ReqRace OR i1.ReqAttackPart<>i2.ReqAttackPart OR i1.ReqDefensePart<>i2.ReqDefensePart
				OR i1.ReqFuelPart<>i2.ReqFuelPart OR i1.ReqSoulPart<>i2.ReqSoulPart OR i1.ReqShieldPart<>i2.ReqShieldPart
				OR i1.ReqDodgePart<>i2.ReqDodgePart OR i1.ReqUnitKind<>i2.ReqUnitKind OR i1.ReqMinLevel<>i2.ReqMinLevel
				OR i1.ReqMaxLevel<>i2.ReqMaxLevel OR i1.ReqItemKind<>i2.ReqItemKind OR i1.Weight<>i2.Weight
				OR i1.HitRate<>i2.HitRate OR i1.Defense<>i2.Defense OR i1.FractionResistance<>i2.FractionResistance
				OR i1.NaturalFaction<>i2.NaturalFaction OR i1.SpeedPenalty<>i2.SpeedPenalty OR i1.Range<>i2.Range
				OR i1.[Position]<>i2.[Position] OR i1.Scarcity<>i1.Scarcity OR i1.Endurance<>i2.Endurance
				OR i1.AbrasionRate<>i2.AbrasionRate OR i1.Charging<>i2.Charging OR i1.Luck<>i2.Luck
				OR i1.MinTradeQuantity<>i2.MinTradeQuantity OR i1.Price<>i2.Price OR i1.CashPrice<>i2.CashPrice
				OR i1.DestParameter1<>i2.DestParameter1 OR i1.ParameterValue1<>i2.ParameterValue1
				OR i1.DestParameter2<>i2.DestParameter2 OR i1.ParameterValue2<>i2.ParameterValue2
				OR i1.DestParameter3<>i2.DestParameter3 OR i1.ParameterValue3<>i2.ParameterValue3
				OR i1.DestParameter4<>i2.DestParameter4 OR i1.ParameterValue4<>i2.ParameterValue4
				OR i1.ReAttacktime<>i2.ReAttacktime OR i1.[Time]<>i2.[Time] OR i1.RepeatTime<>i2.RepeatTime
				OR i1.Material<>i2.Material OR i1.ReqMaterial<>i2.ReqMaterial
				OR i1.RangeAngle<>i2.RangeAngle OR i1.UpgradeNum<>i2.UpgradeNum OR i1.LinkItem<>i2.LinkItem
				OR i1.MultiTarget<>i2.MultiTarget OR i1.ExplosionRange<>i2.ExplosionRange OR i1.ReactionRange<>i2.ReactionRange
				OR i1.ShotNum<>i2.ShotNum OR i1.MultiNum<>i2.MultiNum OR i1.AttackTime<>i2.AttackTime OR i1.ReqSP<>i2.ReqSP
				OR i1.SummonMonster<>i2.SummonMonster OR i1.NextSkill<>i2.NextSkill OR i1.SkillLevel<>i2.SkillLevel
				OR i1.SkillHitRate<>i2.SkillHitRate OR i1.SkillType<>i2.SkillType OR i1.SkillTargetType<>i2.SkillTargetType
				OR i1.Caliber<>i2.Caliber OR i1.OrbitType<>i2.OrbitType OR i1.ItemAttribute<>i2.ItemAttribute
				OR i1.BoosterAngle<>i2.BoosterAngle OR i1.CameraPattern<>i2.CameraPattern OR i1.Description<>i2.Description)
