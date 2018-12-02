
// Source code from: http://www.paulgriffiths.net/program/c/srcs/curhellosrc.html

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>

#include "types.h"

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

    mvaddstr(13, 33, "Enter School ID: ");
    refresh();
    FILE *fps = fopen("Names.txt", "r");
    FILE *fpt = fopen("Teachers.txt", "r");
    FILE *fpc = fopen("classList.txt", "r");
    char id_string[6];
    int signed_in = 0;
    int isTeacher = 0;
    char id_check[6];
    char firstName[30];
    char lastName[30];
    
    do {
    for(int i = 0; i <= 4; i++){
	id_string[i] = getch();
    }
    while(fscanf(fps, "%s %s %s", id_check, firstName, lastName) != EOF){
        if(strcmp(id_check, id_string) == 0){
	    signed_in = 1;
	    break;
	}
    }
    if(signed_in != 1){
	while(fscanf(fpt, "%s %s %s", id_check, firstName, lastName) != EOF){
	    if(strcmp(id_check, id_string) == 0){
		signed_in = 1;
		isTeacher = 1;
		break;
	    }
	}
	if(strcmp(id_check, id_string) != 0){
	    erase();
	    mvaddstr(14, 33, "User does not exist please enter new ID.");
	    mvaddstr(13, 33, "Enter School ID: ");
            refresh();
	    fclose(fps);
	    fclose(fpt);
	    fps = fopen("Names.txt", "r");
	    fpt = fopen("Teachers.txt", "r");
	}
    }
    } while(signed_in == 0);

    if(isTeacher){
	Teacher * teacher = malloc(sizeof(Teacher));
    }

    //mvaddstr(14, 33, id_string);
    mvaddstr(15, 33, id_check);
    mvaddstr(16, 33, firstName);
    mvaddstr(17, 33, lastName);
    refresh();
    sleep(1e99);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
