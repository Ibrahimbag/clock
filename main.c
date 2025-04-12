/* Displays clock in the terminal with ncurses */

#include "digits.h"
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if (argc == 2 && (atoi(argv[1]) < 1 || atoi(argv[1]) > 7))
    {
        fprintf(stderr, "Usage: %s [color_code (1-7)]\n", argv[0]);
        return 1;
    }
    
    /* Support unicode characters */
    setlocale(LC_ALL, "");
    
    /* Initialize ncurses */
    WINDOW *stdscr = initscr();
    nodelay(stdscr, true);
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
        set_color(atoi(argv[1]));
    }

    /* Don't close the clock until someone presses the 'q' key */
    while (getch() != 'q')
    {
        /* Get the current time */
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        /* Create a buffer to store the time in */
        char buffer[MAX_DIGIT + 1];
        snprintf(buffer, sizeof(buffer), "%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min);
        
        /* Get the size of the terminal */
        int screen_height, screen_width;
        getmaxyx(stdscr, screen_height, screen_width);

        /* Get the position to display the clock */
        int x = screen_width / 2 - 17;
        int y = screen_height / 2 - 2;

        /* Display the clock to the terminal */
        erase();
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
    }

    endwin();
    return 0;
}
