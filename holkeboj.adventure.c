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
	mkdir(dir_name,S_IRWXU | S_IRWXG | S_IRWXO);
		/* create room files */
	int i;
	char filename[7] = "room"; 
	char filedir[25];
	char *gameRooms[7];
	int roomsPicked[10];
	
	//Assign start and end rooms by index
	int startRoom = rand() % 7;
	printf("%d", startRoom);
	int endRoom = rand() % 7;
	while (startRoom == endRoom) {
		endRoom = rand() % 7;
	}
	printf("%d", endRoom);
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
		printf("Selected %d ", randNum);
		char filenum[2];
		sprintf(filenum, "%d\0", i);
		strcat(filename, filenum);
		/* create file  */
		strcpy(filedir, dir_name);
		strcat(filedir, filename);
		printf("%s\n",&roomNames[randNum]);
		FILE *fp;
		fp = fopen(filedir,"w");
		fprintf(fp,"ROOM NAME: %s\n", &roomNames[randNum]);
		gameRooms[i] = roomNames[randNum];
		printf("%s\n",gameRooms[i]);
		
		//connections
		
		//room type
		// if (randNum == startRoom) {
		// 	fprintf(fp,"ROOM TYPE: %s\n", "START_ROOM");
		// }
		// else if (randNum == endRoom) {
		// 	fprintf(fp,"ROOM TYPE: %s\n", "END_ROOM");
		// }
		// else {
		// 	fprintf(fp,"ROOM TYPE: %s\n", "MID_ROOM");
		// }
		fclose(fp);
		memset(filedir,0,25);
	}
	
	//connections
	int possible_connections[21][2];
	possible_connections[0][0] = 0;
	possible_connections[0][1] = 1;
	possible_connections[1][0] = 0;
	possible_connections[1][1] = 2;
	possible_connections[2][0] = 0;
	possible_connections[2][1] = 3;
	possible_connections[3][0] = 0;
	possible_connections[3][1] = 4;
	possible_connections[4][0] = 0;
	possible_connections[4][1] = 5;
	possible_connections[5][0] = 0;
	possible_connections[5][1] = 6;
	possible_connections[6][0] = 1;
	possible_connections[6][1] = 2;
	possible_connections[7][0] = 1;
	possible_connections[7][1] = 3;
	possible_connections[8][0] = 1;
	possible_connections[8][1] = 4;
	possible_connections[9][0] = 1;
	possible_connections[9][1] = 5;
	possible_connections[10][0] = 1;
	possible_connections[10][1] = 6;
	possible_connections[11][0] = 2;
	possible_connections[11][1] = 3;
	possible_connections[12][0] = 2;
	possible_connections[12][1] = 4;
	possible_connections[13][0] = 2;
	possible_connections[13][1] = 5;
	possible_connections[14][0] = 2;
	possible_connections[14][1] = 6;
	possible_connections[15][0] = 3;
	possible_connections[15][1] = 4;
	possible_connections[16][0] = 3;
	possible_connections[16][1] = 5;
	possible_connections[17][0] = 3;
	possible_connections[17][1] = 6;
	possible_connections[18][0] = 4;
	possible_connections[18][1] = 5;
	possible_connections[19][0] = 4;
	possible_connections[19][1] = 6;
	possible_connections[20][0] = 5;
	possible_connections[20][1] = 6;

	
	int chosen_connections[21];
	int num_of_connections[6];
	int c;
	for (c = 0; c < 21; c++) {
		chosen_connections[c] = 0;
	}
	int randConn;
	int still_connecting = 1;
	while (still_connecting == 1) {
		int r;
		int conn_found = 0;
		int conn_index;
		randConn = rand() % 21;
		for (r=0; r<21; r++) {
			if (chosen_connections[r] == 1) {
				continue;
			}
			else {
				conn_found = 1;
				conn_index = r;
			}
		}
		if (conn_found == 1) {
			chosen_connections[conn_index] = 1;
		}
		else {
			continue;
		}
		
		int room1;
		int room2;
		//increment num_of_connections
		for (r=0; r<21; r++) {
			if (chosen_connections[r] == 1) {
				room1 = possible_connections[r][0];
				room2 = possible_connections[r][1];
				num_of_connections[room1]++;
				num_of_connections[room2]++;
			}
		}
		
		//check num of connections
		still_connecting = 0;
		for (r=0; r<21; r++) {
			if (chosen_connections[r] == 1) {
				room1 = possible_connections[r][0];
				room2 = possible_connections[r][1];
				if (num_of_connections[room1] < 3 || num_of_connections[room2] < 3) {
					still_connecting = 1;
				}				
			}
		}
	}
	for (c = 0; c < 21; c++) {
		if (chosen_connections[c] == 1) {
			printf("Connection %d: %d connects to %d\n",c,possible_connections[c][0],possible_connections[c][1]);
		}
	}
	
	// Write connections to files
	char filename2[7] = "room";
	for (i = 0; i < 7; i++) {
		/* create filename */
		char filenum[2];
		sprintf(filenum, "%d\0", i);
		strcat(filename2, filenum);
		/* create file  */
		strcpy(filedir, dir_name);
		strcat(filedir, filename2);
		FILE *fp;
		fp = fopen(filedir,"a");
		
		//connections
		int currentRoom = i;
		int connCount = 1;
		int c;
		int room1;
		int room2;
		for (c = 0; c < 21; c++) {
			if (chosen_connections[c] == 1) {
				room1 = possible_connections[c][0];
				room2 = possible_connections[c][1];
				if (currentRoom == room1) {
					fprintf(fp,"CONNECTION %d: %s\n", connCount, gameRooms[room2]);
					connCount++;			
				}
				else if (currentRoom == room2) {
					fprintf(fp,"CONNECTION %d: %s\n", connCount, gameRooms[room1]);
					connCount++;					
				}
			}
		}

		fclose(fp);
		memset(filedir,0,25);
	}
	
	//append room types
	char filename3[7] = "room";
	for (i = 0; i < 7; i++) {
		char filenum[2];
		sprintf(filenum, "%d\0", i);
		strcat(filename3, filenum);
		/* create file  */
		strcpy(filedir, dir_name);
		strcat(filedir, filename3);
		FILE *fp;
		fp = fopen(filedir,"a");
		//room type
		if (i == startRoom) {
			fprintf(fp,"ROOM TYPE: %s\n", "START_ROOM");
		}
		else if (i == endRoom) {
			fprintf(fp,"ROOM TYPE: %s\n", "END_ROOM");
		}
		else {
			fprintf(fp,"ROOM TYPE: %s\n", "MID_ROOM");
		}	
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
	for (i=0; i<21; i++) {
		printf("%d",chosen_connections[i]);
	}
	return 0;
}