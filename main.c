
// Source code from: http://www.paulgriffiths.net/program/c/srcs/curhellosrc.html

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>

int main(void) {

    WINDOW * mainwin;

    
    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
	    fprintf(stderr, "Error initialising ncurses.\n");
	    exit(EXIT_FAILURE);
    }


    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */

    mvaddstr(13, 33, "Enter School ID:");
    refresh();
    int id = 0;
    char id_string[5];
    for(int i = 0; i <= 4; i++){
	id_string[i] = getch();
    }
    mvaddstr(14, 33, id_string);
    refresh();
    sleep(1e99);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
