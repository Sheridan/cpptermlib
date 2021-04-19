#pragma once

#define CT_ESC "\x1B["
#define CT_CLEAR_SCREEN CT_ESC "2J"

// font
#define CT_COLOR_(_where,_color)    CT_ESC #_where ";5;" + std::to_string(_color) + "m"
#define CT_COLOR_FOREGROUND(_color) CT_COLOR_(38, _color)
#define CT_COLOR_BACKGROUND(_color) CT_COLOR_(48, _color)

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
