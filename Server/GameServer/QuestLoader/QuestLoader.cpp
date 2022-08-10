/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         QuestLoaderparse
#define yylex           QuestLoaderlex
#define yyerror         QuestLoadererror
#define yylval          QuestLoaderlval
#define yychar          QuestLoaderchar
#define yydebug         QuestLoaderdebug
#define yynerrs         QuestLoadernerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "QuestLoader.y"

#pragma warning(disable:4786)
#include <iostream>
#include "UserVariable.h"
//#include "windows.h"
#ifdef _ATUM_FIELD_SERVER
	#include "DBGOUT_Field.h"
#endif

#ifndef DBGOUT
#define DBGOUT (void(0))
#endif

#include "Quest.h"
#include "AtumDataLoader.h"

extern int QuestLoadererror(const char* s);
extern int QuestLoaderlex();

int				g_line_number_quest = 1;
CUserVariable	g_user_var_quest;

CQuest			g_quest_for_loading;
QUEST_NPC_INFO  g_quest_npc_info_for_loading;
vector<ITEM_W_COUNT>		g_item_w_count_list_for_loading;
vector<ITEM_W_COUNT_PROB>	g_item_w_count_list_for_random_pay_item;

ez_map<INT, CQuest*>	*g_pQuestInfoMap;
vectCQuestPtr			*g_pvectQuestInfoList;		// 2007-07-09 by cmkwon, 퀘스트 스크립트를 정보를 vector로 받기 위해

/* Line 371 of yacc.c  */
#line 106 "QuestLoader.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "QuestLoader.hpp".  */
#ifndef YY_QUESTLOADER_QUESTLOADER_HPP_INCLUDED
# define YY_QUESTLOADER_QUESTLOADER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int QuestLoaderdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUEST_TOK = 258,
     BASIC_INFO_TOK = 259,
     QUEST_INDEX_TOK = 260,
     QUEST_NAME_TOK = 261,
     QUEST_EPISODE_TYPE_TOK = 262,
     QUEST_PARTYTYPE_TOK = 263,
     QUEST_KIND_TOK = 264,
     QUEST_TYPE_TOK = 265,
     QUEST_START_TYPE_TOK = 266,
     QUEST_END_TYPE_TOK = 267,
     QUEST_PARTY_MEMBERS_TOK = 268,
     QUEST_NPC_INFO_TOK = 269,
     NPC_INDEX_TOK = 270,
     NPC_NAME_TOK = 271,
     PRE_TALK_TOK = 272,
     MID_TALK_TOK = 273,
     FAIL_TALK_TOK = 274,
     SUCCESS_TALK_TOK = 275,
     DESCRIPTION_TOK = 276,
     EVENT_MAP_TOK = 277,
     NEXT_QUEST_INDEX_TOK = 278,
     PARTY_QUEST_MEMBER_COUNT_TOK = 279,
     DROP_ITEM_TO_ALL_ATTACK_CHARACTER_TOK = 280,
     TIME_LIMIT_IN_MINUTES_TOK = 281,
     DISCARDABLE_QUEST_TOK = 282,
     BI_QUEST_ATTRI_IS_CITYWAR_TOK = 283,
     BI_QUEST_ATTRI_NEVER_COMPLETION_BY_USER_TOK = 284,
     DROP_ITEM_TO_ALL_PARTY_MEMBERS_TOK = 285,
     START_REQ_TOK = 286,
     S_REQ_UNIT_KIND_TOK = 287,
     S_REQ_LEVEL_TOK = 288,
     S_REQ_ATTACK_PART_TOK = 289,
     S_REQ_DEFENSE_PART_TOK = 290,
     S_REQ_FUEL_PART_TOK = 291,
     S_REQ_SOUL_PART_TOK = 292,
     S_REQ_SHIELD_PART_TOK = 293,
     S_REQ_DODGE_PART_TOK = 294,
     S_REQ_ITEM_TOK = 295,
     S_REQ_QUEST_INDEX_TOK = 296,
     S_REQ_RECV_QUEST_INDEX_TOK = 297,
     S_REQ_GUILD_TOK = 298,
     S_REQ_INFLUENCE_TYPE_TOK = 299,
     S_REQ_START_AREA_TOK = 300,
     START_ACTION_TOK = 301,
     S_PAY_ITEM_TOK = 302,
     S_DEL_ITEM_TOK = 303,
     S_START_MAP_INDEX_TOK = 304,
     S_START_PARTY_WARP_FLAG_TOK = 305,
     COMPLETION_REQ_TOK = 306,
     C_REQ_MEET_NPC_INFO_TOK = 307,
     C_REQ_ITEM_TOK = 308,
     C_REQ_MEET_OBJ_INDEX_TOK = 309,
     C_REQ_DEAD_BY_MONSTER_TOK = 310,
     C_REQ_MEET_MAP_AREA_TOK = 311,
     C_REQ_MONSTER_TOK = 312,
     C_REQ_MIX_ITEM_TARGET_TOK = 313,
     C_REQ_USE_ITEM_TOK = 314,
     COMPLETION_ACTION_TOK = 315,
     C_PAY_BONUS_STAT_TOK = 316,
     C_PAY_BONUS_SKILL_POINT_TOK = 317,
     C_PAY_FAME_TOK = 318,
     C_PAY_STATUS_TOK = 319,
     C_PAY_LEVEL_TOK = 320,
     C_PAY_EXPERIENCE_TOK = 321,
     C_PAY_WARP_MAP_INDEX_TOK = 322,
     C_DEL_ITEM_TOK = 323,
     C_PAY_ITEM_TOK = 324,
     C_PAY_ITEM_MISSIONMASTER_TOK = 325,
     C_RANDOM_PAY_ITEM_TOK = 326,
     C_MIX_ITEM_TOK = 327,
     C_PAY_PROPENSITY_TOK = 328,
     C_CINEMA_NUM_TOK = 329,
     C_PAY_INFLUENCE_TYPE_TOK = 330,
     FROM_TOK = 331,
     TO_TOK = 332,
     MONSTER_TOK = 333,
     CHARACTER_TOK = 334,
     ALL_TOK = 335,
     ATTACH_TOK = 336,
     AREA_TOK = 337,
     X_TOK = 338,
     Y_TOK = 339,
     R_TOK = 340,
     PER_TOK = 341,
     PROB_100_TOK = 342,
     PROB_1K_TOK = 343,
     PROB_10K_TOK = 344,
     PROB_100K_TOK = 345,
     PROB_256_TOK = 346,
     AND_TOK = 347,
     OR_TOK = 348,
     TRUE_TOK = 349,
     FALSE_TOK = 350,
     R_ARROW_TOK = 351,
     GT_TOK = 352,
     LT_TOK = 353,
     GE_TOK = 354,
     LE_TOK = 355,
     EQUAL_TOK = 356,
     USER_VARIABLE_TOK = 357,
     INTEGER_TOK = 358,
     WORD_TOK = 359,
     QSTRING_TOK = 360
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 34 "QuestLoader.y"

	int					BOOLEAN;
	int					integer;
	char				string2048[2048];
	MONSTER_W_COUNT		monster_w_count;
	ITEM_W_COUNT		item_w_count;
	ITEM_W_COUNT_PROB	item_w_count_prob;
	QUEST_PAY_ITEM		quest_pay_item;
	INT_RANGE			integer_range;
	MAP_AREA			map_area;


