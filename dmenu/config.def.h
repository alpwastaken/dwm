/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

// Change colors
// #include "colors/nord.h"

// pywal
#include "/home/alp/.cache/wal/colors-wal-dmenu.h"

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom */
#if ALPHA_PATCH
static double opacity = 1.0;                /* -o  option; defines alpha translucency */
#endif // ALPHA_PATCH
#if FUZZYMATCH_PATCH
static int fuzzy = 1;                       /* -F  option; if 0, dmenu doesn't use fuzzy matching */
#endif // FUZZYMATCH_PATCH
#if INCREMENTAL_PATCH
static int incremental = 0;                 /* -r  option; if 1, outputs text each time a key is pressed */
#endif // INCREMENTAL_PATCH
#if INSTANT_PATCH
static int instant = 0;                     /* -n  option; if 1, selects matching item without the need to press enter */
#endif // INSTANT_PATCH
#if CENTER_PATCH
static int center = 1;                      /* -c  option; if 0, dmenu won't be centered on the screen */
static int min_width = 500;                 /* minimum width when centered */
#endif // CENTER_PATCH
/* -fn option overrides fonts[0]; default X11 font or font set */
#if PANGO_PATCH
static char font[] = "Cozette 10";
#else
#if XRESOURCES_PATCH
static char *fonts[] =
#else
static const char *fonts[] =
#endif // XRESOURCES_PATCH
{
	"CozetteVector:style=Regular:pixelsize=12:antialias=true"
};
#endif // PANGO_PATCH
#if MANAGED_PATCH
static char *prompt            = NULL;      /* -p  option; prompt to the left of input field */
#else
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
#endif // MANAGED_PATCH
#if DYNAMIC_OPTIONS_PATCH
static const char *dynamic     = NULL;      /* -dy option; dynamic command to run on input change */
#endif // DYNAMIC_OPTIONS_PATCH
#if SYMBOLS_PATCH
static const char *symbol_1 = "<";
static const char *symbol_2 = ">";
#endif // SYMBOLS_PATCH

#if ALPHA_PATCH
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
#endif // ALPHA_PATCH
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
#if GRID_PATCH
/* -g option; if nonzero, dmenu uses a grid comprised of columns and lines */
static unsigned int columns    = 0;
#endif // GRID_PATCH
#if LINE_HEIGHT_PATCH
static unsigned int lineheight = 0;         /* -h option; minimum height of a menu line     */
#endif // LINE_HEIGHT_PATCH
#if NAVHISTORY_PATCH
static unsigned int maxhist    = 15;
static int histnodup           = 1;	/* if 0, record repeated histories */
#endif // NAVHISTORY_PATCH

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
#if PIPEOUT_PATCH
static const char startpipe[] = "#";
#endif // PIPEOUT_PATCH
static const char worddelimiters[] = " ";

#if BORDER_PATCH
/* Size of the window border */
static unsigned int border_width = 5;
#endif // BORDER_PATCH

#if PREFIXCOMPLETION_PATCH
/*
 * Use prefix matching by default; can be inverted with the -x flag.
 */
static int use_prefix = 1;
#endif // PREFIXCOMPLETION_PATCH
