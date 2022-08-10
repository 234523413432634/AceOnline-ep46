
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Le serveur n'est pas activé."
	#define STRERR_S_ATUMEXE_0002 "Socket fermé par le Pre Server!"
	#define STRERR_S_ATUMEXE_0003 "La mise à jour automatique a échoué.\r\nVeuillez réinstaller le jeu.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) reçu de %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Erreur inconnue : %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Impossible de joindre le serveur de téléchargement."
	#define STRERR_S_ATUMEXE_0007 "Taille des fichiers à télécharger inconnue."
	#define STRERR_S_ATUMEXE_0008 "Le fichier de mise à jour ne peut être téléchargé."
	#define STRERR_S_ATUMEXE_0009 "Le système ne dispose pas d'assez de mémoire ou de ressources."
	#define STRERR_S_ATUMEXE_0010 "Le fichier .exe est invalide."
	#define STRERR_S_ATUMEXE_0011 "Fichier introuvable."
	#define STRERR_S_ATUMEXE_0012 "Le dossier spécifié est introuvable."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Mise à jour terminée."
	#define STRMSG_S_ATUMLAUNCHER_0001 "Veuillez sélectionner un autre serveur."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Mise à jour de la liste des fichiers à effacer v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Effacer des fichiers temporaires."
	#define STRMSG_S_ATUMLAUNCHER_0004 "Mise à jour avertissement"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Mise à jour complète  (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Sélectionner le fichier d'exécution"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Sélectionner le fichier de chemin"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Téléchargement annulé"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Téléchargement terminé."
	#define STRMSG_S_ATUMLAUNCHER_0010 "Mise à jour à c%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Impossible de créer le fichier %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Mise à jour à v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Recevant information sur les fichiers %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Actualiser VTC Guard"				// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, º£³² X-Trap -> VTC °¡µå·Î º¯°æ

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Erreur] Erreur en comptant paramètre, Chiffre(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Erreur] Erreur Mutex\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Erreur] Erreur temps de transit, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Erreur] ID Erreur de décodage, ID décodé(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Impossible de connecter avec le serveur login."
	#define STRERR_S_ATUMLAUNCHER_0005 "La connexion au serveur a échoué."
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket fermé par le Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Attention-Erreur Fichier"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "La mise à jour automatique a échoué.\r\nVeuillez réinstaller le jeu.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "Tous les serveurs sont inactifs à l'heure actuelle."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s en cours d'examen..."
	#define STRERR_S_ATUMLAUNCHER_0012 "Tous les serveurs sont en cours de maintenance. Essayez de vous connecter plus tard."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERREUR %s(%#04X) reçu par %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "Vous avez mis un identifiant ou mot de passe invalide. Veuillez entrer un identifiant et mot de passe enregistré."
	#define STRERR_S_ATUMLAUNCHER_0015 "Erreur dans le processus de connexion"
	#define STRERR_S_ATUMLAUNCHER_0016 "ID non indiqué"
	#define STRERR_S_ATUMLAUNCHER_0017 "Double connexion"
	#define STRERR_S_ATUMLAUNCHER_0018 "Le serveur F ne fonctionne pas."
	#define STRERR_S_ATUMLAUNCHER_0019 "Le serveur I ne fonctionne pas."
	#define STRERR_S_ATUMLAUNCHER_0020 "Le service est arrêté temporairement.\n\n Essayez de vous connecter plus tard."
	#define STRERR_S_ATUMLAUNCHER_0021 "Il y a trop d'utilisateurs en ligne.\n\n Essayez de vous connecter plus tard."


	#define STRERR_S_ATUMLAUNCHER_0022 "Votre compte est actuellement bloqué.\ Durée : %s\n\nContactez www.airrivals.fr par mail pour de plus amples renseignements."
	#define STRERR_S_ATUMLAUNCHER_0023 "La version du client est incorrecte.\n\n Veuillez télécharger le jeu à nouveau."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERREUR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Impossible de se connecter au serveur de téléchargement."
	#define STRERR_S_ATUMLAUNCHER_0026 "La taille du fichier téléchargé(%s) est inconnue."
	#define STRERR_S_ATUMLAUNCHER_0027 "La taille du fichier téléchargé est inconnue."
	#define STRERR_S_ATUMLAUNCHER_0028 "Impossible de télécharger le fichier de mise à jour."
	#define STRERR_S_ATUMLAUNCHER_0029 "Le fichier mis à jour n'existe pas."
	#define STRERR_S_ATUMLAUNCHER_0030 "Le serveur sélectionné est en cours de maintenance. Essayez de vous connecter plus tard."
	#define STRERR_S_ATUMLAUNCHER_0031 "Le système ne dispose pas de suffisamment de mémoire ou de ressources."
	#define STRERR_S_ATUMLAUNCHER_0032 "Le fichier .exe est invalide."
	#define STRERR_S_ATUMLAUNCHER_0033 "Le fichier est introuvable."
	#define STRERR_S_ATUMLAUNCHER_0034 "Le dossier est introuvable."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, ÇöÀç ½´Â °ÔÀÓ ÁøÇàÀÌ º¡´ÉÇÙ.\n\nÇÑ »çÇ× ¿¡¿¶óÀÎ °¼¾ÅÎ ¹®Àø´Ù."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î


	#define STRMSG_S_050506		"\'%s\''s compte est bloqué pour le moment.\n Raison: %s\n	Durée: %s~%s\n\nVa sur http://support.airrivals.fr pour recevoir plus d'informations."
	#define STRMSG_S_050930		"Veuillez télécharger le jeu de nouveau.\nURL: %s\nVersion la plus récente :"
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Male"
//	#define STRMSG_S_SCADMINTOOL_0001 "Female"
//	#define STRMSG_S_SCADMINTOOL_0002 "A.D%d, Age%d"
//	#define STRMSG_S_SCADMINTOOL_0003 "Do you really want to modify your account information?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces attained, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''To ' + l.PeerCharacterName + ''', give ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''To ' + l.PeerCharacterName + ''', receive ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0008 "'''Discard ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces bought, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces sold, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' added ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' effacé ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Ajout ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Depôt ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Récupération ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'Temps du jeu \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', entier \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', Temps du jeu: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(N'existe pas)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Compte bloqué"
	#define STRMSG_S_SCADMINTOOL_0030 "Chat interdit"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s serveur"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s serveur,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Compte saisi"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Voulez-vous débloquer ce compte ?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dsecond)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d victoires %d défaites"
	#define STRMSG_S_SCADMINTOOL_0042 "Êtes-vous sur de vouloir déconnecter et bloquer le compte ?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s objet"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Notification : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Nombre d'utilisateurs : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Messages reçus : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] Nombre d'utilisateurs : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] État du domaine du serveur : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "La connexion au serveur a été perdue\nNom du Socket: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Impossible de charger les informations du compte correspondant."
	#define STRERR_S_SCADMINTOOL_0001 "La modification des informations du compte a échoué"
	#define STRERR_S_SCADMINTOOL_0002 "Entrez votre mot de passe"
	#define STRERR_S_SCADMINTOOL_0003 "L'authentification du mot de passe a échoué"
	#define STRERR_S_SCADMINTOOL_0004 "Entrez votre identifiant"
	#define STRERR_S_SCADMINTOOL_0005 "Le serveur n'est pas ouvert."
	#define STRERR_S_SCADMINTOOL_0006 "Impossible de se connecter au PreServer"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "ERREUR : le protocole correspondant n'existe pas."
	#define STRERR_S_SCADMINTOOL_0009 "Entrez votre identifiant"
	#define STRERR_S_SCADMINTOOL_0010 "Entrez la raison"
	#define STRERR_S_SCADMINTOOL_0011 "Erreur dans la configuration des points d'expérience : Niveau %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Nombre maximum de log dépassé.\r\n\r\nVeuillez modifier le nombre maximum de log ou la condition de recherche."
	#define STRERR_S_SCADMINTOOL_0013 "Impossible de se connecter à la base de données."
	#define STRERR_S_SCADMINTOOL_0014 "Non connecté"
	#define STRERR_S_SCADMINTOOL_0015 "Connecté"
	#define STRERR_S_SCADMINTOOL_0016 "Mise à jour"
	#define STRERR_S_SCADMINTOOL_0017 "Connecté"
	#define STRERR_S_SCADMINTOOL_0018 "Choix du personnage"
	#define STRERR_S_SCADMINTOOL_0019 "Joue !"
	#define STRERR_S_SCADMINTOOL_0020 "Inconnu"
	#define STRERR_S_SCADMINTOOL_0021 "La base de données %s(%s:%d)ne peut pas être connectée."
	#define STRERR_S_SCADMINTOOL_0022 "Ajout d'objet échoué"
	#define STRERR_S_SCADMINTOOL_0023 "La recherche du compte bloqué a échoué."
	#define STRERR_S_SCADMINTOOL_0024 "D'abord, se déconnecter du compte et le bloquer pour modifier."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(argent) ne peut pas être ajoutée."
	#define STRERR_S_SCADMINTOOL_0026 "L'objet sélectionné existe déjà, donc modifier le montant."
	#define STRERR_S_SCADMINTOOL_0027 "Erreur dans la recherche de l'objet"
	#define STRERR_S_SCADMINTOOL_0028 "SPI(argent) possédé par le personnage ne peut pas être effacée."
	#define STRERR_S_SCADMINTOOL_0029 "Voulez-vous effacer cet objet ?"
	#define STRERR_S_SCADMINTOOL_0030 "L'effacement de l'objet a échoué."
	#define STRERR_S_SCADMINTOOL_0031 "La modification de l'objet a échoué."
	#define STRERR_S_SCADMINTOOL_0032 "Aller sur le compte"
	#define STRERR_S_SCADMINTOOL_0033 "Le compte n'existe pas. (Le compte est peut-être bloqué)"
	#define STRERR_S_SCADMINTOOL_0034 "Le compte ou le personnage n'existe pas."
	#define STRERR_S_SCADMINTOOL_0035 "Erreur dans la recherche d'information du personnage"
	#define STRERR_S_SCADMINTOOL_0036 "Le personnage correspondant n'existe pas."
	#define STRERR_S_SCADMINTOOL_0037 "Erreur dans la mise à jour du personnage."
	#define STRERR_S_SCADMINTOOL_0038 "Les informations du personnage ont été mises à jour avec succès."
	#define STRERR_S_SCADMINTOOL_0039 "Choisissez un objet."
	#define STRERR_S_SCADMINTOOL_0040 "Choisissez le nombre d'objet."
	#define STRERR_S_SCADMINTOOL_0041 "Objet sélectionné peut être créé avec moins de 5 pièces."
	#define STRERR_S_SCADMINTOOL_0042 "Entrer le message."
	#define STRERR_S_SCADMINTOOL_0043 "L'avis ne peut pas être envoyé."
	#define STRERR_S_SCADMINTOOL_0044 "%s : état du serveur(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "Le serveur de MI n'est pas exécuté."
	#define STRERR_S_SCADMINTOOL_0046 "Le domaine du serveur ne fonctionne pas."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] État du serveur de MI : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ÆÊ - ¾îµå¹Î Åø ÆÊ ±¼­ »ç¿ëµÂ MSG
#define STRERR_S_SCADMINTOOL_0048 "Cette case est faite pour votre D.E.P. Vous pouvez la supprimer grâce à la commande \socket."
#define STRERR_S_SCADMINTOOL_0049 "L'enregistrement de la modification du D.E.P. a échoué (mais la modification a été effectuée)."
#define STRERR_S_SCADMINTOOL_0050 "Le chargement des informations sur le D.E.P. a échoué."
#define STRERR_S_SCADMINTOOL_0051 "La case équipée n'a pas pu être supprimée."
#define STRERR_S_SCADMINTOOL_0052 "L'utilisation du bonus caché sur les objets équipés a échoué."
#define STRERR_S_SCADMINTOOL_0053 "La modification de la case du D.E.P. a échoué."
#define STRERR_S_SCADMINTOOL_0054 "Les informations sur le D.E.P. n'ont pas pu être actualisées."
#define STRERR_S_SCADMINTOOL_0055 "Le chargement des informations sur le niveau du D.E.P. a échoué."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎæ¾ÆÀÌÅÛ°â´É
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ¿Åø±â´ÉÃ¡, ÀÎæ¾ÆÀÌÅÛ°â´É. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "Account name"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0002 "Conviction"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Start date"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Finish date"
//	#define STRMSG_S_SCAT_COLNAME_0005 "Handling person"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Handling reason"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Date"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Log type"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0011 "Character name"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Location"
//	#define STRMSG_S_SCAT_COLNAME_0013 "Contents"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Item"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "Own number"
//	#define STRMSG_S_SCAT_COLNAME_0017 "Name"
//	#define STRMSG_S_SCAT_COLNAME_0018 "Item number"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "Équipe"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Pas équipé"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Warehouse"
//	#define STRMSG_S_SCAT_COLNAME_0027 "Auction"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Map"
//	#define STRMSG_S_SCAT_COLNAME_0029 "Coordinate"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Sex"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Race"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Authority"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Unit kind"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Level"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Maximum level"
//	#define STRMSG_S_SCAT_COLNAME_0036 "Experience point"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Decreased experience point"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Auto stat division type"
//	#define STRMSG_S_SCAT_COLNAME_0039 "Attack"
//	#define STRMSG_S_SCAT_COLNAME_0040 "Defense"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Fuel"
//	#define STRMSG_S_SCAT_COLNAME_0042 "Spirit"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Shield"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Agility"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Attached regiment"
//	#define STRMSG_S_SCAT_COLNAME_0046 "Propensity"
//	#define STRMSG_S_SCAT_COLNAME_0047 "social position"
//	#define STRMSG_S_SCAT_COLNAME_0048 "Whole connection time"
//	#define STRMSG_S_SCAT_COLNAME_0049 "Generated time"
//	#define STRMSG_S_SCAT_COLNAME_0050 "Final log in time"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0052 "Whole"
	#define STRMSG_S_SCAT_COLNAME_0053 "Type automatique(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Type Vulcain (1-1 Type)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Type Duel (1-1 Type)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Type de Canon (1-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Type de Rifle (Type 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Gatling Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Type de lanceur (Type 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Type de commande de masse (Type 1-2)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Type de Roquettes (Type 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Type de Missile (Type 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Type de Paquet (Type 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Type de Mine (Type 2-1)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Type de bouclier (Type 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Type Factice (Type 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Type de Pixer (Type 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Type de Leurre (Type 2-2)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Type de Défense"
	#define STRMSG_S_SCAT_COLNAME_0070 "Type d'équipement de Soutien"
	#define STRMSG_S_SCAT_COLNAME_0071 "Type d'énergie"
	#define STRMSG_S_SCAT_COLNAME_0072 "Type de Metal"
	#define STRMSG_S_SCAT_COLNAME_0073 "Type de Carte"
	#define STRMSG_S_SCAT_COLNAME_0074 "Type d'enchantement"
	#define STRMSG_S_SCAT_COLNAME_0075 "Type de Réservoir"
	#define STRMSG_S_SCAT_COLNAME_0076 "Type de Munition"
	#define STRMSG_S_SCAT_COLNAME_0077 "Pour la Mission"
	#define STRMSG_S_SCAT_COLNAME_0078 "Type de Radar"
	#define STRMSG_S_SCAT_COLNAME_0079 "Type d'ordinateur"
	#define STRMSG_S_SCAT_COLNAME_0080 "Type de carte de jeu"
	#define STRMSG_S_SCAT_COLNAME_0081 "Type d'enchantement contre la destruction"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Type de Blaster"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Type de canon électrique"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "Whole item"
//	#define STRMSG_S_SCAT_COLNAME_0082 "Whole server"
//	#define STRMSG_S_SCAT_COLNAME_0083 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Server type"
//	#define STRMSG_S_SCAT_COLNAME_0085 "Server IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Present number of users"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Server condition"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Group server"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Field server"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Unknown"
//	#define STRMSG_S_SCAT_COLNAME_0091 "Not executed"
//	#define STRMSG_S_SCAT_COLNAME_0092 "Normal"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Abnormal"
	#define STRMSG_S_SCAT_COLNAME_0094 "Administrateur"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '°³, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Command list\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- List of backup account ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  Account: \'%s\', Original password: \'%s\', Temporary password: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  Account: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Please choose the folder where Versions for update are located"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "File has been succesfully created.\r\n\r\nDB information: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  active) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -inactive) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Servers data has been succesfully reloaded."
//	#define STRMSG_S_SCMONITOR_0011 "Service condition has been succesfully reflected."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  active)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -inactive)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "Free server service has been stopped."
//	#define STRMSG_S_SCMONITOR_0017 "Free server service started."
//	#define STRMSG_S_SCMONITOR_0018 "Field server is not executed"
//	#define STRMSG_S_SCMONITOR_0019 "Do you really want to close Field Server?"
//	#define STRMSG_S_SCMONITOR_0020 "Update version list information(Maximum 1492 Bytes)\r\n\r\n    Number of version list[%3d], Data capacity[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "Do you really want to close Pre Server?"
//	#define STRMSG_S_SCMONITOR_0022 "Do you really want to close IM Server?"
//	#define STRMSG_S_SCMONITOR_0023 "Do you really want to close NPC Server?"
//	#define STRMSG_S_SCMONITOR_0024 "%Yyear %mmonth %dday %Hhour %Mminute %Ssecond"
//	#define STRMSG_S_SCMONITOR_0025 "No event(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "Open beta attendance event(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "Do not know event(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "Set up time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0029 "Standard time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0030 "Occupying brigade"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> Command succesful.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> Command failed.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "Cannot connect to the DB."
//	#define STRERR_S_SCMONITOR_0003 "Corresponding Version do not exist"
//	#define STRERR_S_SCMONITOR_0004 "Please enter name of the folder that you want to compress"
//	#define STRERR_S_SCMONITOR_0005 "Please enter name of the folder that you want to output"
//	#define STRERR_S_SCMONITOR_0006 "Please enter start version"
//	#define STRERR_S_SCMONITOR_0007 "Please enter last version"
//	#define STRERR_S_SCMONITOR_0008 "Please choose the folder that you are going to output Zip file for update"
//	#define STRERR_S_SCMONITOR_0009 "Cannot connect file"
//	#define STRERR_S_SCMONITOR_0010 "Please choose the server!"
//	#define STRERR_S_SCMONITOR_0011 "Cannot connect to the DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "There is too many update version list.(Version list number[%3d], Data capacity[%4dBytes])\r\n\r\n    You must arrange version list."
//	#define STRERR_S_SCMONITOR_0014 "Eliminated function.\r\nPlease use management tool."
//	#define STRERR_S_SCMONITOR_0015 "This is not a city occupying map"
//	#define STRERR_S_SCMONITOR_0016 "Cannot make EDIT control."
//	#define STRERR_S_SCMONITOR_0017 "You have already registered existing file."

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Erreur] WndProc(), Connexion impossible avec le ServeurLog [%15s:%4d] Connectez-vous à nouveau\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Connecté au serveur de log.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "La connexion au serveur de log [%15s:%4d] a été perdue. Essayez de vous reconnecter.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Connexion au PreServer impossible[%15s:%4d] Se reconnecter\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Connecté au Pre Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) reçu de %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Erreur inconnue@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "La connexion au Pre Server[%15s:%4d]a été perdue. Tentative de reconnexion.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Connexion impossible avec le ServeurIM[%15s:%4d] Connectez-vous à nouveau\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Connecté au serveur de MI.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "La connexion au serveur de MI [%15s:%4d] a été perdue. Essayez de vous reconnecter.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) reçu de %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Erreur inconnue@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "Aucune requête DB dans le domaine de requêtes du serveur! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Objet sélectionné n'existe pas."
	#define STRMSG_S_F2DBQUERY_0002 "'%s' a posé sa candidature et a promis un objet."
	#define STRMSG_S_F2DBQUERY_0003 "a été donné. Appuyez sur F5 afin de consulter votre inventaire."
	#define STRMSG_S_F2DBQUERY_0004 "La compétence %s(%d) a été ajoutée."
	#define STRMSG_S_F2DBQUERY_0005 "L'objet sélectionné n'existe pas."
	#define STRMSG_S_F2DBQUERY_0006 "L'achat de l'objet a échoué."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "Début de la guerre d'occupation : %d(%10s) occGuildNom(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Brigade participante: GuildeUID(%4d) Guilde Nom(%10s) GuildeMaître(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "Guerre d'occupation de ville explosion de monstres :  %d(%10s) occGuildNom(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Dommage total ==> Nom de guilde(%10s) Dommage total(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "Guerre d'occupation de ville: %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildeID(%d) OccGuildeNom(%s) OccGuildeMaîtreUID(%d) Á¡·ÉÀü½Ã°£(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Erreur] SetCityWarState_ DBError, IndexCartes(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "Après %d minutes, \"%s\" va entrer dans la guerre d'occupation de ville."
	#define STRMSG_S_F2CITYWAR_0007 "Après %d minutes, \"%s\" la guerre d'occupation de ville sera terminée."
	#define STRMSG_S_F2CITYWAR_0008 "Monstre appelé au combat d'occupation de ville(%s) : occuper NPC."
	#define STRMSG_S_F2CITYWAR_0009 "Monstre appelé au combat d'occupation de ville(%s): %s brigade occupante"
	#define STRMSG_S_F2CITYWAR_0010 "Actuellement, \"NPC\" occupe \"%s\"."
	#define STRMSG_S_F2CITYWAR_0011 "Actuellement, brigade \"%s\" occupe \"%s\"."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Échec du chargement de la mission"
	#define STRMSG_S_F2QUEST_0001 "La mission n'a pas été chargée.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Serveur de test a été fermé! \r\n\r\nLoadFieldServerDataDebug() doit être terminé."
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "Fureur de monstres %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "Type 1"
	#define STRMSG_S_F2NOTIFY_0003 "Type 2"
	#define STRMSG_S_F2NOTIFY_0004 "Mon 1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Type d'arme incorrect ! Veuillez contacter l'administrateur !"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Probabilité d'attaque a été réduite de %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s échoué, Probabilité(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s échoué, Probabilité(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s échoué, Probabilité(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Dommage réduit de %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, donne%5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, reçoit %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, PV:%5.2f), donne %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, reçoit %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Échec de l'essai : Probabilité insuffisante > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Essai restant[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "L'information \"Balle\" n'existe pas. Veuillez envoyer une demande à l'administrateur."
	#define STRMSG_S_F2NOTIFY_0019 "Des informations sur les calibres de balles n'existent pas. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "C'est l'information sur les balles.  %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Il est impossible de se téléporter pendant le tournoi."
	#define STRMSG_S_F2NOTIFY_0022 "Vous ne pouvez pas vous téléporter lorsque vous êtes mort."
	#define STRMSG_S_F2NOTIFY_0023 "Impossible de vous téléporter pendant un combat en formation."
	#define STRMSG_S_F2NOTIFY_0024 "Erreur lors de la production des cartes ! Veuillez envoyer une demande à l'administrateur."
	#define STRMSG_S_F2NOTIFY_0025 "Erreur lors de la production des cartes ! Veuillez envoyer une demande à l'administrateur. Chez %d, %d l'index de l'objectif du téléportation n'existe pas!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Téléportation impossible, le combat en formation n'est pas terminé."
	#define STRMSG_S_F2NOTIFY_0027 "Téléportation(%04d) Correction impossible de Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Caractère %10s, subit dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Caractère %10s, cause du dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Personnage %10s, subit du dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Personnage %10s, cause du dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Personnage %10s, subit un dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Personnage %10s, cause un dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Monstre %3d, cause un dommage %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Personnage %10s, cause un dommage de %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Personnage %10s, cause  %5.2f de dommages"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Monstre %3d, subit  %5.2f de dommages"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> Personnage %10s, cause du dommage %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> Le personnage %10s, donne %5.2f de dommages factices"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> Le monstre %10s, donne %5.2f de dommages"
	#define STRMSG_S_F2NOTIFY_0041 "L'initialisation des statistiques a été réalisée avec succès."
	#define STRMSG_S_F2NOTIFY_0042 "Impossible de l'utiliser si vous êtes mort"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO n'existe pas"
	#define STRMSG_S_F2NOTIFY_0044 "Mise à jour \g réussie \g."
	#define STRMSG_S_F2NOTIFY_0045 "\r Echec \r de l'amélioration."
	#define STRMSG_S_F2NOTIFY_0046 "N'appartient pas à la brigade."
	#define STRMSG_S_F2NOTIFY_0047 "Déjà en attente de la requête."
	#define STRMSG_S_F2NOTIFY_0048 "Veuillez réessayer plus tard."
	#define STRMSG_S_F2NOTIFY_0049 "Vous ou l'autre personne êtes le chef de la brigade."
	#define STRMSG_S_F2NOTIFY_0050 "Déjà dans la brigade de combat."
	#define STRMSG_S_F2NOTIFY_0051 "Les deux chefs de la brigade ne sont pas sur le même carte."
	#define STRMSG_S_F2NOTIFY_0052 "Tous les membres de la brigade ne sont pas sur la même carte"
	#define STRMSG_S_F2NOTIFY_0053 "Tous les membres de la formation ne sont pas sur la même carte"
	#define STRMSG_S_F2NOTIFY_0054 "Vous ne faites pas partie de la brigade."
	#define STRMSG_S_F2NOTIFY_0055 "Le demandeur est différent."
	#define STRMSG_S_F2NOTIFY_0056 "Vous ou l'autre personne n'êtes pas chef de brigade."
	#define STRMSG_S_F2NOTIFY_0057 "Deux chefs de brigades n'existent pas sur la même carte."
	#define STRMSG_S_F2NOTIFY_0058 "Vous ne faites pas partie de la brigade."
	#define STRMSG_S_F2NOTIFY_0059 "Le demandeur est différent."
	#define STRMSG_S_F2NOTIFY_0060 "Vous ou l'autre personne n'êtes pas un chef de brigade."
	#define STRMSG_S_F2NOTIFY_0061 "La bataille défensive de la ville sous occupation est un succès."
	#define STRMSG_S_F2NOTIFY_0062 "Erreur dans la configuration de la mission - Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0063 "L'objet correspondant(%s) ne peut pas être installé à cet endroit"
	#define STRMSG_S_F2NOTIFY_0064 "Le moteur ne peut pas être libéré."
	#define STRMSG_S_F2NOTIFY_0065 "Mouvement de l'objet : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Mouvement de l'objet incorrect : (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENEMENT (%d) impossible de prendre en charge le processus_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Information sur la carte des évènements anormale! Veuillez contacter l'administrateur!"
	#define STRMSG_S_F2NOTIFY_0069 "La cible correspondante n'existe pas"
	#define STRMSG_S_F2NOTIFY_0070 "Erreur dans l'achat d'objet. Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0071 "Le niveau de compétence que vous souhaitez acheter est inférieur ou égal à votre niveau actuel."
	#define STRMSG_S_F2NOTIFY_0072 "Erreur d'objet. L'objet requiert une compétence d'achat."
	#define STRMSG_S_F2NOTIFY_0073 "Erreur dans la vente d'objet. Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0074 "Erreur dans l'achat d'objet. Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0075 "\'L'objet Crédit\'a été acheté."
	#define STRMSG_S_F2NOTIFY_0076 "Liste des achats : \'%s(%dpieces)\'"
	#define STRMSG_S_F2NOTIFY_0077 "A déjà rejoint la partie"
	#define STRMSG_S_F2NOTIFY_0078 "Impossible de rejoindre si vous êtes le chef de la partie"
	#define STRMSG_S_F2NOTIFY_0079 "Impossible de rejoindre si la bataille de la formation est en cours."
	#define STRMSG_S_F2NOTIFY_0080 "Évoquer toutes les informations du personnel de formation n'est pas pris en charge !"
	#define STRMSG_S_F2NOTIFY_0081 "Information de la carte d'évènement anormale! Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0082 "Ce compte ne peut pas faire de transaction"
	#define STRMSG_S_F2NOTIFY_0083 "%s's chargement dépassé."
	#define STRMSG_S_F2NOTIFY_0084 "Coordination des mouvements possibles : (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "Utilisateur :"
	#define STRMSG_S_F2NOTIFY_0086 "20 personnes maximum peuvent être vues."
	#define STRMSG_S_F2NOTIFY_0087 "L'utilisateur correspondant (%s) n'existe pas"
	#define STRMSG_S_F2NOTIFY_0088 "Ne fait pas parti du parti"
	#define STRMSG_S_F2NOTIFY_0089 "Heure actuelle : %d:%d, Heure d'Artum : %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Changement d'heure : %d:%d, heure d'Artum : %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Non connecté au serveur NPC"
	#define STRMSG_S_F2NOTIFY_0092 "L'objet correspondant(%d) n'existe pas"
	#define STRMSG_S_F2NOTIFY_0093 "Limité à 10 pièces si ce n'est pas un objet comptable"
	#define STRMSG_S_F2NOTIFY_0094 "Nombre total de personne connectée à la carte \'%s\' : %dpersonnes"
	#define STRMSG_S_F2NOTIFY_0095 "Nombre de connexions simultanées à la carte %s %s : %d personnes -  '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Nombre de connexions simultanées à la carte %s %s : %d personnes - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Canal de carte actuel : %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Les informations de munitions n'existe pas. Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0099 "Les informations sur le calibre des munitions n'existent pas. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Les informations sur les munitions n'existent pas. Veuillez contacter l'administrateur."
	#define STRMSG_S_F2NOTIFY_0101 "Les informations sur le calibre des munitions n'existe pas. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "L'utilisateur correspondant (%s) n'existe pas"
	#define STRMSG_S_F2NOTIFY_0103 "L'utilisateur correspondant (%s) est mort"
	#define STRMSG_S_F2NOTIFY_0104 "Les utilisateurs correspondants (%s) n'existent pas"
	#define STRMSG_S_F2NOTIFY_0105 "Configuré comme compte standard"
	#define STRMSG_S_F2NOTIFY_0106 "Le compte standard a été annulé"
	#define STRMSG_S_F2NOTIFY_0107 "L'invincibilité a été activée."
	#define STRMSG_S_F2NOTIFY_0108 "L'invincibilité a été désactivée."
	#define STRMSG_S_F2NOTIFY_0109 "Les dommages par armes seront modifiés par %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Sera initialisé lors du rechargement de l'objet"
	#define STRMSG_S_F2NOTIFY_0111 "Sera initialisé lors du rechargement de l'objet"
	#define STRMSG_S_F2NOTIFY_0112 "L'utilisateur correspondant (%s) n'existe pas"
	#define STRMSG_S_F2NOTIFY_0113 "Invisibilité a été désactivée"
	#define STRMSG_S_F2NOTIFY_0114 "Invisibilité a été activée"
	#define STRMSG_S_F2NOTIFY_0115 "L'évènement %s n'est pas en cours"
	#define STRMSG_S_F2NOTIFY_0116 "L'évènement %s a démarré (grossissement : %4.2f, Durée de l'évènement:%3d minutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Configuré en tant que compte premium standard"
	#define STRMSG_S_F2NOTIFY_0118 "Échec de configuration en compte premium"
	#define STRMSG_S_F2NOTIFY_0119 "Configuré en tant que Super Compte premium"
	#define STRMSG_S_F2NOTIFY_0120 "Ceci n'est pas la carte de la bataille de la ville sous occupation"
	#define STRMSG_S_F2NOTIFY_0121 "La bataille de la ville sous occupation ne peut pas démarrer"
	#define STRMSG_S_F2NOTIFY_0122 "La bataille de la ville sous occupation ne peut pas se terminer"
	#define STRMSG_S_F2NOTIFY_0123 "Mode Furtif a été initialisé"
	#define STRMSG_S_F2NOTIFY_0124 "En mode furtif"
	#define STRMSG_S_F2NOTIFY_0125 "La carte n'est pas validée"
	#define STRMSG_S_F2NOTIFY_0126 "Configuration de l'Happy Hour [temps écoulé :%4dminute)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy Hour terminé"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> Reçu du monstre %3d, %5.2f de dommage"
	#define STRMSG_S_F2NOTIFY_0129 "Type 1 -> Dommages reçus du monstre %3d, %5.2f(factice)"
	#define STRMSG_S_F2NOTIFY_0130 "Connecté avec les droits de \r %s\r"
	#define STRMSG_S_F2NOTIFY_0131 "Ne pas remplir pendant l'accomplissement de la routine %s : CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Échec de la suppression du parti personnel! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Arrêté!"
	#define STRMSG_S_F2NOTIFY_0136 "ERREUR FATALE: Veuillez contacter l'administrateur! Erreur dans l'attribution des variables de magasin!"
	#define STRMSG_S_F2NOTIFY_0137 "%s est effacé."
	#define STRMSG_S_F2NOTIFY_0138 "Le canal que vous êtes en train d'utiliser est désactivé donc les monstres et autres fonctions ne sont pas disponibles."
	#define STRMSG_S_F2NOTIFY_0139 "Arrêté. Veuillez utiliser un autre canal."
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Durée du mouvement %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "Récupération automatique de PV arrêté."
	#define STRMSG_S_F2NOTIFY_0143 "La récupération automatique de PV s'est arrêtée puisqu'il ne s'agit pas d'un emplacement possible pour l'atterrissage"
	#define STRMSG_S_F2NOTIFY_0144 "Récupération d'urgence de PV 5.2f"
	#define STRMSG_S_F2NOTIFY_0145 "PV UP graduelle arrêtée (temps restant : %d)"
	#define STRMSG_S_F2NOTIFY_0146 "DP UP graduelle arrêtée (temps restant : %d)"
	#define STRMSG_S_F2NOTIFY_0147 "EP UP graduelle arrêtée (temps restant : %d)"
	#define STRMSG_S_F2NOTIFY_0148 "L'évènement %s a été arrêté."
	#define STRMSG_S_F2NOTIFY_0149 "L'évènement %s est en cours (grossissement %4.2f, restant : %3dminute)"
	#define STRMSG_S_F2NOTIFY_0150 "La commande n'a pas été exécutée"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Erreur en divisant les points d'expérience. (%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Erreur Notification de départ de jeu non valide ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Erreur Notification de départ de jeu non valide ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "Correction de téléportation(%04d) impossible comme RésultatProcessusQuest(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Information-Carte-Événement anormale. Veuillez demander l'administrateur. \rCurrent(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "Evénement(%d) Correction impossible à T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Information-Carte-Evénement anormale. Veuillez contacter l'administrateur!\rCurrent(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "Correction de téléportation impossible afin de T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "Evénement (%d) Correction impossible à (party leader) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "Correction de téléportage (%04d) impossible à Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "Evénement (%d) Correction impossible à Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "Correction de téléportage impossible à  T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Téléportation a échoué: %s -> Distance: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "Téléportation(%04d) Correction impossible à i Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> Clique sur le bouton interféré OK!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "La quête n'a pas été chargée.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "Téléportation(%s) Correction impossible par HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "Téléportation(%s) Correction impossible par HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "ERREUR FATALE : Ce message ne doit pas être envoyé au serveur auquel les membres n'appartiennent pas. Essaie.\r\n"
	#define STRERR_S_F2NOTIFY_0019 "Téléportation(%04d) Correction impossible à T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "Téléportation(%s) Correction impossible à T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Points d'expérience"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Récupération des points d'expérience."
	#define STRMSG_S_F2EVENTTYPE_0003 "Chute d'objet"
	#define STRMSG_S_F2EVENTTYPE_0004 "Chute d'objet rare"
	#define STRMSG_S_F2EVENTTYPE_0005 "Événement inconnu"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Connecté au Pre Server. \n"
	#define STRMSG_S_I2PRECONNECT_0001 "La connexion au Pre Server [%15s:%4d]a été perdue. En attente de reconnexion.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' existe déjà"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' est déjà dans une brigade"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' est déjà le nom d'une brigade existente"
	#define STRMSG_S_I2NOTIFY_0003 "Échec du chargement de la brigade - Veuillez contacter l'administrateur!"
	#define STRMSG_S_I2NOTIFY_0004 "Votre ami '%s' s\"est connecté"
	#define STRMSG_S_I2NOTIFY_0005 "Vérification de la formation précédente"
	#define STRMSG_S_I2NOTIFY_0006 "La formation précédente n'existe pas"
	#define STRMSG_S_I2NOTIFY_0007 "Rejoint la formation"
	#define STRMSG_S_I2NOTIFY_0008 "Vous êtes actuellement dans une formation"
	#define STRMSG_S_I2NOTIFY_0009 "Erreur fatale : Erreur fatale du parti! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "L'état de la formation personnelle est invalide"
	#define STRMSG_S_I2NOTIFY_0011 "Le personnel de formation a déjà rejoint la brigade"
	#define STRMSG_S_I2NOTIFY_0012 "Cette personne a déjà rejoint la brigade"
	#define STRMSG_S_I2NOTIFY_0013 "Vous ne pouvez pas vous inviter vous-même"
	#define STRMSG_S_I2NOTIFY_0014 "Vous êtes dans un état qui ne permet pas de rejoindre une brigade"
	#define STRMSG_S_I2NOTIFY_0015 "Vous avez dépassé le nombre de brigade personnelle que vous pouvez rejoindre"
	#define STRMSG_S_I2NOTIFY_0016 "Vous êtes dans un état qui ne vous permet pas de rejoindre une brigade"
	#define STRMSG_S_I2NOTIFY_0017 "Le chef de la brigade ne peut pas se retirer de la brigade"
	#define STRMSG_S_I2NOTIFY_0018 "Vous ne pouvez pas vous retirer de la brigade tant que vous êtes dans un combat de brigade"
	#define STRMSG_S_I2NOTIFY_0019 "Vous ne pouvez pas expulser le personnel de la brigade quand vous êtes en combat de brigade."
	#define STRMSG_S_I2NOTIFY_0020 "Le chef de la brigade ne peut pas être expulsé"
	#define STRMSG_S_I2NOTIFY_0021 "Vous ne pouvez pas disperser la brigade tant que vous êtes en combat de brigade"
	#define STRMSG_S_I2NOTIFY_0022 "Vous ne pouvez pas changer pour le même nom"
	#define STRMSG_S_I2NOTIFY_0023 "Vous êtes dans un état qui ne permet pas le changement de nom"
	#define STRMSG_S_I2NOTIFY_0024 "Vous êtes dans un état qui ne permet pas le changement de médaille de brigade"
	#define STRMSG_S_I2NOTIFY_0025 "Vous êtes dans un état qui ne permet pas le changement de rang"
	#define STRMSG_S_I2NOTIFY_0026 "Recoupement de grade"
	#define STRMSG_S_I2NOTIFY_0027 "Le changement de rang en chef de régiment est impossible"
	#define STRMSG_S_I2NOTIFY_0028 "Le changement en rang de chef de régiment n'est pas possible"
	#define STRMSG_S_I2NOTIFY_0029 "Nombre total d'utilisateurs : %d personnes (jusqu'à %d personnes)"
	#define STRMSG_S_I2NOTIFY_0030 "Ajouter à la liste des messages des administrateurs"
	#define STRMSG_S_I2NOTIFY_0031 "Supprimer de la liste des messages des administrateurs"
	#define STRMSG_S_I2NOTIFY_0032 "IP du serveur : %s"
	#define STRMSG_S_I2NOTIFY_0033 "Groupe du serveur \'%s\' nombre total de personnes connectées : %d personnes"
	#define STRMSG_S_I2NOTIFY_0034 "Voulez-vous vraiment fermer le serveur(%s)? ID du serveur : %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' ne joue pas au jeu"
	#define STRMSG_S_I2NOTIFY_0036 "Nombre total d'utilisateurs : %d personnes (production jusqu'à %d personnes)"
	#define STRMSG_S_I2NOTIFY_0037 "/envoi %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Le régiment correspondant n'existe pas."
	#define STRMSG_S_I2NOTIFY_0039 "Chuchoter a été désactivé"
	#define STRMSG_S_I2NOTIFY_0040 "Le chuchotement a été désactivé"
	#define STRMSG_S_I2NOTIFY_0041 "N'a pas joint la brigade"
	#define STRMSG_S_I2NOTIFY_0042 "La brigade (%d) n'est pas disponible"
	#define STRMSG_S_I2NOTIFY_0043 "Le temps correspondant (%s) n'existe pas"
	#define STRMSG_S_I2NOTIFY_0044 "Le domaine du serveur n'est pas valide"
	#define STRMSG_S_I2NOTIFY_0045 "La carte correspondante (%s) n'existe pas"
	#define STRMSG_S_I2NOTIFY_0046 "Vous ne pouvez pas chatter pendant %d minutes!"
	#define STRMSG_S_I2NOTIFY_0047 "Ban pour le dialogue en ligne : '%10s', %3d min"
	#define STRMSG_S_I2NOTIFY_0048 "Le ban pour le dialogue en ligne est terminé."
	#define STRMSG_S_I2NOTIFY_0049 "Ban chat annulé : '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (compte ; %s, carte: %d(%d), niveau: %d) EN JEU"
	#define STRMSG_S_I2NOTIFY_0051 "Vous ne pouvez pas vous convoquer vous-même."
	#define STRMSG_S_I2NOTIFY_0052 "La brigade correspondante n'existe pas."

	#define STRMSG_S_IMSERVER_050607_0001	"La carte correspondante n'existe pas."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Connecté au domaine du serveur.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "La connexion au domaine du serveur[%15s:%4d] a été perdue. En attente de reconnexion.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Le contrôle de collision entre le monstre et l'objet n'existe pas\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "Le monstre de la bataille de la ville occupée (%10s) est appelé\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Connecté avec %s compte (%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Succès"
	#define STRMSG_S_P2PRENOTIFY_0002 "Echec"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERREUR] Erreur dans l'ajout d'information sur le compte, Nom du compte(%s) IP Privée(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Bonjour! Ceci est l'administrateur d'AirRivals."
	#define STRMSG_SCAT_051115_0002		"Nous allons effectuer nos travaux réguliers d'entretien dans 10 minutes."
	#define STRMSG_SCAT_051115_0003		"Merci de vous rendre à un endroit sûr et de quitter le jeu."
	#define STRMSG_SCAT_051115_0004		"Tout d'abord, le serveur NPS sera fermé."
	#define STRMSG_SCAT_051115_0005		"Les travaux réguliers d'entretien d'AirRivals commencent."
	#define STRMSG_SCAT_051115_0006		"Profitez de votre journée avec AirRivals."
	#define STRMSG_SCAT_051115_0007		"Dans environ 5 minutes il y aura un check-up du serveur." // 5     .
	#define STRMSG_SCAT_051115_0008		"Serveur sera hors ligne pendant 60 minutes."	//  60   
	#define STRMSG_SCAT_051115_0009		"Maintenance du serveur dans 30 minutes."
	#define STRMSG_SCAT_051115_0010		"Maintenance du serveur dans 15 minutes."
	#define STRMSG_SCAT_051115_0011		"Maintenance du serveur dans 10 minutes."
	#define STRMSG_SCAT_051115_0012		"Maintenance du serveur dans 5 minutes."
	#define STRMSG_SCAT_051115_0013		"Maintenance du serveur imminente."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Mode Invisible : Les joueurs ne peuvent pas vous voir et les armes ne peuvent pas être utilisées."
	#define STRMSG_060509_0001			"Statut d'invincibilité : Vous ne recevrez aucun dommage."
	#define STRMSG_060509_0002			"Mode furtif : Les monstres ne vous attaqueront pas en premier."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Votre requête a été envoyée à un GM. L'un de nos GM vous contactera dès que possible."
	#define	STRMSG_060526_0001			"Vous étiez dans l'incapacité de mettre à jour automatiquement.\r\n\r\nVeuillez télécharger le patch à partir de la page d'accueil(%s) et vous reconnecter.\r\n\r\n     Erreur : %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"L'identifiant n'a pas été enregistré ou l'identifiant et le mot de passe ne correspondent pas."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"Le serveur de jeu est actuellement déconnecté pour maintenance. Veuillez consulter la page d'accueil (www.airrivals.fr) pour de plus amples informations."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"La version du client n'est pas valide.\r\n	Veuillez réinstaller ou télécharger le patch."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"Vous avez été abattu par %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"L'initialisation du serveur Jamboree DB(atum2_db_20) doit être effectuée après le serveur Jamboree a été fermé."
	#define STRMSG_070410_0001   	"Voulez-vous vraiment initialiser le serveur de base de données jamboree(atum2_db_20)- [Code de validation:%d]"
	#define STRMSG_070410_0002   	"Le serveur de base de données Jamboree(atum2_db_20) est initialisé."
	#define STRMSG_070410_0003   	"L'initialisation du serveur de base de données Jamboree(atum2_db_20) a échoué !!"
	#define STRMSG_070410_0004   	"'%s' la duplication des données vers le serveur de base de données Jamboree(atum2_db_20) est terminée."
	#define STRMSG_070410_0005   	"'%s' la duplication des données vers le serveur de base de données Jamboree(atum2_db_20) a échoué - le personnage n'existe pas!"
	#define STRMSG_070410_0006   	"'%s' la duplication des données vers le serveur de base de données(atum2_db_20) a échoué - Le compte du personnage correspondant existe!"
	#define STRMSG_070410_0007   	"'%s' la duplication des données vers le serveur de base de données Jamboree(atum2_db_20) a échoué. Echec d'ajout!"
	#define STRMSG_070410_0008   	"'%s' la duplication des données vers le serveur de base de données(atum2_db_20) a échoué - Inconnu (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
	//#define STRMSG_WINDOW_DEGREE_800x600_LOW			"800x600 (low)"
	//#define STRMSG_WINDOW_DEGREE_800x600_MEDIUM			"800x600 (medium)"
	//#define STRMSG_WINDOW_DEGREE_800x600_HIGH			"800x600 (high)"
