-- 2005-05-28 by cmkwon, ���� ���� ����� ��� ���� �ʱ�ȭ, ���ø����� �̵� ��Ŵ
-- 1. atum_db_[n] DB�� ���� ������� ���̺�(td_StatErrorCharacter)�� �����ؾ��ϹǷ� ����Ÿ�� �̾��� �־�� �Ѵ�.

-- ���� �ʱ�ȭ
-- b-gear
update td_character set
			AttackPart = 3, DefensePart = 3, FuelPart = 3, SoulPart = 3, ShieldPart = 3, DodgePart = 3,
			DP = 33, SP = 12, EP = 30,
			currentHP = HP, currentDP = DP, currentSP = SP, currentEP  = EP,
			Bonusstat = 2*(c.level-1), MapIndex = 1001, ChannelIndex = 0
From td_character c, td_StatErrorCharacter sec
where (sec.CharacterUID = c.uniquenumber and c.unitkind = 1)

-- i-gear
update td_character set
				AttackPart = 4, DefensePart = 2, FuelPart = 3, SoulPart = 3, ShieldPart = 2, DodgePart = 4,
				DP = 26, SP = 12, EP = 30,
				currentHP = HP, currentDP = DP, currentSP = SP, currentEP  = EP,
				Bonusstat = 2*(c.level-1), MapIndex = 1001, ChannelIndex = 0
From td_character c, td_StatErrorCharacter sec
where (sec.CharacterUID = c.uniquenumber and c.unitkind = 4096)

-- m-gear
update td_character set
				AttackPart = 2, DefensePart = 4, FuelPart = 4, SoulPart = 2, ShieldPart = 3, DodgePart = 3,
				DP = 33, SP = 8, EP = 40,
				currentHP = HP, currentDP = DP, currentSP = SP, currentEP  = EP,
				Bonusstat = 2*(c.level-1), MapIndex = 1001, ChannelIndex = 0
From td_character c, td_StatErrorCharacter sec
where (sec.CharacterUID = c.uniquenumber and c.unitkind = 16)

-- a-gear
update td_character set
				AttackPart = 4, DefensePart = 3, FuelPart = 4, SoulPart = 2, ShieldPart = 4, DodgePart = 1,
				DP = 40, SP = 8, EP = 40,
				currentHP = HP, currentDP = DP, currentSP = SP, currentEP  = EP,
				Bonusstat = 2*(c.level-1), MapIndex = 1001, ChannelIndex = 0
From td_character c, td_StatErrorCharacter sec
where (sec.CharacterUID = c.uniquenumber and c.unitkind = 256)
