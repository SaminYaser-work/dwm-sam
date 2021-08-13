/* See LICENSE file for copyright and license details. */

#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 15;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 5;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 5;  /* vert inner gap between windows */
static const unsigned int gappoh         = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;

static char *fonts[] = {
    "JetBrains Mono:pixelsize=14:antialias=true:autohint=true",
    "Noto Naskh Arabic UI:pixelsize=15:antialias=true:autohint=true",
    "JetBrainsMonoExtraBold Nerd Font Mono:pixelsize=22:antialias=true:autohint=true",
    "JoyPixels:pixelsize=15:antialias=true:autohint=true"};

static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#282828";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#282828";
static char selbordercolor[]             = "#13FF00";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#282828";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#282828";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#282828";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#504945";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";


static const unsigned int baralpha = 0xff;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};




const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16",
                        "-g", "50x20", "-e", "bc", "-lq", NULL};
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
   {"spcalc",      spcmd2},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { " ﷲ ", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = TERMCLASS, .isterminal = 1)
	RULE(.class = "mpv", .isfloating = 1)
	/* RULE(.class = "Gimp", .tags = 1 << 4) */
	/* RULE(.class = "Firefox", .tags = 1 << 7) */
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.instance = "spcalc", .tags = SPTAG(1), .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ 'A',      0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{  0,       0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ -1,       0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",                       tile },
    { "[B]",                     bstack },

    { "[S]",                     spiral },
    { "[DW]",                   dwindle },

    { "[D]",                       deck },
	{ "[M]",                    monocle },

	{ "[CM]",            centeredmaster },
	{ "[CFM]",   centeredfloatingmaster },


    { "[F]",                       NULL },
    { NULL,                        NULL },

};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
    { MOD, XK_v,     ACTION##stack, {.i = 0 } },

	// { MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
	// { MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
	// { MOD, XK_a,     ACTION##stack, {.i = 2 } }, \
	// { MOD, XK_z,     ACTION##stack, {.i = -1 } },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { TERMINAL, NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	STACKKEYS(MODKEY,                              focus)
	STACKKEYS(MODKEY|ShiftMask,                    push)

	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },


    //Size
    { MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },

    //Gaps
	{ MODKEY,                       XK_z,          incrgaps,               {.i = +3 } },
	{ MODKEY,                       XK_x,          incrgaps,               {.i = -3 } },
    { MODKEY,                       XK_a,          togglegaps,             {0} },
	{ MODKEY|ShiftMask,             XK_a,          defaultgaps,            {0} },

    //Shiftview
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY,                       XK_g,          shiftviewclients,       { .i = -1 } },
	{ MODKEY,                       XK_semicolon,  shiftviewclients,       { .i = +1 } },

    //Close program
	{ MODKEY,                       XK_q,          killclient,             {0} },

    //layouts
    { MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} }, //tile
    { MODKEY|ShiftMask,             XK_t,          setlayout,              {.v = &layouts[1]} }, //bstack
    { MODKEY,                       XK_y,          setlayout,              {.v = &layouts[2]} }, //Spiral
    { MODKEY|ShiftMask,             XK_y,          setlayout,              {.v = &layouts[3]} }, //Dwindle
    { MODKEY,                       XK_u,          setlayout,              {.v = &layouts[4]} }, //Deck
    { MODKEY|ShiftMask,             XK_u,          setlayout,              {.v = &layouts[5]} }, //Monocle
    { MODKEY,                       XK_i,          setlayout,              {.v = &layouts[6]} }, //CM
    { MODKEY|ShiftMask,             XK_i,          setlayout,              {.v = &layouts[7]} }, //CFM
    // { MODKEY,                       XK_f,          fullscreen,             {0} }, //fullscreen with monocle
    { MODKEY,                       XK_f,          togglefullscreen,        {0} }, //real fullscreen
    { MODKEY|ShiftMask,             XK_f,          setlayout,              {.v = &layouts[8]} }, //floating
    { MODKEY,                       XK_s,          togglesticky,           {0} }, //makes window sticky

    //Increase or decrease Master
    { MODKEY,                       XK_o,          incnmaster,             {.i = +1 } },
    { MODKEY|ShiftMask,             XK_o,          incnmaster,             {.i = -1 } },

    { MODKEY,                       XK_space,      zoom,                   {0} }, //Make master
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} }, //Make floating

	{ MODKEY,                       XK_apostrophe, togglescratch,          {.ui = 1 } },
    { MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } }, //terminal
    { MODKEY|ShiftMask,             XK_Return,     togglescratch,          {.ui = 0 } },

    { MODKEY,                      XK_bracketleft, focusmon,               {.i = -1 } },
	{ MODKEY,                     XK_bracketright, focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,            XK_bracketleft, tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,           XK_bracketright, tagmon,                 {.i = +1 } },

    //restarts DWM (Needs modification in .Xinitrc)
    { MODKEY|ShiftMask,             XK_grave,      quit,                   {0} },

	// { MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	// { MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	// { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	// { MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	// { MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	// { MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	// { MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	// { MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	// { MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	// { ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	// { ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	// { ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	// { ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	// { ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigdwmblocks,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigdwmblocks,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigdwmblocks,   {.i = 3 } },
    { ClkStatusText,        0,                   Button4,        sigdwmblocks,   {.i = 4 } },
    { ClkStatusText,        0,                   Button5,        sigdwmblocks,   {.i = 5 } },
    { ClkStatusText,    ShiftMask,               Button1,        sigdwmblocks,   {.i = 6 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	// { ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