/* Line 387 of yacc.c  */
#line 267 "QuestLoader.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE QuestLoaderlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int QuestLoaderparse (void *YYPARSE_PARAM);
#else
int QuestLoaderparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int QuestLoaderparse (void);
#else
int QuestLoaderparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_QUESTLOADER_QUESTLOADER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 295 "QuestLoader.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNRULES -- Number of states.  */
#define YYNSTATES  469

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     112,   113,   109,   107,   116,   106,     2,   108,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   111,
       2,   110,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,   115,   117,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    17,    22,    27,
      36,    38,    41,    47,    52,    58,    63,    69,    74,    80,
      85,    91,    96,    98,   101,   106,   111,   116,   121,   126,
     131,   136,   141,   146,   152,   157,   162,   167,   172,   177,
     182,   187,   192,   197,   202,   207,   212,   217,   222,   227,
     232,   237,   242,   247,   252,   257,   262,   267,   272,   277,
     282,   287,   292,   298,   304,   309,   314,   331,   350,   355,
     360,   365,   371,   376,   381,   386,   391,   396,   401,   406,
     411,   416,   421,   426,   433,   441,   446,   451,   456,   458,
     462,   469,   471,   475,   476,   489,   492,   496,   502,   507,
     512,   516,   520,   524,   528,   532,   536,   540,   542,   544,
     546,   548,   553,   558,   563,   568,   573,   578,   580,   583,
     588,   593,   598,   603,   608,   613,   614,   617,   618,   620,
     621,   624,   626,   628,   633,   638,   643,   648
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     119,     0,    -1,   120,    -1,   119,   120,    -1,   121,    -1,
     122,    -1,   102,   110,   132,   111,    -1,   102,   110,   105,
     111,    -1,   102,   110,   102,   111,    -1,     3,   112,   103,
     113,   114,   123,   115,   111,    -1,   124,    -1,   123,   124,
      -1,     4,   114,   125,   115,   111,    -1,     4,   114,   115,
     111,    -1,    31,   114,   125,   115,   111,    -1,    31,   114,
     115,   111,    -1,    46,   114,   125,   115,   111,    -1,    46,
     114,   115,   111,    -1,    51,   114,   125,   115,   111,    -1,
      51,   114,   115,   111,    -1,    60,   114,   125,   115,   111,
      -1,    60,   114,   115,   111,    -1,   126,    -1,   125,   126,
      -1,     5,   110,   132,   111,    -1,     6,   110,   133,   111,
      -1,     7,   110,   132,   111,    -1,     8,   110,   132,   111,
      -1,     9,   110,   132,   111,    -1,    10,   110,   132,   111,
      -1,    11,   110,   132,   111,    -1,    12,   110,   132,   111,
      -1,    13,   110,   132,   111,    -1,    14,   114,   138,   115,
     111,    -1,    21,   110,   133,   111,    -1,    22,   110,   132,
     111,    -1,    23,   110,   132,   111,    -1,    24,   110,   132,
     111,    -1,    25,   110,   143,   111,    -1,    26,   110,   132,
     111,    -1,    27,   110,   143,   111,    -1,    28,   110,   143,
     111,    -1,    29,   110,   143,   111,    -1,    30,   110,   143,
     111,    -1,    32,   110,   132,   111,    -1,    33,   110,   131,
     111,    -1,    34,   110,   131,   111,    -1,    35,   110,   131,
     111,    -1,    36,   110,   131,   111,    -1,    37,   110,   131,
     111,    -1,    38,   110,   131,   111,    -1,    39,   110,   131,
     111,    -1,    40,   110,   135,   111,    -1,    41,   110,   132,
     111,    -1,    42,   110,   132,   111,    -1,    43,   110,   132,
     111,    -1,    44,   110,   132,   111,    -1,    45,   110,   130,
     111,    -1,    47,   110,   136,   111,    -1,    48,   110,   135,
     111,    -1,    49,   110,   132,   111,    -1,    50,   110,   143,
     111,    -1,    52,   114,   138,   115,   111,    -1,    54,   110,
     132,   130,   111,    -1,    59,   110,   135,   111,    -1,    53,
     110,   135,   111,    -1,    53,   110,   135,    76,    78,   112,
     132,   116,   132,   117,   132,   116,   132,   113,   130,   111,
      -1,    53,   110,   135,    76,    79,   112,   132,   116,   132,
     116,   132,   117,   132,   116,   132,   113,   130,   111,    -1,
      55,   110,   132,   111,    -1,    56,   110,   130,   111,    -1,
      57,   110,   134,   111,    -1,    57,   110,   134,   130,   111,
      -1,    58,   110,   135,   111,    -1,    61,   110,   132,   111,
      -1,    62,   110,   132,   111,    -1,    63,   110,   132,   111,
      -1,    64,   110,   132,   111,    -1,    65,   110,   132,   111,
      -1,    66,   110,   132,   111,    -1,    67,   110,   132,   111,
      -1,    68,   110,   135,   111,    -1,    69,   110,   136,   111,
      -1,    70,   110,   137,   111,    -1,    71,   110,   127,    86,
     132,   111,    -1,    72,   110,   129,    96,   132,   144,   111,
      -1,    73,   110,   132,   111,    -1,    74,   110,   132,   111,
      -1,    75,   110,   132,   111,    -1,   128,    -1,   127,    93,
     128,    -1,   132,   112,   132,   116,   132,   113,    -1,   135,
      -1,   129,   107,   135,    -1,    -1,    82,   132,   112,    83,
     132,   116,    84,   132,   116,    85,   132,   113,    -1,    82,
     132,    -1,   112,   132,   113,    -1,   112,   132,   117,   132,
     113,    -1,   112,   132,   117,   113,    -1,   112,   117,   132,
     113,    -1,   132,   107,   132,    -1,   132,   106,   132,    -1,
     132,   109,   132,    -1,   132,   108,   132,    -1,   132,    92,
     132,    -1,   132,    93,   132,    -1,   112,   132,   113,    -1,
     103,    -1,   102,    -1,   105,    -1,   102,    -1,   132,   112,
     132,   113,    -1,   132,   112,    80,   113,    -1,   132,   112,
     132,   113,    -1,   132,   112,    80,   113,    -1,   135,   140,
     141,   142,    -1,   135,   140,   141,   142,    -1,   139,    -1,
     138,   139,    -1,    15,   110,   132,   111,    -1,    16,   110,
     133,   111,    -1,    17,   110,   133,   111,    -1,    18,   110,
     133,   111,    -1,    19,   110,   133,   111,    -1,    20,   110,
     133,   111,    -1,    -1,    86,   132,    -1,    -1,    81,    -1,
      -1,    77,   132,    -1,    94,    -1,    95,    -1,    87,   112,
     132,   113,    -1,    88,   112,   132,   113,    -1,    89,   112,
     132,   113,    -1,    90,   112,   132,   113,    -1,    91,   112,
     132,   113,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   187,   187,   189,   193,   195,   199,   205,   211,   233,
     259,   261,   265,   270,   272,   274,   276,   278,   280,   282,
     284,   286,   290,   292,   297,   302,   314,   319,   324,   329,
     334,   339,   344,   349,   355,   367,   372,   377,   382,   387,
     392,   397,   402,   407,   413,   418,   423,   428,   433,   438,
     443,   448,   453,   458,   463,   468,   473,   478,   484,   489,
     494,   499,   505,   511,   518,   524,   529,   552,   571,   576,
     581,   590,   599,   605,   610,   616,   621,   626,   631,   636,
     641,   646,   651,   656,   677,   704,   709,   714,   721,   726,
     733,   742,   747,   755,   762,   770,   780,   786,   792,   798,
     806,   808,   810,   812,   825,   827,   829,   831,   833,   853,
     855,   875,   881,   889,   895,   903,   914,   925,   927,   931,
     936,   948,   960,   972,   984,   999,  1003,  1011,  1015,  1023,
    1027,  1034,  1039,  1046,  1051,  1056,  1061,  1066
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUEST_TOK", "BASIC_INFO_TOK",
  "QUEST_INDEX_TOK", "QUEST_NAME_TOK", "QUEST_EPISODE_TYPE_TOK",
  "QUEST_PARTYTYPE_TOK", "QUEST_KIND_TOK", "QUEST_TYPE_TOK",
  "QUEST_START_TYPE_TOK", "QUEST_END_TYPE_TOK", "QUEST_PARTY_MEMBERS_TOK",
  "QUEST_NPC_INFO_TOK", "NPC_INDEX_TOK", "NPC_NAME_TOK", "PRE_TALK_TOK",
  "MID_TALK_TOK", "FAIL_TALK_TOK", "SUCCESS_TALK_TOK", "DESCRIPTION_TOK",
  "EVENT_MAP_TOK", "NEXT_QUEST_INDEX_TOK", "PARTY_QUEST_MEMBER_COUNT_TOK",
  "DROP_ITEM_TO_ALL_ATTACK_CHARACTER_TOK", "TIME_LIMIT_IN_MINUTES_TOK",
  "DISCARDABLE_QUEST_TOK", "BI_QUEST_ATTRI_IS_CITYWAR_TOK",
  "BI_QUEST_ATTRI_NEVER_COMPLETION_BY_USER_TOK",
  "DROP_ITEM_TO_ALL_PARTY_MEMBERS_TOK", "START_REQ_TOK",
  "S_REQ_UNIT_KIND_TOK", "S_REQ_LEVEL_TOK", "S_REQ_ATTACK_PART_TOK",
  "S_REQ_DEFENSE_PART_TOK", "S_REQ_FUEL_PART_TOK", "S_REQ_SOUL_PART_TOK",
  "S_REQ_SHIELD_PART_TOK", "S_REQ_DODGE_PART_TOK", "S_REQ_ITEM_TOK",
  "S_REQ_QUEST_INDEX_TOK", "S_REQ_RECV_QUEST_INDEX_TOK", "S_REQ_GUILD_TOK",
  "S_REQ_INFLUENCE_TYPE_TOK", "S_REQ_START_AREA_TOK", "START_ACTION_TOK",
  "S_PAY_ITEM_TOK", "S_DEL_ITEM_TOK", "S_START_MAP_INDEX_TOK",
  "S_START_PARTY_WARP_FLAG_TOK", "COMPLETION_REQ_TOK",
  "C_REQ_MEET_NPC_INFO_TOK", "C_REQ_ITEM_TOK", "C_REQ_MEET_OBJ_INDEX_TOK",
  "C_REQ_DEAD_BY_MONSTER_TOK", "C_REQ_MEET_MAP_AREA_TOK",
  "C_REQ_MONSTER_TOK", "C_REQ_MIX_ITEM_TARGET_TOK", "C_REQ_USE_ITEM_TOK",
  "COMPLETION_ACTION_TOK", "C_PAY_BONUS_STAT_TOK",
  "C_PAY_BONUS_SKILL_POINT_TOK", "C_PAY_FAME_TOK", "C_PAY_STATUS_TOK",
  "C_PAY_LEVEL_TOK", "C_PAY_EXPERIENCE_TOK", "C_PAY_WARP_MAP_INDEX_TOK",
  "C_DEL_ITEM_TOK", "C_PAY_ITEM_TOK", "C_PAY_ITEM_MISSIONMASTER_TOK",
  "C_RANDOM_PAY_ITEM_TOK", "C_MIX_ITEM_TOK", "C_PAY_PROPENSITY_TOK",
  "C_CINEMA_NUM_TOK", "C_PAY_INFLUENCE_TYPE_TOK", "FROM_TOK", "TO_TOK",
  "MONSTER_TOK", "CHARACTER_TOK", "ALL_TOK", "ATTACH_TOK", "AREA_TOK",
  "X_TOK", "Y_TOK", "R_TOK", "PER_TOK", "PROB_100_TOK", "PROB_1K_TOK",
  "PROB_10K_TOK", "PROB_100K_TOK", "PROB_256_TOK", "AND_TOK", "OR_TOK",
  "TRUE_TOK", "FALSE_TOK", "R_ARROW_TOK", "GT_TOK", "LT_TOK", "GE_TOK",
  "LE_TOK", "EQUAL_TOK", "USER_VARIABLE_TOK", "INTEGER_TOK", "WORD_TOK",
  "QSTRING_TOK", "'-'", "'+'", "'/'", "'*'", "'='", "';'", "'('", "')'",
  "'{'", "'}'", "','", "'~'", "$accept", "command_list", "command",
  "user_variable_definition", "quest_definition", "quest_content_list",
  "quest_content", "statement_list", "statement", "item_w_count_prob_list",
  "item_w_count_prob_value", "item_w_count_list", "map_area_value",
  "integer_range_value", "integer_expression", "string_expression",
  "monster_w_count_value", "item_w_count_value", "quest_pay_item_value",
  "quest_missinmaster_pay_item_value", "quest_npc_statement_list",
  "quest_npc_statement", "per_item_value", "attach_value",
  "to_unit_kind_value", "boolean_value", "prob_value", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,    45,    43,    47,    42,
      61,    59,    40,    41,   123,   125,    44,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   119,   120,   120,   121,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   137,   138,   138,   139,
     139,   139,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   144,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     4,     4,     8,
       1,     2,     5,     4,     5,     4,     5,     4,     5,     4,
       5,     4,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     5,     4,     4,    16,    18,     4,     4,
       4,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     7,     4,     4,     4,     1,     3,
       6,     1,     3,     0,    12,     2,     3,     5,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     1,     2,     4,
       4,     4,     4,     4,     4,     0,     2,     0,     1,     0,
       2,     1,     1,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     0,     0,     1,
       3,     0,   108,   107,     0,     0,     0,     0,     8,     7,
     108,     0,     0,     0,     0,     0,     0,     0,     6,     0,
     106,   104,   105,   101,   100,   103,   102,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    23,    15,     0,
      17,     0,    19,     0,    21,     0,     0,   110,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
      88,     0,     0,    91,     0,     0,     0,    12,    14,    16,
      18,    20,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   118,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,     0,    45,    46,    47,    48,    49,    50,    51,     0,
      52,    53,    54,    55,    56,    95,    57,     0,   127,    58,
      59,    60,    61,     0,     0,    65,     0,    68,    69,     0,
      70,     0,    72,    64,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   127,    82,     0,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    33,
       0,    96,     0,     0,     0,     0,   126,   128,   129,    62,
       0,     0,    63,     0,     0,    71,   129,     0,    89,     0,
       0,    92,   119,   120,   121,   122,   123,   124,    99,    98,
       0,   114,   113,     0,     0,   115,     0,     0,   112,   111,
     116,    83,     0,     0,     0,     0,     0,     0,     0,    97,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    93,     0,     0,     0,    66,    93,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    42,    43,   113,   114,   269,
     270,   272,   243,   229,   236,   199,   255,   244,   245,   268,
     213,   214,   328,   378,   405,   221,   418
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -204
static const yytype_int16 yypact[] =
{
      -1,  -108,   -86,     5,  -204,  -204,  -204,   -75,    32,  -204,
    -204,   -83,   -79,  -204,   -45,    94,   359,   -54,  -204,  -204,
    -204,   207,    94,    94,    94,    94,    94,    94,  -204,    19,
    -204,  -204,  -204,   -24,   -24,   -80,   -80,   -38,   -34,   -27,
     -25,    -9,     2,  -204,   450,   534,   618,   702,   786,    -3,
    -204,    41,    43,    45,    48,    50,    51,    59,    63,    80,
      29,    88,   101,   108,   109,   114,   136,   146,   158,   159,
     160,   174,   175,   176,   177,   178,   180,   187,   188,   193,
     194,   195,   196,   199,   200,   202,   208,   219,   223,    35,
     225,   234,   235,   247,   249,   250,   251,   252,   253,   257,
     258,   265,   267,   268,   274,   275,   283,   287,   290,   291,
     292,   293,     4,   870,  -204,   106,   954,   184,  1038,   206,
    1122,   232,  1206,  -204,    94,   -30,    94,    94,    94,    94,
      94,    94,    94,   213,   -30,    94,    94,    94,    38,    94,
      38,    38,    38,    38,    94,   271,   271,   271,   271,   271,
     271,   271,    94,    94,    94,    94,    94,   327,    94,    94,
      94,    38,   213,    94,    94,    94,   327,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,  -204,   300,  -204,  -204,   304,
    -204,   305,  -204,   315,  -204,   320,   443,  -204,  -204,   322,
     527,   611,   695,   779,   863,   947,  1031,   325,   334,   335,
     339,   340,   343,    23,  -204,   329,  1115,  1263,  1271,  -204,
    -204,   358,  1283,   370,   385,   390,   399,  1291,   -29,   415,
     416,   417,   418,   419,   420,   421,  1227,   422,  1303,  1311,
    1323,  1331,    94,   423,   324,   426,   427,  1343,   442,    39,
     -67,   -15,  1351,   469,  1235,   -48,   474,   483,  1363,  1371,
    1383,  1391,  1403,  1411,  1423,   499,   500,   324,   501,   -22,
    -204,  1245,   -85,  -204,  1431,  1443,  1451,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,    94,   -30,   -30,   -30,   -30,   -30,   502,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
      94,   -11,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   -77,
    -204,  -204,  -204,  -204,  -204,  1253,  -204,    94,   533,  -204,
    -204,  -204,  -204,   504,    21,  -204,   505,  -204,  -204,   -51,
    -204,   506,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,   533,  -204,    94,    94,    94,    94,    94,
    -204,  -204,  -204,  1463,   507,   510,   511,   526,   553,  -204,
     215,  -204,     1,   556,   233,   595,  1483,  -204,   617,  -204,
     583,   584,  -204,   585,   245,  -204,   617,  1471,  -204,    85,
     185,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
     263,  -204,  -204,    94,    94,  -204,    94,    94,  -204,  -204,
    -204,  -204,    94,   587,   588,   589,   590,   593,   586,  -204,
      96,  1483,   107,   129,   273,    94,    94,    94,    94,    94,
    -204,   622,    94,    94,  -204,   281,   299,   321,   330,  1190,
      94,    33,   133,  -204,  -204,  -204,  -204,  -204,   151,    94,
      94,   636,   155,    78,    94,    94,    94,  1198,  1209,   173,
    -204,   327,    94,   637,  1217,  -204,   327,   642,  -204
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,   759,  -204,  -204,  -204,   736,   162,   214,  -204,
     424,  -204,  -165,   104,    -8,  -113,  -204,  -132,   601,  -204,
     619,  -203,   515,   430,   398,   -31,  -204
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      16,   253,     1,   373,     7,     9,    37,    21,     1,   334,
     298,   358,    22,    23,    31,    32,    33,    34,    35,    36,
     237,   215,   359,    37,     8,    20,    13,   246,    11,   383,
      17,   250,    18,    38,   242,    15,   256,   257,   207,   208,
     209,   210,   211,   212,   335,   265,   298,   267,    39,   273,
      38,    20,    13,    40,   207,   208,   209,   210,   211,   212,
      29,    15,    41,   340,   355,    39,    19,   242,    22,    23,
      40,   356,   197,    20,    13,   198,    44,    22,    23,    41,
      45,    22,    23,    15,    26,    27,   336,    46,   310,    47,
     341,    24,    25,    26,    27,    24,    25,    26,    27,   380,
     381,     2,   371,    20,    13,    48,   372,     2,   123,   223,
     224,   225,   226,    15,   399,   185,   196,    49,   200,   201,
     202,   203,   204,   205,   206,    22,    23,   216,   217,   218,
     248,   222,   219,   220,    12,    13,   227,    14,   297,    24,
      25,    26,    27,   133,    15,   238,   239,   240,   241,   162,
     449,   124,   247,   125,   333,   126,   251,   252,   127,   254,
     128,   129,   258,   259,   260,   261,   262,   263,   264,   130,
      22,    23,   271,   131,   274,   275,   276,    22,    23,   364,
     365,   366,   367,   368,    24,    25,    26,    27,    22,    23,
     132,    24,    25,    26,    27,   456,    20,    13,   134,    22,
      23,   412,    24,    25,    26,    27,    15,   116,   118,   120,
     122,   135,   431,    24,    25,    26,    27,   188,   136,   137,
     311,    22,    23,   432,   138,    22,    23,   391,   207,   208,
     209,   210,   211,   212,   325,    24,    25,    26,    27,    24,
      25,    26,    27,    22,    23,   433,   139,    22,    23,   450,
     230,   231,   232,   233,   234,   235,   140,    24,    25,    26,
      27,    24,    25,    26,    27,    22,    23,   451,   141,   142,
     143,   455,   413,   414,   415,   416,   417,    22,    23,    24,
      25,    26,    27,   363,   144,   145,   146,   147,   148,   462,
     149,    24,    25,    26,    27,   190,   463,   150,   151,    22,
      23,   467,   370,   152,   153,   154,   155,    22,    23,   156,
     157,   374,   158,    24,    25,    26,    27,   192,   159,   376,
      30,    24,    25,    26,    27,    22,    23,   187,   398,   160,
     187,   384,   187,   161,   187,   163,   187,    22,    23,    24,
      25,    26,    27,   194,   164,   165,   402,   387,   271,   389,
     390,    24,    25,    26,    27,    22,    23,   166,   409,   167,
     168,   169,   170,   171,   400,    22,    23,   172,   173,    24,
      25,    26,    27,    22,    23,   174,   419,   175,   176,    24,
      25,    26,    27,   228,   177,   178,   434,    24,    25,    26,
      27,    22,    23,   179,   443,   420,   421,   180,   422,   423,
     181,   182,   183,   184,   424,    24,    25,    26,    27,   242,
     327,   277,   444,    22,    23,   278,   279,   435,   436,   437,
     438,   439,    22,    23,   441,   442,   280,    24,    25,    26,
      27,   281,   448,   283,   445,   291,    24,    25,    26,    27,
     299,   452,   453,   446,   292,   293,   457,   458,   459,   294,
     295,    22,    23,   296,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    24,    25,    26,    27,   303,
      28,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   305,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   306,    85,    86,    87,
      88,   307,    89,    90,    91,    92,    93,    94,    95,    96,
     308,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   312,   313,   314,   315,
     316,   317,   318,   320,   326,    22,    23,   329,   330,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    24,
      25,    26,    27,   332,   282,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   112,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     338,    85,    86,    87,    88,   342,    89,    90,    91,    92,
      93,    94,    95,    96,   343,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     351,   352,   354,   369,   377,   379,   382,   385,   393,    22,
      23,   394,   395,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    24,    25,    26,    27,   396,   284,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   115,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   397,    85,    86,    87,    88,   401,
      89,    90,    91,    92,    93,    94,    95,    96,   403,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   404,   406,   407,   430,   408,   425,
     426,   427,   428,    22,    23,   429,   440,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    24,    25,    26,
      27,   454,   285,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   117,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   465,    85,
      86,    87,    88,   468,    89,    90,    91,    92,    93,    94,
      95,    96,    10,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    50,   266,
     388,   249,   353,   386,   410,     0,     0,    22,    23,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    24,    25,    26,    27,     0,   286,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   119,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,     0,    89,    90,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,     0,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    24,    25,    26,    27,     0,
     287,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   121,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,     0,    89,    90,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    24,
      25,    26,    27,     0,   288,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   186,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,    87,    88,     0,    89,    90,    91,    92,
      93,    94,    95,    96,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    24,    25,    26,    27,     0,   289,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   189,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,     0,
      89,    90,    91,    92,    93,    94,    95,    96,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    24,    25,    26,
      27,     0,   290,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   191,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      86,    87,    88,     0,    89,    90,    91,    92,    93,    94,
      95,    96,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    24,    25,    26,    27,     0,   300,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,   193,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,     0,    89,    90,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    22,    23,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,    24,    25,    26,    27,
       0,    22,    23,   447,    24,    25,    26,    27,     0,    22,
      23,   460,     0,     0,     0,    24,    25,    26,    27,    22,
      23,   195,   461,    24,    25,    26,    27,    22,    23,     0,
     466,     0,     0,    24,    25,    26,    27,    22,    23,   319,
       0,    24,    25,    26,    27,    22,    23,   339,     0,     0,
       0,    24,    25,    26,    27,    22,    23,   357,     0,    24,
      25,    26,    27,    22,    23,   375,     0,     0,     0,    24,
      25,    26,    27,     0,   301,    22,    23,    24,    25,    26,
      27,     0,   302,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   304,    22,    23,    24,    25,    26,
      27,     0,   309,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   321,    22,    23,    24,    25,    26,
      27,     0,   322,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   323,    22,    23,    24,    25,    26,
      27,     0,   324,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   331,    22,    23,    24,    25,    26,
      27,     0,   337,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   344,    22,    23,    24,    25,    26,
      27,     0,   345,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   346,    22,    23,    24,    25,    26,
      27,     0,   347,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   348,    22,    23,    24,    25,    26,
      27,     0,   349,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   350,    22,    23,    24,    25,    26,
      27,     0,   360,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   361,    22,    23,    24,    25,    26,
      27,     0,   362,    22,    23,     0,     0,     0,     0,    24,
      25,    26,    27,     0,   392,    22,    23,    24,    25,    26,
      27,     0,   411,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-204)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       8,   166,     3,    80,   112,     0,     4,    15,     3,    76,
     213,    96,    92,    93,    22,    23,    24,    25,    26,    27,
     152,   134,   107,     4,   110,   102,   103,   159,   103,    80,
     113,   163,   111,    31,    82,   112,   168,   169,    15,    16,
      17,    18,    19,    20,   111,   177,   249,   179,    46,   181,
      31,   102,   103,    51,    15,    16,    17,    18,    19,    20,
     114,   112,    60,   111,    86,    46,   111,    82,    92,    93,
      51,    93,   102,   102,   103,   105,   114,    92,    93,    60,
     114,    92,    93,   112,   108,   109,   251,   114,   117,   114,
     255,   106,   107,   108,   109,   106,   107,   108,   109,    78,
      79,   102,   113,   102,   103,   114,   117,   102,   111,   140,
     141,   142,   143,   112,   113,   111,   124,   115,   126,   127,
     128,   129,   130,   131,   132,    92,    93,   135,   136,   137,
     161,   139,    94,    95,   102,   103,   144,   105,   115,   106,
     107,   108,   109,   114,   112,   153,   154,   155,   156,   114,
     117,   110,   160,   110,   115,   110,   164,   165,   110,   167,
     110,   110,   170,   171,   172,   173,   174,   175,   176,   110,
      92,    93,   180,   110,   182,   183,   184,    92,    93,   292,
     293,   294,   295,   296,   106,   107,   108,   109,    92,    93,
     110,   106,   107,   108,   109,   117,   102,   103,   110,    92,
      93,   116,   106,   107,   108,   109,   112,    45,    46,    47,
      48,   110,   116,   106,   107,   108,   109,   111,   110,   110,
     228,    92,    93,   116,   110,    92,    93,   359,    15,    16,
      17,    18,    19,    20,   242,   106,   107,   108,   109,   106,
     107,   108,   109,    92,    93,   116,   110,    92,    93,   116,
     146,   147,   148,   149,   150,   151,   110,   106,   107,   108,
     109,   106,   107,   108,   109,    92,    93,   116,   110,   110,
     110,   116,    87,    88,    89,    90,    91,    92,    93,   106,
     107,   108,   109,   291,   110,   110,   110,   110,   110,   116,
     110,   106,   107,   108,   109,   111,   461,   110,   110,    92,
      93,   466,   310,   110,   110,   110,   110,    92,    93,   110,
     110,   319,   110,   106,   107,   108,   109,   111,   110,   327,
     113,   106,   107,   108,   109,    92,    93,   113,   113,   110,
     116,   339,   118,   110,   120,   110,   122,    92,    93,   106,
     107,   108,   109,   111,   110,   110,   113,   355,   356,   357,
     358,   106,   107,   108,   109,    92,    93,   110,   113,   110,
     110,   110,   110,   110,   372,    92,    93,   110,   110,   106,
     107,   108,   109,    92,    93,   110,   113,   110,   110,   106,
     107,   108,   109,   112,   110,   110,   113,   106,   107,   108,
     109,    92,    93,   110,   113,   403,   404,   110,   406,   407,
     110,   110,   110,   110,   412,   106,   107,   108,   109,    82,
      86,   111,   113,    92,    93,   111,   111,   425,   426,   427,
     428,   429,    92,    93,   432,   433,   111,   106,   107,   108,
     109,   111,   440,   111,   113,   110,   106,   107,   108,   109,
     111,   449,   450,   113,   110,   110,   454,   455,   456,   110,
     110,    92,    93,   110,   462,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   106,   107,   108,   109,   111,
     111,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   111,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   111,    47,    48,    49,
      50,   111,    52,    53,    54,    55,    56,    57,    58,    59,
     111,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   111,   111,   111,   111,
     111,   111,   111,   111,   111,    92,    93,   111,   111,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   106,
     107,   108,   109,   111,   111,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   115,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     111,    47,    48,    49,    50,   111,    52,    53,    54,    55,
      56,    57,    58,    59,   111,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     111,   111,   111,   111,    81,   111,   111,   111,   111,    92,
      93,   111,   111,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   106,   107,   108,   109,   111,   111,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   115,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   111,    47,    48,    49,    50,   113,
      52,    53,    54,    55,    56,    57,    58,    59,    83,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    77,   112,   112,   111,   113,   112,
     112,   112,   112,    92,    93,   112,    84,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   106,   107,   108,
     109,    85,   111,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   115,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   111,    47,
      48,    49,    50,   111,    52,    53,    54,    55,    56,    57,
      58,    59,     3,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    42,   178,
     356,   162,   267,   353,   386,    -1,    -1,    92,    93,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   106,   107,   108,   109,    -1,   111,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   115,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   106,   107,   108,   109,    -1,
     111,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   115,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   106,
     107,   108,   109,    -1,   111,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   115,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   106,   107,   108,   109,    -1,   111,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   115,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   106,   107,   108,
     109,    -1,   111,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   115,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   106,   107,   108,   109,    -1,   111,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   115,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
      -1,    92,    93,   113,   106,   107,   108,   109,    -1,    92,
      93,   113,    -1,    -1,    -1,   106,   107,   108,   109,    92,
      93,   115,   113,   106,   107,   108,   109,    92,    93,    -1,
     113,    -1,    -1,   106,   107,   108,   109,    92,    93,   112,
      -1,   106,   107,   108,   109,    92,    93,   112,    -1,    -1,
      -1,   106,   107,   108,   109,    92,    93,   112,    -1,   106,
     107,   108,   109,    92,    93,   112,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    92,    93,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,    -1,   111,    92,    93,   106,   107,   108,
     109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,   109
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   102,   119,   120,   121,   122,   112,   110,     0,
     120,   103,   102,   103,   105,   112,   132,   113,   111,   111,
     102,   132,    92,    93,   106,   107,   108,   109,   111,   114,
     113,   132,   132,   132,   132,   132,   132,     4,    31,    46,
      51,    60,   123,   124,   114,   114,   114,   114,   114,   115,
     124,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    47,    48,    49,    50,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   115,   125,   126,   115,   125,   115,   125,   115,
     125,   115,   125,   111,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   114,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   114,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   115,   126,   111,   115,
     111,   115,   111,   115,   111,   115,   132,   102,   105,   133,
     132,   132,   132,   132,   132,   132,   132,    15,    16,    17,
      18,    19,    20,   138,   139,   133,   132,   132,   132,    94,
      95,   143,   132,   143,   143,   143,   143,   132,   112,   131,
     131,   131,   131,   131,   131,   131,   132,   135,   132,   132,
     132,   132,    82,   130,   135,   136,   135,   132,   143,   138,
     135,   132,   132,   130,   132,   134,   135,   135,   132,   132,
     132,   132,   132,   132,   132,   135,   136,   135,   137,   127,
     128,   132,   129,   135,   132,   132,   132,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   110,   110,   110,   110,   110,   110,   115,   139,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     117,   132,   111,   111,   111,   111,   111,   111,   111,   112,
     111,   111,   111,   111,   111,   132,   111,    86,   140,   111,
     111,   111,   111,   115,    76,   111,   130,   111,   111,   112,
     111,   130,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   140,   111,    86,    93,   112,    96,   107,
     111,   111,   111,   132,   133,   133,   133,   133,   133,   111,
     132,   113,   117,    80,   132,   112,   132,    81,   141,   111,
      78,    79,   111,    80,   132,   111,   141,   132,   128,   132,
     132,   135,   111,   111,   111,   111,   111,   111,   113,   113,
     132,   113,   113,    83,    77,   142,   112,   112,   113,   113,
     142,   111,   116,    87,    88,    89,    90,    91,   144,   113,
     132,   132,   132,   132,   132,   112,   112,   112,   112,   112,
     111,   116,   116,   116,   113,   132,   132,   132,   132,   132,
      84,   132,   132,   113,   113,   113,   113,   113,   132,   117,
     116,   116,   132,   132,    85,   116,   117,   132,   132,   132,
     113,   113,   116,   130,   132,   111,   113,   130,   111
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
/* Line 1792 of yacc.c  */
#line 200 "QuestLoader.y"
    {
			g_user_var_quest.AddUserVariableInteger((yyvsp[(1) - (4)].string2048), (yyvsp[(3) - (4)].integer));
			_loader_print("user variable %s = %d\n", (yyvsp[(1) - (4)].string2048), (yyvsp[(3) - (4)].integer));
		}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 206 "QuestLoader.y"
    {
			g_user_var_quest.AddUserVariableString((yyvsp[(1) - (4)].string2048), (yyvsp[(3) - (4)].string2048));
			_loader_print("user variable %s = %s\n", (yyvsp[(1) - (4)].string2048), (yyvsp[(3) - (4)].string2048));
		}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 212 "QuestLoader.y"
    {
			USER_VAR_ELEMENT *pElem = g_user_var_quest.GetUserVariable((yyvsp[(3) - (4)].string2048));
			if (pElem == NULL)
			{
				// error
				QuestLoadererror("User Variable NOT Defined");
				return -1;
			}

			if (pElem->Type == ET_INTEGER)
			{
				_loader_print("user variable %s = %d\n", (yyvsp[(1) - (4)].string2048), pElem->IntValue);
			}
			else if (pElem->Type == ET_STRING)
			{
				_loader_print("user variable %s = %s\n", (yyvsp[(1) - (4)].string2048), pElem->StringValue);
			}
		}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 234 "QuestLoader.y"
    {
			// 2008-09-09 by cmkwon, 퀘스트 인덱스 중복 체크 
			if(NULL != g_pQuestInfoMap->findEZ((yyvsp[(3) - (8)].integer)))
			{
				// error
				QuestLoadererror("QuestIndex dup");
				return -1;
			}

			// 2007-07-09 by cmkwon, 퀘스트 스크립트를 정보를 vector로 받기 위해 - 아래와 같이 수정
			//g_pQuestInfoMap->insertEZ($3, g_quest_for_loading.Clone());
			CQuest *pQuestInfo = g_quest_for_loading.Clone();
			g_pQuestInfoMap->insertEZ((yyvsp[(3) - (8)].integer), pQuestInfo);
			if(g_pvectQuestInfoList)
			{
				g_pvectQuestInfoList->push_back(pQuestInfo);
			}
			_loader_print("quest %d defined...\n", (yyvsp[(3) - (8)].integer));

			// reset
			g_quest_for_loading.Reset();
		}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 266 "QuestLoader.y"
    {
			// _loader_print("%s's BASIC_INFO Parsed\n", "rr");
		}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 298 "QuestLoader.y"
    {
			g_quest_for_loading.QuestIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 303 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_QUEST_NAME <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("QuestName overflow error, QuestIndex(%d) QuestNameLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_for_loading.QuestName, 0x00, SIZE_MAX_QUEST_NAME);
			strncpy(g_quest_for_loading.QuestName, (yyvsp[(3) - (4)].string2048), SIZE_MAX_QUEST_NAME-1);
		}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 315 "QuestLoader.y"
    {
			g_quest_for_loading.QuestEpisodeType = (yyvsp[(3) - (4)].integer);	// 2008-06-16 by cmkwon, EP3 퀘스트 기존 퀘스트와 구별 - 
		}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 320 "QuestLoader.y"
    {
			g_quest_for_loading.QuestPartyType = (yyvsp[(3) - (4)].integer);        // 2008-12-02 by dhjin, 미션마스터
		}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 325 "QuestLoader.y"
    {
			g_quest_for_loading.QuestKind = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 330 "QuestLoader.y"
    {
			g_quest_for_loading.QuestType = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 335 "QuestLoader.y"
    {
			g_quest_for_loading.QuestStartType = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 340 "QuestLoader.y"
    {
			g_quest_for_loading.QuestEndType = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 345 "QuestLoader.y"
    {
			g_quest_for_loading.QuestPartyMembers = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 350 "QuestLoader.y"
    {
			g_quest_for_loading.QuestNPCInfo = g_quest_npc_info_for_loading;
			g_quest_npc_info_for_loading.Reset();
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 356 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_TALK_STRING <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("QuestDescription overflow error, QuestIndex(%d) QuestDescriptionLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_for_loading.QuestDescription, 0x00, SIZE_MAX_NPC_TALK_STRING);
			strncpy(g_quest_for_loading.QuestDescription, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_TALK_STRING-1);
		}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 368 "QuestLoader.y"
    {
			g_quest_for_loading.EventMapIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 373 "QuestLoader.y"
    {
			g_quest_for_loading.NextQuestIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 378 "QuestLoader.y"
    {
			g_quest_for_loading.PartyQuestMemberCount = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 383 "QuestLoader.y"
    {
			g_quest_for_loading.DropItemToAllAttackCharacter = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 388 "QuestLoader.y"
    {
			g_quest_for_loading.TimeLimitInMinutes = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 393 "QuestLoader.y"
    {
			g_quest_for_loading.IsDiscardable = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 398 "QuestLoader.y"
    {
			g_quest_for_loading.IsCityWar = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 403 "QuestLoader.y"
    {
			g_quest_for_loading.IsNeverCompletionByUser = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 408 "QuestLoader.y"
    {
			g_quest_for_loading.IsDropItemToAllPartyMembers = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 414 "QuestLoader.y"
    {
			g_quest_for_loading.ReqUnitKind = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 419 "QuestLoader.y"
    {
			g_quest_for_loading.ReqLevel = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 424 "QuestLoader.y"
    {
			g_quest_for_loading.ReqAttackPart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 429 "QuestLoader.y"
    {
			g_quest_for_loading.ReqDefensePart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 434 "QuestLoader.y"
    {
			g_quest_for_loading.ReqFuelPart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 439 "QuestLoader.y"
    {
			g_quest_for_loading.ReqSoulPart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 444 "QuestLoader.y"
    {
			g_quest_for_loading.ReqShieldPart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 449 "QuestLoader.y"
    {
			g_quest_for_loading.ReqDodgePart = (yyvsp[(3) - (4)].integer_range);
		}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 454 "QuestLoader.y"
    {
			g_quest_for_loading.ReqItemVector.push_back((yyvsp[(3) - (4)].item_w_count));
		}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 459 "QuestLoader.y"
    {
			g_quest_for_loading.ReqQuestIndexVector.push_back((yyvsp[(3) - (4)].integer));
		}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 464 "QuestLoader.y"
    {
			g_quest_for_loading.ReqRecvQuestIndexVector.push_back((yyvsp[(3) - (4)].integer));
		}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 469 "QuestLoader.y"
    {
			g_quest_for_loading.ReqGuild = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 474 "QuestLoader.y"
    {
			g_quest_for_loading.ReqInfluenceType = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 479 "QuestLoader.y"
    {
			g_quest_for_loading.ReqStartArea = (yyvsp[(3) - (4)].map_area);
		}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 485 "QuestLoader.y"
    {
			g_quest_for_loading.StartPayItemVector.push_back((yyvsp[(3) - (4)].quest_pay_item));
		}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 490 "QuestLoader.y"
    {
			g_quest_for_loading.StartDelItemVector.push_back((yyvsp[(3) - (4)].item_w_count));
		}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 495 "QuestLoader.y"
    {
			g_quest_for_loading.StartMapIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 500 "QuestLoader.y"
    {
			g_quest_for_loading.StartPartyWarpFlag = (yyvsp[(3) - (4)].BOOLEAN);
		}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 506 "QuestLoader.y"
    {
			g_quest_for_loading.TargetMeetNPCInfo = g_quest_npc_info_for_loading;
			g_quest_npc_info_for_loading.Reset();
		}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 512 "QuestLoader.y"
    {
			g_quest_for_loading.TargetMeetObjectIndex = (yyvsp[(3) - (5)].integer);
			g_quest_for_loading.TargetMeetObjectMapArea = (yyvsp[(4) - (5)].map_area);
		}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 519 "QuestLoader.y"
    {
			g_quest_for_loading.TargetUseItemVector.push_back((yyvsp[(3) - (4)].item_w_count));
		}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 525 "QuestLoader.y"
    {
			g_quest_for_loading.TargetItemVector.push_back((yyvsp[(3) - (4)].item_w_count));
		}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 530 "QuestLoader.y"
    {
			///////////////////////////////////////////////////////////////////////////////
			// 2007-03-14 by cmkwon, ItemNum이 0이거나 Count가 0이면 드랍아이템리스트에는 추가하지 않는다. 위치 정보에는 추가한다.
			if(0 < (yyvsp[(3) - (16)].item_w_count).ItemNum
				&& 0 <= (yyvsp[(3) - (16)].item_w_count).Count)
			{
				QUEST_DROP_ITEM tmpQuestDropItem;
				tmpQuestDropItem.MonsterUniqueNumber = (yyvsp[(7) - (16)].integer);
				tmpQuestDropItem.ItemNumber = (yyvsp[(3) - (16)].item_w_count).ItemNum;
				tmpQuestDropItem.MinCount = (yyvsp[(9) - (16)].integer);
				tmpQuestDropItem.MaxCount = (yyvsp[(11) - (16)].integer);
				tmpQuestDropItem.Probability = (yyvsp[(13) - (16)].integer);
				g_quest_for_loading.vecQuestDropItem.push_back(tmpQuestDropItem);
			}

			ITEM_W_COUNT_MAP_AREA tmpTargetMonsterItem;
			tmpTargetMonsterItem.ItemWithCount = (yyvsp[(3) - (16)].item_w_count);
			tmpTargetMonsterItem.MapArea = (yyvsp[(15) - (16)].map_area);
			tmpTargetMonsterItem.MonsterUniqueNumber = (yyvsp[(7) - (16)].integer);
			g_quest_for_loading.TargetMonsterItemVector.push_back(tmpTargetMonsterItem);
		}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 553 "QuestLoader.y"
    {
			QUEST_DROP_CHARACTER2ITEM tmpQuestDropItem;
			tmpQuestDropItem.InfluenceType0				= (yyvsp[(7) - (18)].integer);
			tmpQuestDropItem.UnitKindMask0				= (yyvsp[(9) - (18)].integer);
			tmpQuestDropItem.Character2Item.ItemNumber	= (yyvsp[(3) - (18)].item_w_count).ItemNum;
			tmpQuestDropItem.Character2Item.MinCount	= (yyvsp[(11) - (18)].integer);
			tmpQuestDropItem.Character2Item.MaxCount	= (yyvsp[(13) - (18)].integer);
			tmpQuestDropItem.Character2Item.Probability = (yyvsp[(15) - (18)].integer);
			tmpQuestDropItem.Character2Item.QuestIndex	= 0;
			g_quest_for_loading.vecQuestDropCharacter2Item.push_back(tmpQuestDropItem);

			ITEM_W_COUNT_MAP_AREA tmpTargetMonsterItem;
			tmpTargetMonsterItem.ItemWithCount = (yyvsp[(3) - (18)].item_w_count);
			tmpTargetMonsterItem.MapArea = (yyvsp[(17) - (18)].map_area);
			tmpTargetMonsterItem.MonsterUniqueNumber = 0;
			g_quest_for_loading.TargetMonsterItemVector.push_back(tmpTargetMonsterItem);
		}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 572 "QuestLoader.y"
    {
			g_quest_for_loading.TargetDeadByMonsterUniquenumber = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 577 "QuestLoader.y"
    {
			g_quest_for_loading.TargetMeetMapArea = (yyvsp[(3) - (4)].map_area);
		}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 582 "QuestLoader.y"
    {
			MONSTER_W_COUNT tmMonCnt;
			tmMonCnt.MonsterUniqueNumber	= (yyvsp[(3) - (4)].monster_w_count).MonsterUniqueNumber;
			tmMonCnt.Count					= (yyvsp[(3) - (4)].monster_w_count).Count;
			tmMonCnt.MapArea.Reset();
			g_quest_for_loading.TargetMonsterVector.push_back(tmMonCnt);
		}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 591 "QuestLoader.y"
    {
			MONSTER_W_COUNT tmMonCnt;
			tmMonCnt.MonsterUniqueNumber	= (yyvsp[(3) - (5)].monster_w_count).MonsterUniqueNumber;
			tmMonCnt.Count					= (yyvsp[(3) - (5)].monster_w_count).Count;
			tmMonCnt.MapArea				= (yyvsp[(4) - (5)].map_area);
			g_quest_for_loading.TargetMonsterVector.push_back(tmMonCnt);
		}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 600 "QuestLoader.y"
    {
			g_quest_for_loading.TargetMixItemTarget	= (yyvsp[(3) - (4)].item_w_count);
		}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 606 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayBonusStat = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 611 "QuestLoader.y"
    {
// 2005-11-15 by cmkwon, 삭제함
//			g_quest_for_loading.EndPayBonusSkillPoint = $3;
		}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 617 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayFame = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 622 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayStatus = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 627 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayLevel = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 632 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayExperience = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 637 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayWarpMapIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 642 "QuestLoader.y"
    {
			g_quest_for_loading.EndDeleteItemVector.push_back((yyvsp[(3) - (4)].item_w_count));
		}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 647 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayItemVector.push_back((yyvsp[(3) - (4)].quest_pay_item));
		}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 652 "QuestLoader.y"
    {// 2008-12-02 by dhjin, 미션마스터
			g_quest_for_loading.EndMissionMasterPayItemVector.push_back((yyvsp[(3) - (4)].quest_pay_item));
		}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 657 "QuestLoader.y"
    {
			// not implemented yet
			QUEST_RANDOM_PAY_ITEM tmpRandomPayItem; tmpRandomPayItem.Reset();
			for (int i = 0; i < g_item_w_count_list_for_random_pay_item.size(); i++)
			{
				if (i >= COUNT_RANDOM_PAY_ITEM)
				{
					break;
				}

				tmpRandomPayItem.ItemWithCountProb[i] = g_item_w_count_list_for_random_pay_item[i];
				tmpRandomPayItem.NumOfItems++;
			}
			tmpRandomPayItem.PerItemNum = (yyvsp[(5) - (6)].integer);

			g_quest_for_loading.EndRandomPayItemVector.push_back(tmpRandomPayItem);

			g_item_w_count_list_for_random_pay_item.clear();
		}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 678 "QuestLoader.y"
    {
			ITEM_MIXING_INFO tmpMixingInfo;
			tmpMixingInfo.TargetItemNum = (yyvsp[(5) - (7)].integer);
			tmpMixingInfo.MixingProbability = (yyvsp[(6) - (7)].integer);
			tmpMixingInfo.MixingCost = 0;
			memset(tmpMixingInfo.SourceItem, 0x00, COUNT_ITEM_MIXING_SOURCE*sizeof(ITEM_W_COUNT));
			tmpMixingInfo.NumOfSourceItems = 0;
			for (int i = 0; i < g_item_w_count_list_for_loading.size(); i++)
			{
				if (i >= COUNT_ITEM_MIXING_SOURCE)
				{
					break;
				}

				// 할당
				tmpMixingInfo.SourceItem[i] = g_item_w_count_list_for_loading[i];
				tmpMixingInfo.NumOfSourceItems++;

				//printf("%d(%d)\r\n", g_item_w_count_list_for_loading[i].ItemNum, g_item_w_count_list_for_loading[i].Count);
			}

			g_quest_for_loading.EndPayMixItemVector.push_back(tmpMixingInfo);

			g_item_w_count_list_for_loading.clear();
		}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 705 "QuestLoader.y"
    {
			g_quest_for_loading.EndPayPropensity = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 710 "QuestLoader.y"
    {
			g_quest_for_loading.EndCinemaNum = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 715 "QuestLoader.y"
    {
			g_quest_for_loading.EndInfluenceType = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 722 "QuestLoader.y"
    {
			g_item_w_count_list_for_random_pay_item.push_back((yyvsp[(1) - (1)].item_w_count_prob));
		}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 727 "QuestLoader.y"
    {
			g_item_w_count_list_for_random_pay_item.push_back((yyvsp[(3) - (3)].item_w_count_prob));
		}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 734 "QuestLoader.y"
    {
			(yyval.item_w_count_prob).ItemNum = (yyvsp[(1) - (6)].integer);
			(yyval.item_w_count_prob).Count = (yyvsp[(3) - (6)].integer);
			(yyval.item_w_count_prob).Prob100 = (yyvsp[(5) - (6)].integer);
		}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 743 "QuestLoader.y"
    {
			g_item_w_count_list_for_loading.push_back((yyvsp[(1) - (1)].item_w_count));
		}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 748 "QuestLoader.y"
    {
			g_item_w_count_list_for_loading.push_back((yyvsp[(3) - (3)].item_w_count));
		}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 755 "QuestLoader.y"
    {
			(yyval.map_area).MapIndex = 0;
			(yyval.map_area).X = -1;
			(yyval.map_area).Y = -1;
			(yyval.map_area).Radius = -1;
		}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 763 "QuestLoader.y"
    {
			(yyval.map_area).MapIndex = (yyvsp[(2) - (12)].integer);
			(yyval.map_area).X = (yyvsp[(5) - (12)].integer);
			(yyval.map_area).Y = (yyvsp[(8) - (12)].integer);
			(yyval.map_area).Radius = (yyvsp[(11) - (12)].integer);
		}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 771 "QuestLoader.y"
    {
			(yyval.map_area).MapIndex = (yyvsp[(2) - (2)].integer);
			(yyval.map_area).X = -1;
			(yyval.map_area).Y = -1;
			(yyval.map_area).Radius = -1;
		}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 781 "QuestLoader.y"
    {
			(yyval.integer_range).Min = (yyvsp[(2) - (3)].integer);
			(yyval.integer_range).Max = (yyvsp[(2) - (3)].integer);
		}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 787 "QuestLoader.y"
    {
			(yyval.integer_range).Min = (yyvsp[(2) - (5)].integer);
			(yyval.integer_range).Max = (yyvsp[(4) - (5)].integer);
		}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 793 "QuestLoader.y"
    {
			(yyval.integer_range).Min = (yyvsp[(2) - (4)].integer);
			(yyval.integer_range).Max = MAX_INT_VALUE;
		}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 799 "QuestLoader.y"
    {
			(yyval.integer_range).Min = 0;
			(yyval.integer_range).Max = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 806 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) + (yyvsp[(3) - (3)].integer); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 808 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) - (yyvsp[(3) - (3)].integer); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 810 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) * (yyvsp[(3) - (3)].integer); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 813 "QuestLoader.y"
    {
				if ((yyvsp[(3) - (3)].integer) == 0.0)
				{
					QuestLoadererror("divided by zero");
					return -1;
				}
				else
				{
					(yyval.integer) = (yyvsp[(1) - (3)].integer) / (yyvsp[(3) - (3)].integer);
				}
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 825 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) & (yyvsp[(3) - (3)].integer); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 827 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) | (yyvsp[(3) - (3)].integer); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 829 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 831 "QuestLoader.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 834 "QuestLoader.y"
    {
				USER_VAR_ELEMENT *pElem = g_user_var_quest.GetUserVariable((yyvsp[(1) - (1)].string2048));
				if (pElem == NULL)
				{
					// error
					QuestLoadererror("User Variable NOT Defined");
					return -1;
				}
				if (pElem->Type != ET_INTEGER)
				{
					// error
					QuestLoadererror("User Variable Type NOT Matched");
					return -1;
				}
				(yyval.integer) = pElem->IntValue;
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 853 "QuestLoader.y"
    { strncpy((yyval.string2048), (yyvsp[(1) - (1)].string2048), 2048); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 856 "QuestLoader.y"
    {
				USER_VAR_ELEMENT *pElem = g_user_var_quest.GetUserVariable((yyvsp[(1) - (1)].string2048));
				if (pElem == NULL)
				{
					// error
					QuestLoadererror("User Variable NOT Defined");
					return -1;
				}
				if (pElem->Type != ET_STRING)
				{
					// error
					QuestLoadererror("User Variable Type NOT Matched");
					return -1;
				}
				strncpy((yyval.string2048), pElem->StringValue, 2048);
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 876 "QuestLoader.y"
    {
			(yyval.monster_w_count).MonsterUniqueNumber = (yyvsp[(1) - (4)].integer);
			(yyval.monster_w_count).Count = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 882 "QuestLoader.y"
    {
			(yyval.monster_w_count).MonsterUniqueNumber = (yyvsp[(1) - (4)].integer);
			(yyval.monster_w_count).Count = MAX_INT_VALUE;
		}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 890 "QuestLoader.y"
    {
			(yyval.item_w_count).ItemNum = (yyvsp[(1) - (4)].integer);
			(yyval.item_w_count).Count = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 896 "QuestLoader.y"
    {
			(yyval.item_w_count).ItemNum = (yyvsp[(1) - (4)].integer);
			(yyval.item_w_count).Count = MAX_INT_VALUE;
		}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 904 "QuestLoader.y"
    {
			(yyval.quest_pay_item).ItemNum = (yyvsp[(1) - (4)].item_w_count).ItemNum;
			(yyval.quest_pay_item).Count = (yyvsp[(1) - (4)].item_w_count).Count;
			(yyval.quest_pay_item).PerItem = (yyvsp[(2) - (4)].integer);
			(yyval.quest_pay_item).ToBeAttached = (yyvsp[(3) - (4)].BOOLEAN);
			(yyval.quest_pay_item).ToUnitKind = (yyvsp[(4) - (4)].integer);
		}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 915 "QuestLoader.y"
    {
			(yyval.quest_pay_item).ItemNum = (yyvsp[(1) - (4)].item_w_count).ItemNum;
			(yyval.quest_pay_item).Count = (yyvsp[(1) - (4)].item_w_count).Count;
			(yyval.quest_pay_item).PerItem = (yyvsp[(2) - (4)].integer);
			(yyval.quest_pay_item).ToBeAttached = (yyvsp[(3) - (4)].BOOLEAN);
			(yyval.quest_pay_item).ToUnitKind = (yyvsp[(4) - (4)].integer);
		}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 932 "QuestLoader.y"
    {
			g_quest_npc_info_for_loading.NPCIndex = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 937 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_NAME <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("Quest NPCName overflow error, QuestIndex(%d) NPCNameLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_npc_info_for_loading.NPCName, 0x00, SIZE_MAX_NPC_NAME);
			strncpy(g_quest_npc_info_for_loading.NPCName, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_NAME-1);
		}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 949 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_TALK_STRING <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("Quest PreTalk overflow error, QuestIndex(%d) PreTalkLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_npc_info_for_loading.PreTalk, 0x00, SIZE_MAX_NPC_TALK_STRING);
			strncpy(g_quest_npc_info_for_loading.PreTalk, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_TALK_STRING-1);
		}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 961 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_TALK_STRING <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("Quest MidTalk overflow error, QuestIndex(%d) MidTalkLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_npc_info_for_loading.MidTalk, 0x00, SIZE_MAX_NPC_TALK_STRING);
			strncpy(g_quest_npc_info_for_loading.MidTalk, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_TALK_STRING-1);
		}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 973 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_TALK_STRING <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("Quest FailTalk overflow error, QuestIndex(%d) FailTalkLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_npc_info_for_loading.FailTalk, 0x00, SIZE_MAX_NPC_TALK_STRING);
			strncpy(g_quest_npc_info_for_loading.FailTalk, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_TALK_STRING-1);
		}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 985 "QuestLoader.y"
    {
#ifdef _ATUM_FIELD_SERVER
			if(SIZE_MAX_NPC_TALK_STRING <= strlen((yyvsp[(3) - (4)].string2048)))
			{
				DbgOut("Quest SuccessTalk overflow error, QuestIndex(%d) SuccessTalkLength(%d)\n", g_quest_for_loading.QuestIndex, strlen((yyvsp[(3) - (4)].string2048)));
			}
#endif
			memset(g_quest_npc_info_for_loading.SuccessTalk, 0x00, SIZE_MAX_NPC_TALK_STRING);
			strncpy(g_quest_npc_info_for_loading.SuccessTalk, (yyvsp[(3) - (4)].string2048), SIZE_MAX_NPC_TALK_STRING-1);
		}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 999 "QuestLoader.y"
    {
			(yyval.integer) = 0;
		}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1004 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1011 "QuestLoader.y"
    {
			(yyval.BOOLEAN) = FALSE;
		}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1016 "QuestLoader.y"
    {
			(yyval.BOOLEAN) = TRUE;
		}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1023 "QuestLoader.y"
    {
			(yyval.integer) = UNITKIND_ALL_MASK;
		}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1028 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(2) - (2)].integer);
		}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1035 "QuestLoader.y"
    {
			(yyval.BOOLEAN) = TRUE;
		}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1040 "QuestLoader.y"
    {
			(yyval.BOOLEAN) = FALSE;
		}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1047 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1052 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1057 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1062 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(3) - (4)].integer);
		}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1067 "QuestLoader.y"
    {
			(yyval.integer) = (yyvsp[(3) - (4)].integer);
		}
    break;


/* Line 1792 of yacc.c  */
#line 3257 "QuestLoader.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1071 "QuestLoader.y"


/* programs */

/*
 * ???
 */
extern "C"
{
int
QuestLoaderwrap()
{
  return 1;
}
}

/*
 * Report an error situation discovered in a production
 *
 * This does not do anything since we report all error situations through
 * idl_global->err() operations
 */
int
QuestLoadererror(const char *s)
{
    cerr << "Error: " << s << " at line " << g_line_number_quest << endl;
	DBGOUT("Error: %s at line %d\r\n", s, g_line_number_quest);
	system("pause");
	return 0;
}
