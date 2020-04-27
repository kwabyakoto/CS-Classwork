// header files
#include <iostream>
#include <fstream>

using namespace std;

// global constants

// chars
const char SPACE = ' ';
const char DASH ='-';
const char PIPE = '|';
const char PERIOD ='.';
const char SHIP = 'S';
const char DESTROY_SYMBOL = 'X';


// measurements/formatting
const int TWO_SPACES = 2;
const int THREE_SPACES = 3;
const int FOUR_SPACES = 4;
const int FIVE_SPACES = 5;
const int EIGHT_SPACES = 8;
const int NUM_OF_DASHES = 73;
const int MAX_COLUMNS = 8;
const int MAX_ROWS = 8;
const int MAX_STRING_LENGTH = 20;

// orientation codes
const int NO_ORIENTATION_CODE = 0;
const int HORIZONTAL_CODE = 1;
const int VERTICAL_CODE = 2;

// ship lengths
const int FEET_PER_SQUARE = 100;
const int AIRCRAFT_CARRIER_LENGTH = 500;
const int BATTLE_SHIP_LENGTH = 400;
const int DESTROYER_LENGTH = 300;
const int SUBMARINE_LENGTH = 200;
const int PATROL_BOAT_LENGTH = 100;


// ship name character strings
const char AIRCRAFT_CARRIER[MAX_STRING_LENGTH] = "Aircraft Carrier";
const char BATTLE_SHIP[MAX_STRING_LENGTH] = "Battle Ship";
const char DESTROYER[MAX_STRING_LENGTH] = "Destroyer";
const char SUBMARINE[MAX_STRING_LENGTH] = "Submarine";
const char PATROL_BOAT[MAX_STRING_LENGTH] = "Patrol Boat";


// function prototypes

/*
Name: printTitle
Process: prints out the program title with an underline
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: a title with an underline
Dependencies: iostream I/O tools
*/
void printTitle();

/*
Name: getBoardConfig
Process: grabs the data from the file
Function Input/Parameters:  fileName (char[])
Function Output/Parameters: boardContents (char[][])
Function Output/Returned: none
Device Input: boardContents uploaed as specified 
Device Output/Monitor: none
Dependencies: ifstream
*/
void getBoardConfig( const char fileName[], char boardContents[][ MAX_COLUMNS ] );

/*
Name: displayBoard
Process: displays data into the board
Function Input/Parameters: boardContents (char[][])
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: board contents
Dependencies: iostream I/O tools
*/
void displayBoard( char boardContents[][ MAX_COLUMNS ] );

/*
Name: printNumbers
Process: prints out grid coordinates as numbers
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: prints numbers
Dependencies: iostream I/O tools
*/
void printNumbers();

/*
Name: printDividerLine
Process: prints out a dividerLine
Function Input/Parameters:none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: divider line
Dependencies: iostream I/O tools
*/
void printDividerLine();

/*
Name: printSpacedLine
Process: prints out a line of pipe's with spaces in between 
Function Input/Parameters: isFirst (bool) 
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: table line with spaces and pipes
Dependencies: iostream I/O tools
*/
void printSpacedLine(bool isFirst);

/*
Name: printOneDataLine
Process: prints the line of a row that holds the array data at those indices
Function Input/Parameters: gameBoard (char) , currentRow (int) 
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: prints one line with data
Dependencies: iostream I/O tools
*/
void printOneDataLine( char gameBoard[][MAX_COLUMNS], int currentRow);

/*
Name: printChars
Process: prints the number of chars
Function Input/Parameters: amount (int), symbol (char)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: an amount of a certain number of chars
Dependencies: iostream I/O tools
*/
void printChars( int amount, char symbol );

/*
Name: findShip
Process: finds the location of the ship
Function Input/Parameters: (char [][])  bsBoard
Function Output/Parameters: &shipRowIndex (int) , &shipColIndex (int), &orientationCode (int) 
Function Output/Returned: shipFound (bool)
Device Input: none
Device Output/Monitor: none
Dependencies: none
*/
bool findShip(char bsBoard[][MAX_COLUMNS], int& shipRowIndex, int& shipColIndex, int& orientationCode);

/*
Name: getShipLength
Process: find the length of the ship
Function Input/Parameters: bsBoard (char [][]) , startRowIndex (int), startColIndex (int) 
Function Output/Parameters: &orientationCode (int)
Function Output/Returned: int
Device Input: NONE
Device Output/Monitor: NONE
Dependencies: NONE
*/
int getShipLength( char bsBoard[][MAX_COLUMNS] , int startRowIndex, int startColIndex, int& orientationCode);