#define STRMSG_WINDOW_DEGREE_1024x768_LOW			"1024x768 (basse)"
#define STRMSG_WINDOW_DEGREE_1024x768_MEDIUM		"1024x768 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1024x768_HIGH			"1024x768 (haute)"
#define STRMSG_WINDOW_DEGREE_W1280x800_LOW			"1280x800 (basse-large)"
#define STRMSG_WINDOW_DEGREE_W1280x800_MEDIUM		"1280x800 (moyenne-large)"
#define STRMSG_WINDOW_DEGREE_W1280x800_HIGH			"1280x800 (haute-large)"
#define STRMSG_WINDOW_DEGREE_1280x960_LOW			"1280x960 (basse)"
#define STRMSG_WINDOW_DEGREE_1280x960_MEDIUM		"1280x960 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1280x960_HIGH			"1280x960 (haute)"
#define STRMSG_WINDOW_DEGREE_1280x1024_LOW			"1280x1024 (basse)"
#define STRMSG_WINDOW_DEGREE_1280x1024_MEDIUM		"1280x1024 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1280x1024_HIGH			"1280x1024 (haute)"
#define STRMSG_WINDOW_DEGREE_W1600x900_LOW			"1600x900 (basse-large)"
#define STRMSG_WINDOW_DEGREE_W1600x900_MEDIUM		"1600x900 (moyenne-large)"
#define STRMSG_WINDOW_DEGREE_W1600x900_HIGH			"1600x900 (haute-large)"
#define STRMSG_WINDOW_DEGREE_1600x1200_LOW			"1600x1200 (basse)"
#define STRMSG_WINDOW_DEGREE_1600x1200_MEDIUM		"1600x1200 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1600x1200_HIGH			"1600x1200 (haute)"

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Impossible de démarrer puisque vous n'êtes pas en mode furtif."
#define STRMSG_070615_0001		"Impossible de démarrer la montre."
#define STRMSG_070620_0000	"L'utilisateur ne peut pas démarrer la montre."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"Point de Guerre"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"Vous avez joué au jeu pendant %d heure(s)."
#define STRMSG_070628_0001				"Vous avez joué au jeu pendant %d heure(s). Veuillez faire le nécessaire pour prendre un peu de repos."
#define STRMSG_070628_0002				"Vous avez joué trop longtemps. Cela devient dangereux pour votre santé. Prenez soin de votre santé et fermez le jeu. Cela est dans votre propre intérêt."
#define STRMSG_070628_0003				"Jouer à ce jeu plus longtemps serait critique pour votre santé. Prenez soin de votre santé en fermant le jeu dès maintenant. Dans le cas contraire, cela aura un impact sur votre santé et vos recettes de jeu atteindront 0%. Vos recettes de jeu reviendront à la normal 5 heures après la fermeture du jeu."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s'\ n'est pas interdit en entrant dans l'arène."
#define STRMSG_070711_0001 "\'%s'\ a l'interdiction de rentrer dans l'arène (temps restant : %d minutes)"
#define STRMSG_070711_0002 "Vous avez l'interdiction d'entrer dans l'arène pendant %d minutes!"
#define STRMSG_070711_0003 "Votre interdiction d'entrer dans l'arène est terminée."
#define STRMSG_070711_0004 "L'utilisation de l'arène est interdite pendant \'%s'\."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (basse-large)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (moyenne-large)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (haute-large)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "Cette commande ne peut être utilisée qu'après que la nation ait été choisie."
#define STRMSG_070830_0002                                   "Le plan de la salle de conférence(%d) de la nation correspondante n'est pas disponible."
#define STRMSG_070830_0003                                   "Nombre d'utilisateurs pouvant entrer en salle de conférence : %d"
#define STRMSG_070830_0004                                   "'%s' a déjà été ajouté à la liste d'entrée."
#define STRMSG_070830_0005                                   "'%s' n'a pas la permission d'entrer."
#define STRMSG_070830_0006                                   "'%s' n'est pas un personnage valide."
#define STRMSG_070830_0007                                 "'%s' ne peut pas être ajouté à la liste d'entrée de la salle de conférence. (Maximum %d personnes)"
#define STRMSG_070830_0008                                   "'%s' est autorisé à entrer en salle de conférence."
#define STRMSG_070830_0009                                   "La permission d'entrer en salle de conférence a été donnée."
#define STRMSG_070830_0010                                   "La permission d'entrer en salle de conférence a été annulée."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s vous a envoyé %s en cadeau."
#define STRMSG_071115_0002									"Liste actuelle : \'%s(%d pièce)\'"
#define STRMSG_071115_0003									"\\y%s send a present to %s.  Present is  %s. Please check the warehouse."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Le système d'appel n'est pas en fonction. Veuillez utiliser le service client : http://support.airrivals.fr/"
#define STRMSG_071120_0002									"Le système d'appel est activé."
#define STRMSG_071120_0003									"Le système d'appel n'est pas contenu."
#define STRMSG_071120_0004									"Le système d'appel commencera du %s au %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s vous a envoyé %s(%d) en cadeau. Veuillez vérifier votre entrepôt."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Le réglage de résolution n'est pas valable. Veuillez le vérifiez de nouveau."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'Erreur dans %s' bloc de réglage. Code d'erreur (%d)"
#define STRMSG_080201_0002									"Le compte de '%s' a été bloqué. [Date de fin de bloquage : %s]"
#define STRMSG_080201_0003									"Le compte de '%s' n'existe pas dans la liste des blocages. Code d'erreur(%d)"
#define STRMSG_080201_0004									"'En bloquant le compte de %s une erreur s'est produite' Errorcode(%d)"
#define STRMSG_080201_0005									"Le compte de '%s' a été effacé de la liste de rejet." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (basse-large)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (moyenne-large)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (haute-large)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Erreur] WndProc(), Impossible de se connecter à ArenaServer[%15s:%4d] Se reconnecter\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Connecté à ArenaServer.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "La connexion à ArenaServer[%15s:%4d] est fermée. Essai de reconnexion.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) reçue de %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Erreur inconnue@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "La salle d'attente No. \\y%d a reçu l'attribut événement.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "L'attribut événement a été enlevé de la \\ySalle d'attente de l'arène%d .\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y En distribuant l'attribut de l'arène une erreur s'est produite.\r\n"
#define STRMSG_080428_0001					"%s a été vaincu."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ¼­¹ö±º º¸ DB¿¡ á(½Ô °è ¸¯ÅÍ »ý¼º ÇÑ ½ýºÅÛá) - 
#define STRMSG_080430_0001					"Vous ne pouvez pas créer de nouveaux personnages sur le serveur sélectionné."

