#include <X11/XF86keysym.h>

/* See LICENSE file for copyright and license details. */

#include "/home/alp/.cache/wal/colors-wal-dwm.h"

/* appearance */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int swallowfloating    = 0; 
static const int showsystray        = 1;     /* 0 means no systray */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
// static const char *fonts[]          = { "Jetbrains Mono:size=8" };
// static const char *fonts[]	    = {"Fira Code Nerd Font:size=9"};
static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 1;	/* 1 to show underline on all tags, 0 for just the active ones */
static const char *fonts[]		=	{ "Cozette:style=Regular:size=10:antialias=true:autohint=true" };
// static const ichar *fonts[]			=	{ "scientifica Nerd Font:size=11" };
// static const char *fonts[]			=	{ "JetBrainsMonoMedium Nerd Font:size=10" };
static const char dmenufont[]       = "Hack Nerd Font:size=12";


/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
// static const char *tags[] = { " ", "ﭮ", "" ,"", "", "", "7", "8", "" };
// static const char *tags[] = { " ¹", "ﭮ ²", " ³" ," ⁴", " ⁵", " ⁶", " ⁷", "ﲎ ⁸", " ⁹" };
static const char *tags[] = { "www", "dc", "telegram", "term", "filemgr","IDE", "vm", "steam", "epic", "lutris", "game" };
// static const char *tags[] = {"1️⃣","2️⃣","3️⃣","4️⃣","5️⃣","6️⃣","7️⃣","8️⃣","9️⃣"};
static const unsigned int gappx     = 20;        /* gaps between windows */
//static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
//static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
//static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
//static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title       tags mask     isfloating   monitor */
//	{ "Gimp",           NULL,       NULL,       0,            1,           -1 },
	{ "Gimp",     NULL,       NULL,       0,            0,           1,           -1 },
    // { "Firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },

	// { "xterm-256color",           NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
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
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
//static const char *roficmd[] = { "rofi","-show-icons","-modi drun,run","-font 'Jetbrains Mono 12'", "-show drun", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", "-show-icons","-font 'scientifica Nerd Font 12'", NULL };
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", "zsh", NULL };
static const char *upvol[]   = { "amixer", "set", "Master", "5%+",     NULL };
static const char *downvol[] = { "amixer", "set", "Master", "5%-",     NULL };
static const char *mutevol[] = { "amixer", "set", "Master", "toggle",  NULL };
static const char *lock[] = {"slock" , NULL };
// playpause next prev
static const char *sstool[] = {"xfce4-screenshooter", NULL};
static const char *ranger[] = {"st", "-e", "ranger", "/home/enginar/", NULL};
static const char *ytmenu[] = {"ytfzf", "-D", NULL};
static const char *playpause[] = { "playerctl", "play-pause", NULL };
static const char *next[] = { "playerctl",  "next", NULL};
static const char *prev[] = { "playerctl", "previous", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	// { MODKEY|ShiftMask,				XK_s,	   spawn		   { .v = sstool } },
	{ MODKEY|ShiftMask,				XK_l,	   spawn,		   {.v = lock    } },
	{ MODKEY|ShiftMask,				XK_r,	   spawn,		   { .v = ranger } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = sstool    } },
	{ MODKEY|ShiftMask,				XK_y,	   spawn,		   {.v = ytmenu} },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ Mod1Mask,                     XK_F4,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
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
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                       XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
	{ 0,			   XF86XK_AudioPlay, spawn, {.v = playpause} },
       	{ 0, 			   XF86XK_AudioNext, spawn, {.v = next } },
	{ 0,			   XF86XK_AudioPrev, spawn, {.v = prev } },	
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
//	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

