/*
Jack Holkeboer
CS344 Operating Systems
Instructor: Benjamin Brewster
July 20, 2015
holkeboj@onid.oregonstate.edu

compile with:
gcc –o holkeboj.adventure holkeboj.adventure.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LEN 80

typedef enum {START_ROOM, END_ROOM, MID_ROOM} roomPos;
 
struct room {
	char *name;
	roomPos position;
};

int main(){
	/*	Create 7 room files
		 in a directory called holkeboj.rooms.<pid>*/
	char dir_name[40] = "holkeboj.rooms.";
	int pid = getpid();
	char pidstring[10];
	sprintf(pidstring, "%d/", pid);
	strcat(dir_name, pidstring);
	printf("%s\n", &dir_name);
	mkdir(dir_name,S_IRWXU | S_IRWXG | S_IRWXO);
		/* create room files */
	int i;
	char filename[7] = "room";
	char filedir[25];
	for (i = 1; i < 8; i++) {
		/* create filename */
		char filenum[2];
		sprintf(filenum, "%d\0", i);
		strcat(filename, filenum);
		/* create file  */
		strcpy(filedir, dir_name);
		strcat(filedir, filename);
		printf("%s\n",filedir);
		FILE *fp;
		fp = fopen(filedir,"w");
		fprintf(fp,"TESTLINE: \n");
		fclose(fp);
		memset(filedir,0,25);
	}
	
	
	/* RUN GAME */
	printf("Let the advetures begin!\n");
	int playing = 1;
	int stepCount = 0;
	/* SET CURRENT ROOM EQUAL TO START ROOM */
	while (playing == 1) {
			/* print current room status */
		printf("CURRENT LOCATION: ");

		printf("\nPOSSIBLE CONNECTIONS: ");

		printf(".\n");
		printf("WHERE TO? >");
		
		/* WRITE ROOM NAME TO HISTORY FILE */
		stepCount++;
		playing = 0;
	}
	
	printf("\nCongratulations! You did it!\n");
	return 0;
}