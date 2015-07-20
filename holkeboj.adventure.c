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
	//	Create 7 room files
		// in a directory called holkeboj.rooms.<pid>
	char dir_name[50] = "holkeboj.rooms.";
	int pid = getpid();
	char *pidstring;
	printf("%d\n", pid);
	printf("%s\n", dir_name);
	sprintf(pidstring, "%d", pid);
	strcat(dir_name, pidstring);
	printf("%s\n", dir_name);
	// Read room files into memory
	
	
	// Begin user interaction
	printf("Let the advetures begin!\n");
	int playing = 1;
	int stepCount = 0;
	struct room currentRoom;
	// SET CURRENT ROOM EQUAL TO START ROOM
	mkdir(dir_name,S_IRWXU | S_IRWXG | S_IRWXO);
	
	while (playing == 1) {
			//print current room status
		printf("CURRENT LOCATION: ");
		//PRINT CURRENT ROOM NAME
		printf("\nPOSSIBLE CONNECTIONS: ");
		//PRINT POSSIBLE CONNECTIONS
		printf(".\n");
		printf("WHERE TO? >");
		
		//WRITE ROOM NAME TO HISTORY FILE
		stepCount++;
		playing = 0;
	}
	
	printf("\nCongratulations! You did it!\n");
	return 0;
}