// 2008-06-13 by dhjin, EP3 ¿©´Ü ¼ö »çÇ× - 
#define STRMSG_080613_0001					"L'admission à la brigade %s a été rejetée."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[Erreur DB] Aucune fonction de requête de base de données de ce type (QP_xxx) !  Type de requête (%d:%s)\r\n"


// 2008-12-30 by cmkwon, ÁöµµÀÚ äÆÃ ÇÑ µå ±¸Çö - 
#define STRMSG_081230_0001					"\\y%s a été exclu du chat pour %d minutes.\\y"
#define STRMSG_081230_0002					"\\yLe chef du groupe vous a exclu du chat pour %d minutes.\\y"
#define STRMSG_081230_0003					"\\yVous n'êtes plus exclu du chat.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D °å µ¿ÀÇâ ¶ç¿ì±â - 
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - »ç¿ëÇÏÁö ¾Ê, STRMSG_090831_0001´Â ÆäÀÌÁö·Î ó¸®
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
/*#define STRMSG_090831_0002					"Installer Hackshield"*/
#define STRMSG_090831_0002					"Installer nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect µ¿ÀÇÃ¢ ¶ç¿ì±â
#define STRMSG_090831_0003					"Annuler"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D °ÔÀÓ °¡µå µ¿ÀÇâ WebPage·Î ó¸® - 
#define STRMSG_090902_0001					"http://fr.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, Áö¿ø Çóµµ á(1680x1050,1920x1080,1920x1200) - 
#define STRMSG_WINDOW_DEGREE_1680x1050_LOW			"1680x1050 (faible)"
#define STRMSG_WINDOW_DEGREE_1680x1050_MEDIUM		"1680x1050 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1680x1050_HIGH			"1680x1050 (haute)"
#define STRMSG_WINDOW_DEGREE_1920x1080_LOW			"1920x1080 (faible)"
#define STRMSG_WINDOW_DEGREE_1920x1080_MEDIUM		"1920x1080 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1920x1080_HIGH			"1920x1080 (haute)"
#define STRMSG_WINDOW_DEGREE_1920x1200_LOW			"1920x1200 (basse)"
#define STRMSG_WINDOW_DEGREE_1920x1200_MEDIUM		"1920x1200 (moyenne)"
#define STRMSG_WINDOW_DEGREE_1920x1200_HIGH			"1920x1200 (haute)"

