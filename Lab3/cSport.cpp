#include "cSport.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

cSport::cSport() {
	array = nullptr;
}

cSport::~cSport() {

}

/**************************************************************************
*	Purpose: Provides the user with a menu to add players, search records by
*	name, display all players, display the number of players, and exit the
*	program.
*
*	Entry: Called from main.
*
*	Exit: Loops indefinitely until the user exits the program.
*
**************************************************************************/
void cSport::DisplayMenu() {
	while (true) {
		char choice = '\0'; // holds the user's menu choice

		cout << "\nOregon Institue of Technology";
		cout << "\nA - Add a Player";
		cout << "\nS - Search For / Display a Player";
		cout << "\nD - Display all Players";
		cout << "\nC - Display Current Count of Players";
		cout << "\nE - Exit\n";
		cout << "\nMake your choice: ";
		cin >> choice;
		choice = toupper(choice);

		switch (choice) {
		case 'A': Add(); break;
		case 'S': Search(); break;
		case 'D': List(); break;
		case 'C': DisplayCount(); break;
		case 'E': 
			for (int i(0); i < length; ++i) {
				array[i].FreeMemory();
			}

			delete[] array; 
			exit(0);
		default: cout << "\n\nInvalid choice selected. Please try again." << endl;
		}
	}
}

/**************************************************************************
*	Purpose: Allows the user to add a player record to the database.
*
*	Entry: Called from cSport::DisplayMenu after the user enters 'A'.
*
*	Exit: Takes name, grade, and GPA data from the user, then creates a new
*	player record and adds it to the array.
*
**************************************************************************/
void cSport::Add() {
	char tempName[32] = { '\0' }; // stores the player's name
	int tempGrade; // stores the player's grade
	double tempGPA; // stores the player's GPA
	cPlayer* tempArray = new cPlayer[length + 1](); // temp dynamic array

	cout << "\n\nAdd Player Menu";
	cout << "\nEnter name: ";
	cin.ignore();
	cin.getline(tempName, 32);
	cout << "Enter grade: ";
	cin >> tempGrade;
	cout << "Enter GPA: ";
	cin >> tempGPA;

	cPlayer tempPlayer(tempName, tempGrade, tempGPA); // temp player object


	for (int i(0); i < length; ++i) {
		tempArray[i] = array[i];
	}

	tempArray[length] = tempPlayer;
	++length;
	delete[] array;
	array = tempArray;

	cout << "\nRecord added!" << endl;
}

/**************************************************************************
*	Purpose: Allows the user to list all player records in a table format.
*
*	Entry: Called from cSport::DisplayMneu after the user enters 'D'.
*
*	Exit: If the number of players on the team is greater than zero, then
*	the table header and each individual player record will be displayed in
*	table form. If there are no players on the team, then a message will be
*	displayed.
*
**************************************************************************/
void cSport::List() const {
	if (length > 0) {

		cout << setw(32) << left << "\nPlayer name"
			<< setw(5) << right << "Grade"
			<< setw(6) << right << "GPA" << endl;

		for (int i(0); i < length; ++i) {
			array[i].Display();
		}
	}
	else {
		cout << "\nThere are no players on the team." << endl;
	}
}

/**************************************************************************
*	Purpose: Allows the user to search for individual records by name.
*
*	Entry: Called from cSport::DisplayMenu after the user enters 'S'.
*
*	Exit: Asks the user to enter the name of the player to search for. If the
*	number of players on the team is greater than zero, then that name is
*	passed to the bool cPlayer::Search(const char*) function. If it returns
*	true, then a table header followed by the player record is displayed in
*	table format. Otherwise a message is output stating that a match is not
*	found. If there are no players on the team, then a message is displayed.
*
**************************************************************************/
void cSport::Search() const {
	char tempName[32] = { '\0' };

	cout << "\n\nEnter the name of the player you're looking for: ";
	cin >> tempName;

	if (length > 0) {
		for (int i(0); i < length; ++i) {
			if (array[i].Search(tempName) == true) {
				cout << "\nMatch found!\n";
				cout << setw(32) << left << "\nPlayer name"
					<< setw(5) << right << "Grade"
					<< setw(6) << right << "GPA" << endl;
				array[i].Display();
				break;
			}
			else if (i == length - 1) {
				cout << "\nMatch not found." << endl;
			}
		}
	}
	else {
		cout << "\nNo players on team to search for." << endl;
	}
}

/**************************************************************************
*	Purpose: Displays the number of players on the team.
*	
*	Entry: Called from the cSport::Display menu function after the user
*	enters a 'C'.
*	
*	Exit: Function displays text and the number of players on the team.
*	
**************************************************************************/
void cSport::DisplayCount() const {
	cout << "\nNumber of players on the team: " << length << endl;
}