#ifndef CPLAYER_H
#define CPLAYER_H

/******************************************************************************
*	Class: cPlayer
*	
*	Constructors:
*		cPlayer()
*			Empty ctor for use in allocating dynamic player array.
*		cPlayer(const char*, int, double)
*			Initializes datamembers with passed-in data.
*	
*	Destructors:
*		~cPlayer()
*			Not used.
*	
*	Mutators:
*		None.
*	
*	Methods:
*		bool Search(const char*) const
*			Compares the player name with the input char*.
*		void Display() const
*			Displays player data in table format.
*		void FreeMemory()
*			Deletes the player name array.	
*		
******************************************************************************/
class cPlayer {
private:
	char* name; // holds the name of the player.
	int grade; // holds the grade of the player.
	double gpa; // holds the GPA of the player.

public:
	cPlayer();
	cPlayer(const char*, int grade, double gpa);
	~cPlayer();

	static int playerCount; // static variable keeps track of # of teammates

	/**************************************************************************
	*	bool Search(const char*) const;
	*		
	*		Purpose: Compares the name received by the function to the name in 
	*		the datamember.
	*		
	*		Entry: If the number of players on the team is greater than zero 
	*		and the user selects the search funciton, then this function will 
	*		be called from a FOR LOOP in cSport::Search().
	*		
	*		Exit: If strcmp returns 0, then a match has been found and this 
	*		function will return true, otherwise it will return false.
	*		
	*	void Display() const;
	*		
	*		Purpose: Displays individual cPlayer information.
	*		
	*		Entry: Called when the user selects 'Display all' from the menu 
	*		or when the	Search function returns a match, provided that there 
	*		is at least one player on the team.
	*		
	*		Exit: Displays the player information in a table format.
	*		
	*	void FreeMemory();
	*	
	*		Purpose: Frees up the memory used to store the name of the player.
	*	
	*		Entry: Called when the program is exited from the menu.
	*	
	*		Exit: Deletes the char* array that hols the player name.
	*
	*	static void PlayerCount();
	*	
	*		Purpose: Displays the current player count.
	*	
	*		Entry: Called when the user selects Display All from the menu.
	*	
	*		Exit: Displays text and a number indicating the number of players
	*		on the team.
	*	
	**************************************************************************/

	bool Search(const char*) const;
	void Display() const;
	void FreeMemory();
	static void PlayerCount();
};
#endif