///////////////////////////////////////////////////////////////////////////////
// 2011-01-26 by hskim, ÀÎÁõ ¼­¹öÀÇ ¼Ó Çã¿ë »ó
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Serveur non enregistré (il pourrait s'agir d'un serveur privé illégal)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"Une erreur est survenue lors de la connexion à la base de données."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"La confirmation a été effectuée"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"L'IP du serveur est enregistrée, mais les confirmations suivantes ont été refusées."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"La commande d'arrêt du serveur Windows a été envoyée."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ¸®°Å ½ýºÅÛ  ¾²

// 1Â÷ 

#define STRMSG_120330_0001					"%s active le portail de téléportation vers le lieu caché sur le chemin de cendres."
#define STRMSG_120330_0002					"%s active une augmentation de 100 %%%% des points d'expérience (événement happy hour d'une heure) sur le chemin de cendres."
#define STRMSG_120330_0003					"%s active une augmentation de 100 %%%% du taux de chute d'objets (événement happy hour d'une heure) sur le chemin de cendres."
#define STRMSG_120330_0004					"%s active une augmentation de 100 %%%% du taux de chute d'objets/des points d'expérience/des SPI (événement happy hour d'une heure) sur le chemin de cendres."
#define STRMSG_120330_0005					"%s active la boutique d'armes du chemin de cendres."
#define STRMSG_120330_0006					"%s active la boutique d'hypercartes du chemin de cendres."
#define STRMSG_120330_0007					"%s active la boutique de kits du chemin de cendres."
#define STRMSG_120330_0008					"%s invoque un monstre gigantesque au chemin de cendres."
#define STRMSG_120330_0009					"Le cristal a disparu."