/*
Name: destroyShip
Process: replaces the S's with X's which then destroy's the ship
Function Input/Parameters: bsBoard (char [][]) , startRowIndex (int), starColIndex (int), shipLength(int), orientationCode (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: none
Dependencies: none
*/
void destroyShip(char gameBoard[][MAX_COLUMNS] , int startRowIndex, int startColIndex, int orientationCode, int shipLength);

/*
Name: shipDestroyedMessage
Process: show message saying what ship got destroyed with its length
Function Input/Parameters: shipLength (int) 
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: mesages saying what ship got destroyed
Dependencies: iostream I/O tools
*/
void shipDestroyedMessage(int shipLength );

/*
Name: printGameOverMessage
Process: prints out the game over message
Function Input/Parameters: (int) shipLength 
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: game over message
Dependencies: iostream I/O tools
*/
void printGameOverMessage();

// main program
int main()
{
	
	// initialize program
	
		// initialize variables
		bool gameOver = false;
		bool shipExists;
		char gameBoardFile[ MAX_STRING_LENGTH ], configFile[MAX_STRING_LENGTH];
		char gameBoard[ MAX_ROWS ][ MAX_COLUMNS ],  gameConfiguration[ MAX_ROWS ][ MAX_COLUMNS ];
		int shipRowIndex = -1, shipColIndex = -1 , orientationCode;
		int counter = 0;
		int shipLength =1;

		
		// print title
			// function: printTitle
		printTitle();
	
	// get board configurations
	
		// prompt for blank board file name
			// function: iostream <<, >>
		cout << " Enter file name for game board: ";
		cin >> gameBoardFile;
		
		// get blank board configuration
			// function: getBoardConfig
		getBoardConfig( gameBoardFile, gameBoard );
		
		// prompt for configuration file name
			// function: iostream << , >>
		cout << " Enter file name for game configuration: ";
		cin >> configFile;
		
		// store game configuration
			// function: getBoardConfig
		getBoardConfig( configFile, gameConfiguration );


	// loop until all ships are destroyed
	do
	{
		// clear screen
		system("cls");

		// print title
			// function: printTitle
		printTitle();

		// display board
			// function: displayBoard
		displayBoard(gameBoard);
		
		
		if(counter > 0)
		{
			// display ship destroyed message
				// function: shipDestroyMessage
			shipDestroyedMessage(shipLength);
			
		}
		
		// increase
		counter++;

		// hold screen for user
		system("PAUSE");

		
		// find ship
			// function: findShip
		shipExists = findShip(gameConfiguration, shipRowIndex, shipColIndex, orientationCode);
				
		// check if ship found
		if(shipExists)
		{
			// get ship length
				// function: shiplength
			shipLength = getShipLength( gameConfiguration, shipRowIndex, shipColIndex, orientationCode);
			
			// destroy ship in both grids
				// function: destroyShip
			destroyShip(gameBoard, shipRowIndex, shipColIndex, orientationCode, shipLength);			
			destroyShip(gameConfiguration, shipRowIndex, shipColIndex, orientationCode, shipLength);

		}
		
		// check if ship not found
		else
		{
			// game is over
			gameOver = true;
						
		}		
	
	}
	while(!gameOver);
	
	// clear screen
	system("cls");
	
	// print game over message
		// function: printGameOverMessage
	printGameOverMessage();

	
	return 0;
}
// supporting function implementations

void printTitle()
{
		// print title
			// function: iostream <<, >>
		cout << endl << endl;
		cout << " Battleship -- Cheaters Edition" << endl;
		cout << " ==============================" << endl << endl;
}

void getBoardConfig( const char fileName[], char boardContents[][ MAX_COLUMNS ] )
{
	// initialize variable
	ifstream fin;
	int rowIndex, colIndex; 
	char data;


	// clear and open the file
		// function: fstream
	fin.clear();
	fin.open( fileName ); 

	// loop through array rows
	for( rowIndex = 0; rowIndex < MAX_COLUMNS; rowIndex++ )
	{
		// loop through array columns
		for( colIndex = 0; colIndex < MAX_ROWS; colIndex++ )
		{
			// grab data
			fin >> data;
			
			// store data in array
			boardContents[ rowIndex ][ colIndex ] = data;
		}
	}

      // close file
      fin.close();
}

