#include "cPlayer.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using std::cout;
using std::fixed;
using std::setprecision;
using std::endl;
using std::setw;
using std::left;
using std::right;

int cPlayer::playerCount = 0;

cPlayer::cPlayer() {

}

cPlayer::cPlayer(const char* name, int grade, double gpa) {
	this->grade = grade;
	this->gpa = gpa;
	this->name = new char[strlen(name) + 1]();
	strcpy_s(this->name, strlen(name) + 1, name);
}

cPlayer::~cPlayer() {

}

/**************************************************************************
*	Purpose: Compares the name received by the function to the name in the
*	datamember.
*
*	Entry: If the number of players on the team is greater than zero and the
*	user selects the search funciton, then this function will be called from
*	a FOR LOOP in cSport::Search().
*
*	Exit: If strcmp returns 0, then a match has been found and this function
*	will return true, otherwise it will return false.
*
**************************************************************************/
bool cPlayer::Search(const char* name) const {
	if (strcmp(name, this->name) == 0) {
		return true;
	}

	return false;
}

/**************************************************************************
*	Purpose: Displays individual cPlayer information.
*
*	Entry: Called when the user selects 'Display all' from the menu or when
*	the	Search function returns a match, provided that there is at least one
*	player on the team.
*
*	Exit: Displays the player information in a table format.
*
**************************************************************************/
void cPlayer::Display() const {

	cout << setw(32) << left << name
		<< setw(5) << right << grade
		<< setw(6) << right << fixed << setprecision(2) << gpa 
		<< endl;
}

/**************************************************************************
*	Purpose: Frees up the memory used to store the name of the player.
*
*	Entry: Called when the program is exited from the menu.
*
*	Exit: Deletes the char* array that holds the player name.
*
**************************************************************************/
void cPlayer::FreeMemory() {
	--playerCount;
	delete[] name;
}

/**************************************************************************
*	Purpose: Displays the current player count.
*	
*	Entry: Called when the user selects Display All from the menu.
*	
*	Exit: Displays text and a number indicating the number of players
*	on the team.
*
**************************************************************************/
void cPlayer::PlayerCount() {
	cout << "\nNumber of players on the team: " << cPlayer::playerCount << endl;
}