// 2Â÷ 

#define STRMSG_120508_0001					"%s reçoit autant de points de guerre, que %d en a reçu dans l'Oasis Submergée."
#define STRMSG_120508_0002					"%s invoque un boss dans l'Oasis Submergée."
#define STRMSG_120508_0003					"%s active une augmentation de 150 %%%% des points d'expérience (événement happy hour d'une heure) dans l'Oasis Submergée."
#define STRMSG_120508_0004					"%s active une augmentation de 150 %%%% du taux de chute d'objets (événement happy hour d'une heure) dans l'Oasis Submergée."
#define STRMSG_120508_0005					"%s active une augmentation de 150 %%%% du taux de chute d'objets/des points d'expérience/des SPI (événement happy hour d'une heure) dans l'Oasis Submergée."
#define STRMSG_120508_0006					"%s reçoit une glace ancienne dans l'Oasis Submergée."
#define STRMSG_120508_0007					"%s active un item shop agrandi dans l'Oasis Submergée."
#define STRMSG_120508_0008					"%s active la boutique de kits de l'Oasis Submergée."
#define STRMSG_120508_0009					"%s active la boutique d'hypercartes de l'Oasis Submergée."
#define STRMSG_120508_0010					"%s active la boutique d'armes de l'Oasis Submergée."
#define STRMSG_120508_0011					"%s active le portail de téléportation vers le lieu caché de l'Oasis Submergée."

