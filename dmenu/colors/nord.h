#if XRESOURCES_PATCH
static char *colors[][2] =
#else
static const char *colors[][2] =
#endif // XRESOURCES_PATCH
{
        /*               fg         bg       */
        [SchemeNorm] = { "#f5ffff", "#2E3440" },
  	[SchemeSel] = { "#000", "#81a1c1" },
  	[SchemeOut] = { "#F5ffff", "#81a1c1" },
        #if MORECOLOR_PATCH
        [SchemeMid]  = { "#eeeeee", "#770000" },
        #endif // MORECOLOR_PATCH
        #if HIGHLIGHT_PATCH || FUZZYHIGHLIGHT_PATCH
        [SchemeSelHighlight]  = { "#ffc978", "#005577" },
        [SchemeNormHighlight] = { "#ffc978", "#222222" },
        #endif // HIGHLIGHT_PATCH | FUZZYHIGHLIGHT_PATCH
        #if HIGHPRIORITY_PATCH
        [SchemeHp]   = { "#bbbbbb", "#333333" },
        #endif // HIGHPRIORITY_PATCH
};
