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

typedef enum {START_ROOM, END_ROOM, MID_ROOM} roomPos;
 
struct room {
	char *name;
	roomPos position;
};

int main(){
	//	Create 7 room files
		// in a directory called holkeboj.rooms.<pid>
	
	// Read room files into memory
	
	
	// Begin user interaction
	printf("Let the advetures begin!\n");
	int playing = 1;
	int stepCount = 0;
	struct room currentRoom;
	// SET CURRENT ROOM EQUAL TO START ROOM
	
	
	while (playing == 1) {
			//print current room status
		printf("CURRENT LOCATION: ");
		//PRINT CURRENT ROOM NAME
		printf("\nPOSSIBLE CONNECTIONS: ");
		//PRINT POSSIBLE CONNECTIONS
		printf(".\n");
		printf("WHERE TO? >");
		
		stepCount++;
		playing = 0;
	}
	
	return 0;
}