void displayBoard( char checkerArray[][ MAX_COLUMNS ] )
{
    // initialize variables	
    int rowIndex;
    char letter = '@';
    bool isFirst;
	
    // print column numbers
        // function: printNumbers
    printNumbers();
    
    // loop through rows
    for(rowIndex = 0; rowIndex < MAX_ROWS; rowIndex++)
    {

        // change letter to next in alphabet 
        letter = letter+1;
        
        // print divider line
            // function: printDividerLine
        printDividerLine();
        
        // print row letter
            // function: iostream <<
        cout << letter;

        // this is the first blank line
        isFirst = true;
        
        // print a spaced line with no data in it
            // function: printSpacedLine
        printSpacedLine(isFirst);

        //print one line of data
            // function: printOneDataLine
        printOneDataLine(checkerArray, rowIndex );
      
        // this is not the first blank line
         isFirst = false;
         
        // print a spaced line with no data in it
            // function: printSpacedLine
        printSpacedLine(isFirst);
    }

    // print a divder line
	    // function: printDividerLine    
    printDividerLine();
    
}
void printNumbers()
{
	// intialize variables
	int index;
	
	// print beginning chars
		// function: printChars
	printChars(THREE_SPACES, SPACE);
	
	// loop to the number of columns
	for(index = 1; index < (MAX_COLUMNS+1); index++)
	{
		// print number with surrounding spaces
			// function: printChars, iostream <<
		printChars(FIVE_SPACES, SPACE);
		cout << index;
		printChars(THREE_SPACES, SPACE);
	}
	
	// print end line
		// function: iostream
	cout << endl;
	
}

void printDividerLine()
{
	// print out beginning spaces
		// function: printChars
	printChars(THREE_SPACES, ' ');
	
	// print out dashes
		// function: printChars
	printChars(NUM_OF_DASHES,'-');
	
	// print end line
		// function: iostream <<
	cout << endl;

}

void printSpacedLine(bool isFirst)
{
	// intialize variables
	int index;
	
	// test if this is the second spaced line being printed
	if(!isFirst)
	{
		// print beginning spaces
			// function: printChars
		printChars(THREE_SPACES, SPACE);
	}
	
	// otherwise if it is the first spaced line being printed
	else
	{
		// print beginning spaces after row letter
			// function: printChars
		printChars(TWO_SPACES, SPACE);
	}
	
	// loop to number of rows
	for(index = 0; index < MAX_ROWS; index++)
	{
		// print a pipe
			// function: iostream <<
		cout << PIPE;
		
		// print spaces
			// function: printChars
		printChars(EIGHT_SPACES, SPACE);
	}
	
	// print pipe at end of row and end line
		// function: iostream <<
	cout << PIPE << endl;
	
}

void printOneDataLine(char gameBoard[][MAX_COLUMNS], int currentRow)
{
	// intialize variables
	int index;
	
	// print beginning spaces
		// function: printChars
	printChars(THREE_SPACES,SPACE);
	
	// print beginning pipe
		// function: iostream
	cout << PIPE;
	
	// print loop through each column
	for(index = 0; index < MAX_COLUMNS; index++)
	{
		// output spaces before data
			// function: printChars
		printChars(THREE_SPACES, SPACE);
		
		// output array content
			// function: iostream
		cout << gameBoard[currentRow][index];
		
		// print out after data spaces
			// function: printChars
		printChars(FOUR_SPACES, SPACE);
		
		// print ending pipe
			// function: iostream		
		cout << PIPE;
		
	}
	
	// print endline
		// function: iostream
	cout << endl;
		
}

void printChars( int amount, char symbol )
{
    // intialize variables
    int index;

    // loop to the number of symbols
    for(  index = 0; index < amount; index++ )
    {
    	// print out required symbol
    	    // function: iostream << 
        cout << symbol;
    }
}

