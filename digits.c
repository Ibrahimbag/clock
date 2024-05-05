/* These functions down below display the numbers to the terminal */

#include "digits.h"
#include <ncurses.h>

void display_zero(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "██  ██");
    mvaddstr(y + 2, x, "██  ██");
    mvaddstr(y + 3, x, "██  ██");
    mvaddstr(y + 4, x, "██████");
}

void display_one(int y, int x) 
{
    mvaddstr(y, x,     "████");
    mvaddstr(y + 1, x, "  ██");
    mvaddstr(y + 2, x, "  ██");
    mvaddstr(y + 3, x, "  ██");
    mvaddstr(y + 4, x, "██████");
}

void display_two(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "    ██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "██");
    mvaddstr(y + 4, x, "██████");
}

void display_three(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "    ██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "    ██");
    mvaddstr(y + 4, x, "██████");
}

void display_four(int y, int x) 
{
    mvaddstr(y, x,     "██  ██");
    mvaddstr(y + 1, x, "██  ██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "    ██");
    mvaddstr(y + 4, x, "    ██");
}

void display_five(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "    ██");
    mvaddstr(y + 4, x, "██████");        
}

void display_six(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "██  ██");
    mvaddstr(y + 4, x, "██████");
}

void display_seven(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "    ██");
    mvaddstr(y + 2, x, "    ██");
    mvaddstr(y + 3, x, "    ██");
    mvaddstr(y + 4, x, "    ██");
}

void display_eight(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "██  ██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "██  ██");
    mvaddstr(y + 4, x, "██████");
}

void display_nine(int y, int x) 
{
    mvaddstr(y, x,     "██████");
    mvaddstr(y + 1, x, "██  ██");
    mvaddstr(y + 2, x, "██████");
    mvaddstr(y + 3, x, "    ██");
    mvaddstr(y + 4, x, "██████");
}

void display_colon(int y, int x) 
{
    mvaddstr(y + 1, x, "████");
    mvaddstr(y + 3, x, "████");
}
