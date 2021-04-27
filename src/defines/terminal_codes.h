#pragma once

#define CT_ESC "\x1B["
#define CT_CLEAR_SCREEN CT_ESC "2J"

// colors
// indexed: 4bit, 8bit
#define CT_IDX_COLOR_(_where,_color)    CT_ESC #_where ";5;" + _color + "m"
#define CT_IDX_COLOR_FOREGROUND(_color) CT_IDX_COLOR_(38,_color)
#define CT_IDX_COLOR_BACKGROUND(_color) CT_IDX_COLOR_(48,_color)
// 24bit
#define CT_24B_COLOR_(_where,_r,_g,_b)    CT_ESC #_where ";2;" + _r + ";" + _g + ";" + _b + "m"
#define CT_24B_COLOR_FOREGROUND(_r,_g,_b) CT_24B_COLOR_(38,_r,_g,_b)
#define CT_24B_COLOR_BACKGROUND(_r,_g,_b) CT_24B_COLOR_(48,_r,_g,_b)

#define CT_RESET         CT_ESC "0m"
#define CT_BOLD          CT_ESC "1m"
#define CT_ITALIC        CT_ESC "3m"
#define CT_UNDERLINE     CT_ESC "4m"
#define CT_BLINK         CT_ESC "5m"
#define CT_NO_BLINK      CT_ESC "25m"
#define CT_STRIKETHROUGH CT_ESC "9m"

// cursor
#define CT_CURSOR_MOVE(_x,_y) CT_ESC + std::to_string(_y) + ";" + std::to_string(_x) + "H"
#define CT_CURSOR_HIDE        CT_ESC "?25l"
#define CT_CURSOR_SHOW        CT_ESC "?25h"
#define CT_CURSOR_SAVE        CT_ESC "s"
#define CT_CURSOR_LOAD        CT_ESC "u"

/*
\x1b[48;5;13m   -- background
\x1b[38;5;13m   -- foreground
\x1b[48;5;215m\x1b[38;5;46m - both

 \e[1m bold
 \e[3m italic
 \e[4m underline
 \e[9m strikethrough
 \x1b[21;20H - move
*/