#define STRMSG_120712_0001					"18¼¼ ¹¸ û¼°Ô Àû¿ëµÂ °ÔÀð£ ¼±ÅÃ ¼³·Î ÀÎ, %d ºÐ  °ÔÀÓÀÌ ·áµÙ."		// 2012-07-11 by hskim, ¼±ÅÃÀû ¼î

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc¹æ ¸ðµâ
#define STRMSG_121005_0001					"\\yPC¹æ °¡¸Í ½ð£ÀÌ %dºÐ ³²¾Ù."
#define STRMSG_121005_0002					"\\yÀá½Ã ÈÄ PC¹æ °¡¸ÍÀÌ ·áµÙ."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ÀüÀï ½ýºÅÛ ¸®´º¾ó - ÀüÀï½Ã ¸®°Å ¹«Àû»óÅÂ(ÀÃÁö)
#define STRMSG_121126_0001					"\\yCommande : pendant une bataille, toute action impliquant directement les cristaux est interdite.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX ¸Ê ¿öÇÁÇÑ
#define STRMSG_121129_0001					"\\y¿ ÀÇ ÀÌ ÇÈ Áö¿ª ÀÙ.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ÀüÀü±âÁö ¸®°Å ½ýºÅÛ
#define STRMSG_130121_0001					"\\c Les troupes NGC ont conquis le système. L'évacuation immédiate a commencé."
#define STRMSG_130121_0002					"\\cÉclaireurs :\\c Le \\rcontrôleur NGC\\r a été renforcé."
#define STRMSG_130121_0003					"\\cÉclaireurs :\\c Le \\rcontrôleur NGC\\r a été détruit."
#define STRMSG_130121_0004					"\\cCommande :\\c Les boucliers de \\rGomora\\r sont activés. Détruisez le \\rcontrôleur NGC\\r pour désactiver les boucliers."
#define STRMSG_130121_0005					"\\cCommande :\\c Les boucliers de \\rGomora\\r sont désactivés ! Lancez l'attaque !"
#define STRMSG_130121_0006					"\\cCommande :\\c \\rGomora\\r est détruit ! En avant toute !"
#define STRMSG_130121_0007					"\\cCommande :\\c \\rGomora\\r doit d'abord être détruit."
#define STRMSG_130121_0008					"\\c[%s] a été activé par le surchargement du \\c\\rcontrôleur NGC\\r."
#define STRMSG_130121_0009					"\\y[Système de la base d'avant-poste NGC]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ¾ÆÀÌÅÛ  - ¼­ºêŸÀÔ á±¸ ½ýºÅÛ º¸¾È
#define STRMSG_130422_0001					"\\y%s %d n'est pas autorisé dans l'arène. L'objet a été expédié dans votre entrepôt.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim ¾Ó Ä÷º¼Ç - STRMSG á
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gLa carte d'apparence a été ajoutée à votre collection de cartes d'apparence.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gLa carte d'apparence a déjà été utilisée [%2d] fois.\\g"
#define STRMSG_130531_0003					"\\g[%s] La carte d'apparence a atteint son taux d'utilisation maximal. Vous obtenez [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"Votre carte d'apparence n'est plus valide et les valeurs correspondantes ont été supprimées. Le moteur n'est plus équipé."
#define STRMSG_130531_0005					"\\yAucun moteur n'est équipé. Vous allez être téléporté dans la ville.\\y"
#define STRMSG_130531_0006					"\\gVous ne pouvez pas vous servir de la carte d'apparence actuellement utilisée pour votre armure.\\g"
#define STRMSG_130531_0007					"\\gL'apparence a été modifiée.\\g"
#define STRMSG_130531_0008					"\\rLa carte d'apparence de [%s] n'est plus valide.\\r"
#define STRMSG_130531_0009					"\\yLes armures avec cartes d'apparence équipées ne peuvent pas être vendues.\\y"
#define STRMSG_130531_0010					"\\yLes types de vaisseau ne concordent pas.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ¸®°Å ½ýºÅÛ Àå - STRMSG á
#define STRMSG_130708_0001					"\\cCommande :\\c Les boucliers NGC ont été activés. Détruisez le \\rcontrôleur NGC\\r pour désactiver les boucliers de \\rGomora\\r."
#define STRMSG_130708_0002					"\\cCommande :\\c La défense de la base militaire NGC est tombée. Lancez l'attaque !"
#define STRMSG_130708_0003					"\\cÉclaireurs :\\c Le \\rgénérateur de bouclier NGC\\r a été contrôlé."
#define STRMSG_130708_0004					"\\cÉclaireurs :\\c Le \\rgénérateur de bouclier NGC\\r a été détruit."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ °è ¼¼·º¯°æ
#define STRMSG_130726_0001					"Le personnage est déjà membre de cette nation."
#define STRMSG_130726_0002					"Le personnage est chef ou vice-président et ne peut pas changer de nation."
#define STRMSG_130726_0003					"Le personnage appartient à la brigade et ne peut pas changer de nation."
#define STRMSG_130726_0004					"Aucun personnage ne peut changer de nation."
#define STRMSG_130726_0005					"Le changement de nation a échoué[AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)] !"
#define STRMSG_130726_0006					"La changement de nation est terminé [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"Ce compte n'existe pas !"
#define STRMSG_130726_0008					"Vous êtes connecté à votre compte : vous ne pouvez pas changer de nation."


