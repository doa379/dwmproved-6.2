/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int sloppyfocus        = 0;        /* 0 means click to focus */
static const char *fonts[]          = { "sans-serif:pixelsize=10:style=Bold" };
static const char dmenufont[]       = "sans-serif:pixelsize=16";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_gray10[]      = "#1a1a1a";
static const char col_gray20[]      = "#333333";
static const char col_gray30[]      = "#4d4d4d";
static const char col_gray40[]      = "#666666";
static const char col_gray50[]      = "#808080";
static const char col_gray60[]      = "#999999";
static const char col_gray70[]      = "#b3b3b3";
static const char col_gray80[]      = "#cccccc";
static const char col_gray90[]      = "#e6e6e6";
static const char col_cyan[]        = "#005577";
static const char col_cyan30[]      = "#006e99";
static const char col_cyan40[]      = "#0092cc";
static const char col_cyan50[]      = "#00b7ff";
static const char col_cyan60[]      = "#33c5ff";
static const char col_cyan70[]      = "#66d4ff";
static const char col_cyan80[]      = "#99e2ff";
static const char col_cyan90[]      = "#ccf1ff";
static const char col_yellow[]      = "#ffff00";
static const char col_yellow70[]    = "#ffff66";
static const char col_yellow80[]    = "#ffff99";
static const char col_yellow90[]    = "#ffffcc";
static const char col_magenta[]     = "#750075";
static const char col_magenta70[]   = "#ff66ff";
static const char col_magenta80[]   = "#ff99ff";
static const char col_magenta90[]   = "#ffccff";
static const char col_red[]         = "#ff0000";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
  /*
	[SchemeNorm] = { col_gray80,    col_gray10, col_cyan   },
	[SchemeSel]  = { col_gray80,    col_cyan,   col_yellow },
  */
	[SchemeNorm] = { col_gray1,    col_gray80, col_cyan   },
	[SchemeSel]  = { col_gray1,    col_cyan80,   col_yellow },
  /* Scheme ordering for colored status bar */
  /*
	[Scheme0]    = { col_cyan80,    col_gray10, "#000000"  },
	[Scheme1]    = { col_cyan80,    col_gray10, "#000000"  },
	[Scheme2]    = { col_yellow80,  col_gray10, "#000000"  },
	[Scheme3]    = { col_magenta80, col_gray10, "#000000"  },
	[Scheme4]    = { col_cyan80,    col_gray10, "#000000"  },
	[Scheme5]    = { col_yellow80,  col_gray10, "#000000"  },
	[Scheme6]    = { col_magenta80, col_gray10, "#000000"  },
	[Scheme7]    = { col_gray80,    col_gray10, "#000000"  },
	[Scheme8]    = { col_cyan80,    col_gray10, "#000000"  },
	[Scheme9]    = { col_red,       col_cyan,   "#000000"  },
	[Scheme10]   = { col_gray10,    col_gray80, "#000000"  },
	[Scheme11]   = { col_gray10,    col_gray80, "#000000"  },
	[Scheme12]   = { col_gray10,    col_gray80, "#000000"  },
  */
	[Scheme0]    = { col_gray1,    col_gray80, "#000000"  },
	[Scheme1]    = { col_gray1,    col_cyan80, "#000000"  },
	[Scheme2]    = { col_gray1,    col_yellow80, "#000000"  },
	[Scheme3]    = { col_gray1,    col_magenta80, "#000000"  },
	[Scheme4]    = { col_gray1,    col_gray80, "#000000"  },
	[Scheme5]    = { col_gray1,    col_cyan80, "#000000"  },
	[Scheme6]    = { col_gray1,    col_yellow80, "#000000"  },
	[Scheme7]    = { col_gray1,    col_magenta80, "#000000"  },
	[Scheme8]    = { col_gray1,    col_gray80, "#000000"  },
	[Scheme9]    = { col_gray1,    col_cyan80, "#000000"  },
	[Scheme10]   = { col_gray1,    col_yellow80, "#000000"  },
	[Scheme11]   = { col_gray1,    col_magenta80, "#000000"  },
	[Scheme12]   = { col_gray1,    col_gray80, "#000000"  },
};

static const char statusfile[]      = "/tmp/status";
static const unsigned int upd_intvl = 15;   /* in secs */
static const char statusdelim[]     = "|#!>";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ NULL },    /* no layout function means floating behavior */
	{ tile },
	{ monocle },
  { tcl },
  { grid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "xterm", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Escape, spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05 } },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_grave,  view,           {0} },
  { MODKEY|ShiftMask,             XK_Tab,    focusview,      {.i = -1 } },
	{ MODKEY,                       XK_Tab,    focusview,      {.i = +1 } },
  { MODKEY,                       XK_bracketleft, occview,   {.i = -1 } },
	{ MODKEY,                       XK_bracketright, occview,  {.i = +1 } },
	{ MODKEY,                       XK_minus,  shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_equal,  shiftview,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_s,      togglefloating, {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1] } },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2] } },
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[3] } },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[4] } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_BackSpace, view,        {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_BackSpace, tag,         {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button2,        zoom,           {0} },
	{ ClkTagBar,            0,              Button1,        focusstack,     {.i = +1 } },
	{ ClkTagBar,            0,              Button3,        focusstack,     {.i = -1 } },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
