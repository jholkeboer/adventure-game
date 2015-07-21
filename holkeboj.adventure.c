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

/* room names */
/*
const char *roomNames[10];
roomNames[0] = "Dungeon";
roomNames[1] = "Bedroom";
roomNames[2] = "Closet";
roomNames[3] = "Dining room";
roomNames[4] = "Foyer";
roomNames[5] = "Library";
roomNames[6] = "Office";
roomNames[7] = "Theater";
roomNames[8] = "Bathroom";
roomNames[9] = "Garage";
*/
char roomNames[10][MAX_LEN+1] = {"Dungeon","Bedroom","Closet","Dining room","Foyer","Library","Office","Theater","Bathroom","Garage"};  

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
	srand(pid);
	char pidstring[10];
	sprintf(pidstring, "%d/", pid);
	strcat(dir_name, pidstring);
	//mkdir(dir_name,S_IRWXU | S_IRWXG | S_IRWXO);
		/* create room files */
	int i;
	char filename[7] = "room"; 
	char filedir[25];
	char gameRooms[7][MAX_LEN+1];
	int roomsPicked[10];
	for (i = 0; i < 7; i++) {
		/* create filename */
		int randNum;
		int newRand = 0;
		while (newRand != 1) {
			int j;
			int found = 0;
			randNum = rand() % 10;
			for (j=0; j<10; j++) {
				if (roomsPicked[j] == randNum) {
					found = 1;
				}
			}
			if (found == 0) {
				newRand = 1;
			}
		}
		roomsPicked[i] = randNum;
		printf("Selected %d", randNum);
		char filenum[2];
		sprintf(filenum, "%d\0", i);
		strcat(filename, filenum);
		/* create file  */
		strcpy(filedir, dir_name);
		strcat(filedir, filename);
		printf("%s\n",&roomNames[randNum]);
		//FILE *fp;
		//fp = fopen(filedir,"w");
		//fprintf(fp,"TESTLINE: %s\n", &roomNames[randNum]);
		//fclose(fp);
		//memset(filedir,0,25);
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