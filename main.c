/* This program displays numbers in the terminal with ncurses */

#include "digits.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

#define MAX_DIGIT 5

void set_color(int color)
{
    init_pair(color, color, -1);
    attrset(COLOR_PAIR(color));
}

int main(int argc, char *argv[])
{
    /* Check if user used arguments correctly */
    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [color_code (1-7)]\n", argv[0]);
        return 1;
    }

    /* Support unicode characters */
    setlocale(LC_ALL, "");
    
    /* Initialize ncurses */
    WINDOW *win = initscr();
    nodelay(win, true);
    curs_set(false);
    noecho();
    if (has_colors() == true)
    {
        start_color();
        use_default_colors();
    }
    
    /* Set the terminal color. Default is white */
    if (has_colors() == true && argc == 2)
    {
        for (int i = 1; i <= 7; i++)
        {
            if (atoi(argv[1]) == i)
            {
                set_color(i);
            }
        }
    }

    /* Don't close the clock until someone presses the 'q' key */
    while (wgetch(win) != 'q')
    {
        /* Get the current time */
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        /* Get the height and width of the terminal */
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int screen_height = w.ws_row, screen_width = w.ws_col;

        /* Create a buffer to store the time in */
        char buffer[MAX_DIGIT + 1];
        snprintf(buffer, sizeof(buffer), "%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min);

        /* Display the clock to the terminal */
        erase();
        int x = (screen_width / 2 - (3 * 12 + MAX_DIGIT - 1)) + 23;
        int y = screen_height / 2 - 2;
        for (size_t i = 0; i < strlen(buffer); i++)
        {
            switch (buffer[i]) 
            {
                case '0': display_zero(y, x); break;
                case '1': display_one(y, x); break;
                case '2': display_two(y, x); break;
                case '3': display_three(y, x); break;
                case '4': display_four(y, x); break;
                case '5': display_five(y, x); break;
                case '6': display_six(y, x); break;
                case '7': display_seven(y, x); break;
                case '8': display_eight(y, x); break;
                case '9': display_nine(y, x); break;
                case ':': if (time(NULL) % 2 == 0) display_colon(y, x + 1); break;
            }
            x += 7;
        }

        /* Display the output */
        wrefresh(win);
    }

    endwin();
    return 0;
}
