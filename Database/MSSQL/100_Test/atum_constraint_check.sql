--  td_Character table
select * from td_Character where accountname not in (select accountname from td_Account)
select * from td_Character where AccountUniqueNumber not in (select AccountUniqueNumber from td_Account)
-- delete from td_Character where accountname not in (select accountname from td_Account)
-- delete from td_Character where AccountUniqueNumber not in (select AccountUniqueNumber from td_Account)

--  guild table
select * from td_guild where GuildCommanderUniqueNumber not in (select UniqueNumber from td_Character)

--  guildMember table
select * from td_guildMember where GuildUniqueNumber not in (select GuildUniqueNumber from td_Guild)
select * from td_guildMember where CharacterUniqueNumber not in (select UniqueNumber from td_Character)

-- monster table
select * from ti_monster where MonsterItem01 not in (select itemnum from ti_item) and MonsterItem01 != 0
select * from ti_monster where MonsterItem02 not in (select itemnum from ti_item) and MonsterItem02 != 0
select * from ti_monster where MonsterItem03 not in (select itemnum from ti_item) and MonsterItem03 != 0
select * from ti_monster where MonsterItem04 not in (select itemnum from ti_item) and MonsterItem04 != 0
select * from ti_monster where MonsterItem05 not in (select itemnum from ti_item) and MonsterItem05 != 0
select * from ti_monster where ControlSkill not in (select itemnum from ti_item) and ControlSkill != 0

-- store table
select * from td_store where AccountUniqueNumber not in (select AccountUniqueNumber from td_Account)
select * from td_store where Possess not in (select UniqueNumber from td_Character) and Possess != 0 order by AccountUniqueNumber, Possess
select * from td_store where ItemNum not in (select itemnum from ti_item) order by itemnum
-- select distinct itemnum from store where ItemNum not in (select itemnum from item) order by itemnum
-- delete from store where AccountUniqueNumber not in (select mem_idx from td_Account)
-- delete from store where Possess not in (select UniqueNumber from td_Character) and Possess != 0
-- delete from store where ItemNum not in (select itemnum from item)

-- storeSkill table
select * from td_storeSkill where AccountUniqueNumber not in (select AccountUniqueNumber from td_Account)
select * from td_storeSkill where Possess not in (select UniqueNumber from td_Character) and Possess != 0
select * from td_storeSkill where ItemNum not in (select itemnum from ti_item)
--delete from storeSkill where AccountUniqueNumber not in (select mem_idx from td_Account)
--delete from storeSkill where Possess not in (select UniqueNumber from td_Character) and Possess != 0
--delete from storeSkill where ItemNum not in (select itemnum from item)

-- monsterItem table
select * from ti_monsterItem where MonsterUniqueNumber not in (select UniqueNumber from ti_monster)
select * from ti_monsterItem where ItemNum not in (select ItemNum from ti_item)
-- delete from ti_monsterItem where MonsterUniqueNumber not in (select UniqueNumber from ti_monster)
-- delete from ti_monsterItem where ItemNum not in (select ItemNum from ti_item)

-- shop table
select * from ti_shop where ItemNum not in (select ItemNum from ti_item)
-- delete from ti_shop where ItemNum not in (select ItemNum from ti_item)

-- user_quest table
--select * from user_quest where QuestUniqueNumber not in (select UniqueNumber from quest)
--select * from user_quest where CharacterUniqueNumber not in (select UniqueNumber from td_Character)

-- 자기가 가지면 안 되는 아이템을 장전, 장착한 경우
select c.accountname, c.charactername, c.race, c.level, c.unitkind, s.itemnum, s.wear, i.itemname, i.kind, i.requnitkind
from td_store s, td_Character c, ti_item i
where s.possess = c.uniquenumber and i.itemnum = s.itemnum and (c.unitkind & i.requnitkind) = 0 and s.wear != 0
order by race desc, accountname

-- 창고에 countable item을 중복해서 가진 경우
select ss.*, a.accountname, '창고', i.itemname, so.uniquenumber, so.currentcount, so.createdtime
from td_account a, ti_item i,
	(select s.accountuniquenumber, s.itemnum, count(*) as cnt, sum(s.currentcount) as totalcount
	from td_store s
	where s.possess = 0
	group by s.accountuniquenumber, s.itemnum
	having count(*) >= 2) ss, td_store so
where ss.itemnum = i.itemnum and a.accountuniquenumber = ss.accountuniquenumber and dbo.atum_IsCountableItem(i.kind) = 1
		and so.accountuniquenumber = ss.accountuniquenumber and so.itemnum = ss.itemnum and so.possess = 0
order by cnt desc

-- 캐릭터가 countable item을 중복해서 가진 경우
select ss.*, c.accountname, c.charactername, i.itemname, so.uniquenumber, so.currentcount, so.createdtime
from td_character c, ti_item i,
	(select s.possess, s.itemnum, count(*) as cnt, sum(s.currentcount) as totalcount
	from td_store s
	where itemnum = 7000022 and possess != 0
	group by s.possess, s.itemnum
	having count(*) >= 2) ss, td_store so
where cnt >= 2 and ss.itemnum = i.itemnum and c.uniquenumber = ss.possess and dbo.atum_IsCountableItem(i.kind) = 1
		and so.itemnum = ss.itemnum and so.possess = ss.possess
order by cnt desc