bool findShip( char gameConfig[][MAX_COLUMNS], int& shipRowIndex, int& shipColIndex, int& orientationCode)
{
	// intialize variables
	int rowIndex, colIndex;
	
	// loop through the grid rows
	for( rowIndex = 0; rowIndex < MAX_ROWS; rowIndex++)
	{
		// loop through the grid columns
		for( colIndex = 0; colIndex < MAX_COLUMNS; colIndex++)
		{
			// check if a ship is found
			if( gameConfig[rowIndex][colIndex] == SHIP )
			{
				// set ship found coordinates
				shipRowIndex = rowIndex;
				shipColIndex = colIndex;
				
				// check if ship has a horizontal orientation
				if( gameConfig[rowIndex][colIndex+1] == SHIP)
				{
					// set ship orientation code
					orientationCode = HORIZONTAL_CODE;
				}
				
				// check if ship has a vertical orientation
				else if( gameConfig[rowIndex+1][colIndex] == SHIP)
				{
					// set ship orientation code
					orientationCode = VERTICAL_CODE;
				}
				
				// check if ship has a vertical orientation
				else
				{
					// set ship orientation code
					orientationCode = NO_ORIENTATION_CODE;
				}
								
				// return that a ship was found
				return true;	
			} 
		}		
	}
	
	// return that no ship was found
	return false;
	
}

int getShipLength( char gameConfig[][MAX_COLUMNS] , int startRowIndex, int startColIndex, int& orientationCode)
{
	// intialize variables
	int rowIndex = startRowIndex;
	int colIndex = startColIndex;
	int length = 0;

	// test for horizontal code
	if(orientationCode == HORIZONTAL_CODE)
	{
		// loop to the end of the ship
		while(gameConfig[rowIndex][colIndex] == SHIP)		
		{
			
			// move to next column
			colIndex++;
			
			// increase length
			length++;
		}
	}
	
	// test for vertical code
	else if(orientationCode == VERTICAL_CODE)
	{
		// loop to the end of the ship
		while(gameConfig[rowIndex][colIndex] == SHIP)		
		{
			
			// move to next column
			rowIndex++;
			
			// increase length
			length++;
		}
	}
	else
	{
		// set ship length to 1 square
		length = 1;
	}
	  	  
	// calculate length in feet
	length = length*FEET_PER_SQUARE;

	// return ship length
	return length;
}

void destroyShip(char gameBoard[][MAX_COLUMNS] , int startRowIndex, int startColIndex, int orientationCode, int shipLength)
{
	
	// intialize variables
	int rowIndex = startRowIndex;
	int colIndex = startColIndex;
	
	// convert length to square units
	shipLength = shipLength/FEET_PER_SQUARE;
	
	// test for horizontal code
	if(orientationCode == HORIZONTAL_CODE)
	{
		// loop until the end of the ship
		for( colIndex = startColIndex; colIndex < (startColIndex+shipLength); colIndex++)
		{
			// change the ship character to destroy character
			gameBoard[rowIndex][colIndex] = DESTROY_SYMBOL;
		}
	}

	// test for vertical code
	else if(orientationCode == VERTICAL_CODE)
	{	
		// loop until the end of the ship
		for( rowIndex = startRowIndex; rowIndex < (startRowIndex+shipLength); rowIndex++)
		{
			// change the ship character to destroy character
			gameBoard[rowIndex][colIndex] = DESTROY_SYMBOL;
		}
	}
	
	// otherwise, ship has no orientation
	else
	{	
        // change character to destroy character
		gameBoard[rowIndex][colIndex] = DESTROY_SYMBOL;
	}
	
}

void shipDestroyedMessage(int shipLength )
{

	// output beginning ofmessage with length
		// function: iostream <<
	cout << "    Huzzah! You hit a(n) " << shipLength << " foot long ";


	// output ship type based on ship length
	switch( shipLength)
	{
		case PATROL_BOAT_LENGTH:
			
			// ship type is patrol boat
				// function: iostream
			cout << PATROL_BOAT; 
			
			break;
		
		case SUBMARINE_LENGTH:
			
			// ship type is patrol boat
				// function: iostream
			cout << SUBMARINE;
			
			break;
		
		case DESTROYER_LENGTH:

			// ship type is patrol boat
				// function: iostream
			cout << DESTROYER;
			
			break;
		
		case BATTLE_SHIP_LENGTH:

			// ship type is patrol boat
				// function: iostream		
			cout << BATTLE_SHIP;
			
			break;
		
		case AIRCRAFT_CARRIER_LENGTH:
			
			// ship type is patrol boat
				// function: iostream		
			cout << AIRCRAFT_CARRIER;
			
			break;
		
		// other
		default:
		
			break;
	
	}

	// output exclamation point with endlines
		// function: iostream <<
	cout << '!' << endl << endl;	
}

void printGameOverMessage()
{	

	// output game over message
		// function: iostream <<
	cout << endl;
	cout << "	                           GAME OVER" << endl;
	cout << "                                   =========" << endl << endl;
	cout << "              All ships are destroyed! Glory to the empire!" << endl;
}