// 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ
#define STRMSG_130830_0001					"\\yLes privilèges de vol de %s ont été révoqués par le chef des nations.\\y"
#define STRMSG_130830_0002					"\\yLes privilèges de vol ont été révoqués par le chef des nations.\\y"
#define STRMSG_130830_0003					"\\yLes privilèges de vol de %s ont été révoqués par le chef des nations.\\y"
// End. 2013-08-30 by bckim, Çå±ÝÁö¾ÆÀÌÅÛ

// 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­
#define STRMSG_130828_0001					"\\y[%s a contribué à la destruction de \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s a porté le premier coup contre \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s a mené au total le plus d'attaques contre \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s a porté le coup décisif contre \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n a été vaincu."
// End. 2013-08-28 by bckim, º¸½º¸ó½ºÅÍ º¸»ó°­

// 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â
#define STRMSG_130814_0001					"\\y[%s] a gagné la guerre NGC de points stratégiques.\\y"
// end 2013-08-14 by jhseol, °ÅÀü ¸®´º¾ó - ½¸®¼¼·Â GM ¸¼Áö »®±â

// 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)
#define STRMSG_130318_0001					"%s a appelé le boss dans une zone bloquée."
#define STRMSG_130318_0002					"%s a appelé le boss dans les ruines."
// End. 2014-03-12 by bckim, ¹ö´×ŸÀÓ(ÀüÀïÁö¿ª)

// 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF
#define STRMSG_130318_0003					"\\yL'hôtel des ventes est momentanément indisponible.\\y"
// End. 2014-03-18 by bckim, ¸¶ÄÏ ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
