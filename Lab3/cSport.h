#ifndef CSPORT_H
#define CSPORT_H
#include "cPlayer.h"

/******************************************************************************
*	Class: cSport
*	
*	Constructors:
*		cSport()
*			Assigns the player array to nullptr.
*	
*	Destructors:
*		~cPlayer()
*			Not used.
*	
*	Mutators:
*		None.
*	
*	Methods:
*		void DisplayMenu()
*			Provides the user with a menu to add players, search records by
*			name, display all players, display the number of players, and exit 
*			the	program.		
*		void Add()
*			Allows the user to add a player record to the database.
*		void List() const
*			Allows the user to list all player records in a table format.
*		void Search() const
*			Allows the user to search for individual records by name.
*		void DisplayCount() const
*			Displays the number of players on the team.
*	
******************************************************************************/
class cSport {
private:
	cPlayer* array; // holds the array of cPlayer objects
	int length; // holds the count of players on the team

public:
	cSport();
	~cSport();

	/**************************************************************************
	*	void DisplayMenu();
	*		
	*		Purpose: Provides the user with a menu to add players, search 
	*			records by name, display all players, display the number of 
	*			players, and exit the program.
	*		
	*		Entry: Called from main.
	*		
	*		Exit: Loops indefinitely until the user exits the program.
	*		
	*	void Add();
	*		
	*		Purpose: Allows the user to add a player record to the database.
	*		
	*		Entry: Called from cSport::DisplayMenu after the user enters 'A'.
	*		
	*		Exit: Takes name, grade, and GPA data from the user, then creates 
	*		a new player record and adds it to the array.
	*		
	*	void List() const;
	*		
	*		Purpose: Allows the user to list all player records in a table 
	*		format.
	*		
	*		Entry: Called from cSport::DisplayMneu after the user enters 'D'.
	*		
	*		Exit: If the number of players on the team is greater than zero, 
	*		then the table header and each individual player record will be 
	*		displayed in table form. If there are no players on the team, 
	*		then a message will be displayed.
	*		
	*	void Search() const;
	*		
	*		Purpose: Allows the user to search for individual records by name.
	*		
	*		Entry: Called from cSport::DisplayMenu after the user enters 'S'.
	*		
	*		Exit: Asks the user to enter the name of the player to search for. 
	*		If the number of players on the team is greater than zero, then 
	*		that name is passed to the bool cPlayer::Search(const char*) function. 
	*		If it returns true, then a table header followed by the player 
	*		record is displayed in table format. Otherwise a message is output 
	*		stating that a match is not found. If there are no players on the 
	*		team, then a message is displayed.
	*		
	*	void DisplayCount() const;
	*		
	*		Purpose: Displays the number of players on the team.
	*		
	*		Entry: Called from the cSport::Display menu function after the user
	*		enters a 'C'.
	*		
	*		Exit: Function displays text and the number of players on the team.
	*		
	**************************************************************************/

	void DisplayMenu();
	void Add();
	void List() const;
	void Search() const;
	void DisplayCount() const;

};
#endif