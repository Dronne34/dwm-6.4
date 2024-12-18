/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int startwithgaps[]    = { 13 };	/* 1 means gaps are used by default, this can be customized for each tag */
static const unsigned int gappx[]   = { 13 };   /* default gap between windows in pixels, this can be customized for each tag */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewonrulestag 	= 1;		 /* 1 means when open applications view will move to tags defined in rules*/
static const char *fonts[]          = {"Mononoki Nerd Font:style=Regular:size=16"};
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char dmenufont[]       = {"FantasqueSansMono Nerd Font:size=15"};
static const char col_gray1[]       = "#2A303A";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_cyan1[]       = "#99cc00";
static const char col_cyan2[]       = "#cc3399";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_cyan1 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan2 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                      instance                title           tags mask     switchtotag    isfloating   monitor */
	{ "Gimp",                     NULL,                   NULL,            0,            1,             1,           -1, },
	{ "Firefox",                  NULL,                   NULL,            1 << 2,       1,             0,           -1, },
    { "mpv",                      NULL,                   NULL,            1 << 3,       1,             0,           -1, },
    { "Subl",                     NULL,                   NULL,            1,            1,             0,           -1, },
    { "Thunar",                   NULL,                   NULL,            1,            1,             0,           -1, },
    { "Pcmanfm",                  NULL,                   NULL,            1,            1,             0,           -1, },
    { "URxvt",                    NULL,                   NULL,            0,            1,             0,           -1, },
    { "ffplay",                   NULL,                   NULL,            1 << 4,       1,             0,           -1, },
    { "Meld",                     NULL,                   NULL,            1 << 1,       1,             0,           -1, },
    { "Gpick",                    NULL,                   NULL,            1,            1,             1,           -1, },
    { "pulsemixer",               NULL,                   NULL,            0,            1,             1,           -1, },
    { "Alacritty",                NULL,                   NULL,            1,            1,             0,           -1, },
    { "org.gnome.FileRoller",     NULL,                   NULL,            0,            0,             1,           -1, },
    { "Lxappearance",             NULL,                   NULL,            1,            1,             1,           -1, },
    { "Brave-browser",            NULL,                   NULL,            1 << 2,       1,             0,           -1, },
    { "Chromium",                 NULL,                   NULL,            1 << 2,       1,             0,           -1, },
    { "TelegramDesktop",          NULL,                   NULL,            1 << 1,       1,             0,           -1, },
	{ "Vivaldi-stable",           NULL,                   NULL,            1 << 2,       1,             0,           -1, },
    { "File Operation Progress",  NULL,                   NULL,            0,            0,             1,           -1, },
    { NULL,                       "x_st",                 NULL,            0,            0,             1,           -1, },
    { NULL,                       "key",                  NULL,            0,            0,             1,           -1, },
    { NULL,                       "x_mem",                NULL,            0,            0,             1,           -1, },
    { NULL,                       "x_ranger",             NULL,            0,            0,             1,           -1, },
    { "cava",                     "st-256color",          NULL,            1 << 4,       1,             0,           -1, },
    { "st-256color",              "st-256color",          "cava",          1 << 4,       1,             0,           -1, },
    { "ncmpcpp",                  "st-256color",          NULL,            1 << 4,       1,             0,           -1, },
    { "TelegramDesktop",          "telegram-desktop",     "Media viewer",  1 << 1,       1,             1,           -1, },
    { "org.gnome.FileRoller",     "org.gnome.FileRoller", "Extract",       0,            0,             1,           -1, },
    { "org.gnome.FileRoller",     "org.gnome.FileRoller", "Compress",      0,            0,             1,           -1, },
    { "Subl",                     NULL,                   "Open File",     0,            0,             1,           -1, },
    { "zenity",                   NULL,                   NULL,            0,            0,             1,           -1, },
    { NULL,                       NULL,                   "Extract files", 0,            0,             1,           -1, },
    { NULL,                       "Xarchiver",            "Extract files", 0,            0,             1,           -1, },
    { "xarchiver",                "Xarchiver",            "Extract files", 0,            0,             1,           -1, },
    { "Xarchiver",                NULL,                   NULL,            0,            0,             1,           -1, },
    { NULL,                       NULL,                   "sb-popupgrade", 0,            0,             1,           -1, },

};

/* layout(s) */
static const float mfact     = 0.58; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

	
static const char *browsercmd[]  = { "chromium",                              NULL };
static const char *termedit[]    = { "alacritty", "-e",  "vim",               NULL };
static const char *termfile[]    = { "alacritty", "-e", "ranger",             NULL };
static const char *dmenucmd[]    = { "dmenu_run_history", "-i", "-l", "15",   NULL };

static const char *termcmd[]     = { "st",                                                               NULL };
static const char *xst[]         = { "st", "-n", "x_st", "-g", "100x30",                                 NULL };
static const char *xranger[]     = { "st", "-n", "x_ranger", "-g", "100x30", "-e", "ranger",             NULL };
static const char *xpopupgrade[] = { "st", "-n", "x_popupgrade", "-g", "100x30", "-e", "sb-popupgrade", NULL };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    /* { MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} }, */
    /* { MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} }, */
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} },
    { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[5]} },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { ShiftMask|Mod4Mask,           XK_s,      spawn,          {.v = termedit } },
    { ShiftMask|Mod4Mask,           XK_t,      spawn,          {.v = termfile } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ControlMask,           XK_f,      spawn,          {.v = browsercmd } },
    { MODKEY|ControlMask,           XK_i,      spawn,          {.v = xpopupgrade } },
    { MODKEY|ControlMask,           XK_u,      spawn,          {.v = xranger } },
    { MODKEY,                       XK_y,      spawn,          {.v = xst } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
    { MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
    { MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
    { MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
    { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
    { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },

    // { ClkStatusText,        ShiftMask,      Button6,        sigdwmblocks,   {.i = 6} },
    // { ClkStatusText,        ShiftMask,      Button7,        sigdwmblocks,   {.i = 7} },




    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

