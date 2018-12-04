
// Source code from: http://www.paulgriffiths.net/program/c/srcs/curhellosrc.html

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>
#include <string.h>

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
    id_string[5] = '\0';
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
	    mvaddstr(14, 33, "User does not exist please enter new ID.");
	    mvaddstr(13, 33, "Enter School ID: ");
            refresh();
	    rewind(fps);
	    rewind(fpt);
	}
    }
    } while(signed_in == 0);

    *id_check = *id_string;
	
    if(isTeacher == 1){
	FILE *fpc = fopen(strcat(id_string, ".txt"), "r");
	*id_string = *id_check;
	Teacher * teacher = malloc(sizeof(Teacher));
	long lSize;
	char * buffer;

	fseek(fpc, 0L, SEEK_END);
	lSize = ftell(fpc);
	rewind(fpc);

	buffer = calloc(1, lSize+1);
	if(fread(buffer, lSize, 1, fpc) != 1){
	    free(buffer);
	    exit(1);
	}
	fclose(fpc);

	/*DO NOT DELETE
	erase();
	int place = 30;
	char * choice = strtok(buffer, "\n");
	while(choice != NULL){
	    mvaddstr(place++, 15, choice);
	    choice = strtok(NULL, "\n");
	}*/
    }
    else{
	FILE *fpg = fopen("grades.txt", "r");
	Student * student = malloc(sizeof(Student));
	long lSize;
	char * buffer;

	fseek(fpg, 0L, SEEK_END);
	lSize = ftell(fpg);
	rewind(fpg);

	buffer = calloc(1, lSize+1);
	if(fread(buffer, lSize, 1, fpg) != 1){
		free(buffer);
		exit(1);
	}
	fclose(fpg);

	char * line = strtok(buffer, "\n");
	int foundStudent = 0;
	int firstSemester = 1;
	int classCount = 0;
	while(line != NULL){
	    if(strlen(line) == 5){
		if(strcmp(line, id_string) == 0){
		    foundStudent = 1;
		}
		else if(foundStudent == 1){
		    break;
		}
	    }
	    else if(strlen(line) == 4){
		if(firstSemester){
		    student->semester->enrolled = 1;
		    if(classCount == ){

		    }
		}
	    }
	    else{

	    }
	    line = strtok(NULL, "\n");
	}
    }

	//TempList * tempList = malloc(sizeof(TempList));
	//TempList * list = tempList;
	/*while(fscanf(fpc, "%s", buffer) != EOF){
		strcpy(tempList->string, buffer);
		tempList->next = malloc(sizeof(TempList));
		tempList = tempList->next;
	}*/
	//tempList = list;
	
	//*teacher->classes = realloc(teacher->classes, sizeof(teacher->classes) * count);
	/*while(list->next != NULL){
	    char * curClass[1];
	    if(strlen(tempList->string) != 5){
		strcpy(curClass, tempList->string);
		mvaddstr(5,5,tempList->string);
	    }
	    else{
		if(strcmp(id_string, tempList->string) == 0){
		    *teacher->classes[position] = *curClass;
		    position++;
		}
	    }
	    list = list->next;
	}
	mvaddstr(2,2,teacher->classes[1]);*/
   
    mvaddstr(15, 33, id_string);
    mvaddstr(16, 33, firstName);
    mvaddstr(17, 33, lastName);
    refresh();
    sleep(60);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
