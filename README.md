# AceOnline-ep46

Requirements
1.	Visual Studio 2022
2.	MFC for v143 build tools (x86 & x64)

Build once:
1.	AceOnline-ep46\Server\XmlRpc\XmlRpc.sln in "Release" configuration
2.	AceOnline-ep46\Server\ZipArchive\ZipArchive.sln in "Release STL MT" configuration
3.	AceOnline-ep46\Client\BaseClasses\baseclasses.sln in "Release" configuration

Build order:
1.	AceOnline-ep46\Server\GameServer\GameServer.sln in “R_Evo” configuration
2.	AceOnline-ep46\Server\GameServer\GameServer.sln in “R_Evo_ARENA” configuration for arena server
3.	AceOnline-ep46\Client\ProjectAtum.sln in “R_Evo” configuration
