/*****************************************************************************
AUTHOR: Garrett Bates
DATE CREATED: October 10, 2014
LAST MODIFICATION: October 11, 2014
LAB #3
FILE NAME: MAIN.CPP

OVERVIEW
This program demonstrates my knowledge and ability to work with Classes and 
dynamic memory in C++.  The user can add and display Players to a database.

INPUT
The user can add Players to the team. Player data includes Name, Grade, and
GPA. The user can also search by name through the database.

OUTPUT
The user can display individual records through the search function, display
all the records through DisplayAll, and display the number of players on the 
team.

*****************************************************************************/

#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <crtdbg.h>
#include "cSport.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cSport goOwls;

	goOwls.DisplayMenu();

	return 0;
}
