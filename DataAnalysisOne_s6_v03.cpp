// Header Files 
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global Constants 

   // title controls
   const int SCREEN_WIDTH = 79;
   const int HALF_SCREEN_HEIGHT = 9;
   const int MESSAGE_BLOCK_SIZE = 40;
   const bool SHOW_UNDERLINE = true;
   const bool NO_UNDERLINE = false;
   const bool PRE_ENDLINE = true;
   const bool POST_ENDLINE = true;
   const bool NO_PRE_ENDLINE = false;
   const bool NO_POST_ENDLINE = false;

   // display controls
   const int TWOBAR_DIVIDER_SPACES = 2;
   const int TWOBAR_WIDTH = 5;
   const int THREEBAR_DIVIDER_SPACES = 1;
   const int THREEBAR_WIDTH = 4;
   const int FOURBAR_DIVIDER_SPACES = 1;
   const int FOURBAR_WIDTH = 3;
   const int FIVEBAR_DIVIDER_SPACES = 1;
   const int FIVEBAR_WIDTH = 2;
   const int VERT_BLOCK_WIDTH = 19;
   const int HORIZ_BLOCK_WIDTH = 60;

   // character constants
   const char SPACE = ' ';
   const char PIPE = '|';
   const char COLON = ':';
   const char UNDERLINE_CHAR = '=';
   const char BAR_GRAPH_CHAR = '*';
   const char ENDLINE_CHAR = '\n';

   // program limits
   const int MIN_NUMBER_OF_BARS = 2;
   const int MAX_NUMBER_OF_BARS = 5;
   const int MEDIUM_TEXT_SIZE = 50;

   // string constants
   const string MAIN_GRAPH_TITLE = "RESEARCH DATA ANALYSIS";
   const string VERT_GRAPH_TITLE = "Dates";
   const string HORIZ_GRAPH_TITLE = "Averages of Data Samples";
   
// Function Prototypes 

/*
Name: printTitle
Process: accepts title text, prints title centered in given block size,
         then prints underline if directed,
         can have optional pre- or post- endline
Function Input/Parameters: title text (string), block size (int),
                           underline, pre-endline, post-endline flag (bool),
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: title displayed as specified
Dependencies: iostream I/O tools, string tools, printCharacters
*/
void printTitle( const string &title, int blockSize, 
                       bool underlineFlag, bool preEndline, bool postEndline );

/*
Name: showProgramDescription
Process: describes what the program accomplishes
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output: shows description as specified
Dependencies: iostream I/O tools, printTitl
*/
void showProgramDescription();

/*
Name: promptForFileName
Process: prompts user for file name, acquires, returns
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: file name (string)
Device Input/Keyboard: user enters file name
Device Output/Monitor: user is prompted for file name
Dependencies: iostream I/O tools
*/
string promptForFileName();

/*
Name: getAverages
Process: accepts file name, opens file, inputs numbers from lists,
         calculates average for each list found,
         returns number of lists found, and passes averages back
Function Input/Parameters: file name (string)
Function Output/Parameters: collection dates (string), averages (double)
Function Output/Returned: number of data items found
Device Input/HD: numbers uploaded as specified
Device Output: none
Dependencies: iostream I/O tools, string tools, printCharacters
*/
int getAverages( string &fileName, string &colDat1, string &colDat2, 
                   string &colDat3, string &colDat4, string &colDat5, 
                    double &avg1, double &avg2, double &avg3, 
                      double &avg4, double &avg5 );

/*
Name: getOneAverage
Process: accepts file name, opens file, inputs numbers from lists,
         calculates average for each list found,
         returns number of lists found, and passes averages back
Function Input/Parameters: file name (string)
Function Output/Parameters: collection dates (string), averages (int)
Function Output/Returned: number of data items found
Device Input/HD: numbers uploaded as specified
Device Output: none
Dependencies: iostream I/O tools, string tools, printCharacters
*/
double getOneAverage( ifstream &inFileStream, int numOfNums );

/*
Name: showSystemMessage
Process: displays message with leading and trailing endlines
Function Input/Parameters: message (string)
Function Output/Parameters: none
Function Output/Returned: random value (int)
Device Input: none
Device Output/Monitor: message displayed as specified
Dependencies: printTitle
*/
void showSystemMessage( const string &message );

/*
Name: showErrorMessage
Process: clears screen, displays error message with leading 
         and trailing endlines and underline, holds program to continue
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: message displayed as specified
Dependencies: printTitle
*/
void showErrorMessage();

/*
Name: checkDataInLimits
Process: checks to see if the number of bars is within
         specified limits MIN_NUMBER_OF_BARS < limit < MAX_NUMBER_OF_BARS
Function Input/Parameters: number of bars (int)
Function Output/Parameters: none
Function Output/Returned: result of specified test (bool)
Device Input: none
Device Output: none
Dependencies: none
*/
bool checkDataInLimits( int number );

/*
Name: promptForContinue
Process: asks if user wants to run program again, or quit
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: user enters response
Device Output/Monitor: user is prompted for response
Dependencies: iostream I/O tools
*/
bool promptForContinue();

/*
Name: showProgramEnd
Process: clears screen, show program end text, center screen
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: program end display, as specified
Dependencies: iostream I/O tools, printTitle, system/cls, system/pause
*/
void showProgramEnd();

/*
Name: displayGraphTitles
Process: displays graph main, vertical, and horizontal titles
Function Input/Parameters: three graph titles (string
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: displays titles as specified
Dependencies: iostream I/O tools, printTitle, system/cls
*/
void displayGraphTitles( const string &mainTitle, 
                           const string &vertTitle, const string &horizTitle );

/*
Name: displayGraphBars
Process: displays the number of bars specified, as follows:
         2 bars are width 5, 3 bars are width 4, 4 bars are width 3,
         5 bars are width 2
Function Input/Parameters: number of bars and bar lengths (int),
                           individual bar legends (string)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: bar graphs displayed as shown
Dependencies: iostream I/O tools, displayDividerSpaces, displayBar
*/
void displayGraphBars( int numBars, int barLength_1, int barLength_2, 
                        int barLength_3, int barLength_4, int barLength_5,
                         const string &barLegend_1, const string &barLegend_2, 
                          const string &barLegend_3, const string &barLegend_4, 
                           const string &barLegend_5 );

/*
Name: displayDividerSpaces
Process: display dummy spaces between bar graphs with vertical axis bar
Function Input/Parameters: number of divider spaces to show
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: divider spaces displayed as specified
Dependencies: displayLegend
*/
void displayDividerSpaces( int numDividerSpaces );

/*
Name: displayLegend
Process: displays legend or empty spaces centered with vertical axis bar,
         allows for end line if flag is set
Function Input/Parameters: legend text (string), Boolean endline flag
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: legend line displayed as specified
Dependencies: printTitle, iostream I/O tools
*/
void displayLegend( const string &legend, bool postEndLine );

/*
Name: displayBar
Process: displays graph bars, given width and length,
         including legend in first line,
         and legend offset in succeeding lines
Function Input/Parameters: bar legend (string), bar width and length (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: graph bar displayed as specified
Dependencies: displayLegend, iostream I/O tools
*/
void displayBar( const string &barLegend, int width, int length );

/*
Name: printCharacters
Process: displays given character a given number of times
Function Input/Parameters: display character (char), 
                           number of times to display (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: characters displayed as necessary
Dependencies: iostream I/O tools
*/
void printCharacters( int numTimes, char dispChar );

/*
Name: printEndLines
Process: outputs a given number of endlines
Function Input/Parameters: number of endlines (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input: none
Device Output/Monitor: endlines output as specified
Dependencies: iostream I/O tools
*/
void printEndLines( int numEndLines );

// Main Function 
int main()
   {
    // initialize program

       // initialize variables
       string fileName;
       int numberOfDataItems;
       string collDate_1, collDate_2, collDate_3, collDate_4, collDate_5;
       double average_1, average_2, average_3, average_4, average_5;

   // start programloop
   do
      {
       // clear screen
          // function: system/cls
       system( "cls" );

       // show title
          // function: printTitle
       printTitle( "DATA ANALYSIS PROGRAM", 
                   SCREEN_WIDTH, SHOW_UNDERLINE, PRE_ENDLINE, POST_ENDLINE );

       // show program description
          // function: showProgramDescription
       showProgramDescription();

       // get file name
          // function: iostream <<, >>
       fileName = promptForFileName();

       // acquire data, and find averages

          // show message, beginning inputting, averaging process
             // function: showSystemMessage
          showSystemMessage( 
                       "Begin inputting and processing data from file . . ." );

          // get averages
             // function: getAverages
          numberOfDataItems = getAverages( fileName, collDate_1, collDate_2, 
                                      collDate_3, collDate_4, collDate_5, 
                                            average_1, average_2, average_3, 
                                                       average_4, average_5 );

          // show message, ending averaging process
             // function: showSystemMessage
          showSystemMessage( ". . . End processing data" );

       // check for good data
          // function: checkDataInLimits
       if( checkDataInLimits( numberOfDataItems ) )
          {
           // display graph

              // display titles and horizontal axis
                 // function: displayGraphTitles
              displayGraphTitles( MAIN_GRAPH_TITLE, 
                                          VERT_GRAPH_TITLE, HORIZ_GRAPH_TITLE );

              // display bar graphs
                 // function: displayGraphBars
              displayGraphBars( numberOfDataItems, average_1, average_2, 
                                average_3, average_4, average_5, collDate_1, 
                                collDate_2, collDate_3, collDate_4, collDate_5 );
          }

       // otherwise, assume no data
       else
          {
           // show error message
              // function: showErrorMessage
           showErrorMessage();
          }
      }
    while( promptForContinue() );
    // end loop, with continue program flag
       // function: promptForContinue

    // end program

       // show program end
          // function: showProgramEnd
       showProgramEnd();

       // return success
       return 0;
   }

// Supporting Function Implementation

void printTitle( const string &title, int blockSize, 
                       bool underlineFlag, bool preEndline, bool postEndline )
   {
    // initialize function/variables
    int strLen, preSpaceCount, postSpaceCount;

    // find length of title
       // function: string .length
    strLen = title.length();

    // find pre-title space length
    preSpaceCount = ( blockSize / 2 ) - ( strLen / 2 );

    // find post-title space length
    postSpaceCount = blockSize - preSpaceCount - strLen;

    // check for pre-endline flag
    if( preEndline )
       {
        // display endline
           // function: iostream <<
        cout << endl;
       }

    // display pre-title spaces
       // function: printCharacters
    printCharacters( preSpaceCount, SPACE );

    // display title
       // function: iostream <<
    cout << title;

    // display post-title spaces
       // function: printCharacters
    printCharacters( postSpaceCount, SPACE );

    // check for underline flag
    if( underlineFlag )
       {
        // display endline
           // function: iostream <<
        cout << endl;

        // display pre-title spaces
           // function: printCharacters
        printCharacters( preSpaceCount, SPACE );

        // display underline, with two endlines
           // function: printCharacters, iostream <<
        printCharacters( strLen, UNDERLINE_CHAR );
        cout << endl;
       }

    // check for post endline flag
    if( postEndline )
       {
        // display endline
           // function: iostream <<
        cout << endl;
       }
   }

void showProgramDescription()
   {
    // initialize function/variables
       // none

    // show display
       // function: printTitle, iostream <<
    printTitle( "Program uploads specified data file,", 
                 SCREEN_WIDTH, NO_UNDERLINE, NO_PRE_ENDLINE, POST_ENDLINE );
    printTitle( "acquires data and finds group data averages,", 
                 SCREEN_WIDTH, NO_UNDERLINE, NO_PRE_ENDLINE, POST_ENDLINE );
    printTitle( "and then shows bar graphs of data averages.", 
                   SCREEN_WIDTH, NO_UNDERLINE, NO_PRE_ENDLINE, POST_ENDLINE );
    cout << endl;
   }

string promptForFileName()
   {
    // initialize function/variables
    string fileNameString;

    // prompt user for file name
       // function: iostream >>
    cout << "Enter file name for data: ";

    // get user input
       // function: iostream <<
    cin >> fileNameString;

    // return user input;
    return fileNameString;
   }
   
void displayGraphTitles( const string &mainTitle, 
                           const string &vertTitle, const string &horizTitle )
   {
    // initialize function/variables
       // none

    // clear screen
       // function: system/cls
    system( "cls" );

    // display main title
       // function: printTitle
    printTitle( mainTitle, SCREEN_WIDTH, SHOW_UNDERLINE, 
                                                   PRE_ENDLINE, POST_ENDLINE );

    // display vertical legend title
       // function: printTitle
    printTitle( vertTitle, VERT_BLOCK_WIDTH, NO_UNDERLINE, 
                                             NO_PRE_ENDLINE, NO_POST_ENDLINE );

    // display horizontal legend title
       // function: printTitle
    printTitle( horizTitle, HORIZ_BLOCK_WIDTH, NO_UNDERLINE,
                                             NO_PRE_ENDLINE, NO_POST_ENDLINE ); 

    // display end line
       // function: iostream <<  
    cout << endl;
   }

void displayGraphBars( int numBars, int barLength_1, int barLength_2, 
                        int barLength_3, int barLength_4, int barLength_5,
                         const string &barLegend_1, const string &barLegend_2, 
                          const string &barLegend_3, const string &barLegend_4, 
                           const string &barLegend_5 )
   {
    // initialize function/variables
    int barDividerSpaces, barWidth, barLength, barCount;
    string barLegend;

    // display divider line row

       // display offset spaces
          // function: displayLegend
       displayLegend( "", NO_POST_ENDLINE );

       // display horizontal axis
          // function: iostream <<
       cout << "----|----|----|----|----|----|----|----|----|----|"
            << endl;

    // get settings for bars and divider spaces displayed

       // select on number of bars
       switch( numBars )
          {
           // case of 2 bars
           case 2:
              // set bar divider spaces
              barDividerSpaces = TWOBAR_DIVIDER_SPACES;

              // set bar width
              barWidth = TWOBAR_WIDTH;

              // break
              break;

           // case of 3 bars
           case 3:
              // set bar divider spaces
              barDividerSpaces = THREEBAR_DIVIDER_SPACES;

              // set bar width
              barWidth = THREEBAR_WIDTH;

              // break
              break;

           // case of 4 bars
           case 4:
              // set bar divider spaces
              barDividerSpaces = FOURBAR_DIVIDER_SPACES;

              // set bar width
              barWidth = FOURBAR_WIDTH;

              // break
              break;

           // assume 5 bars
           default:
              // set bar divider spaces
              barDividerSpaces = FIVEBAR_DIVIDER_SPACES;

              // set bar width
              barWidth = FIVEBAR_WIDTH;

              // break
              break;
          }
       // end selection

    // display first two bars

       // loop across all bars
       for( barCount = 1; barCount <= numBars; barCount++ )
          {
           // select on which bar to display
           switch( barCount )
              {
               // first bar
               case 1:
                  // set bar legend and length to current data
                  barLegend = barLegend_1;
                  barLength = barLength_1;
                  break;

               // second bar
               case 2:
                  // set bar legend and length to current data
                  barLegend = barLegend_2;
                  barLength = barLength_2;
                  break;

               // third bar
               case 3:
                  // set bar legend and length to current data
                  barLegend = barLegend_3;
                  barLength = barLength_3;
                  break;

               // fourth bar
               case 4:
                  // set bar legend and length to current data
                  barLegend = barLegend_4;
                  barLength = barLength_4;
                  break;

               // fifth bar
               case 5:
                  // set bar legend and length to current data
                  barLegend = barLegend_5;
                  barLength = barLength_5;
                  break;
              }

           // display divider spaces
              // function: displayDividerSpaces
           displayDividerSpaces( barDividerSpaces );

           // display bar
              // function: displayBar
           displayBar( barLegend, barWidth, barLength );
          }
   }

int getAverages( string &fileName, string &colDat1, string &colDat2, 
                   string &colDat3, string &colDat4, string &colDat5, 
                    double &avg1, double &avg2, double &avg3, 
                      double &avg4, double &avg5 )
   {
    // initialize function/variables
    ifstream fileInStream;
    int numDataSets, numItems, dataSetCtr;
    string dateString, dateNumber, month, year;

    // clear, open file
       // function: fstream .clear, .open
    fileInStream.clear();
    fileInStream.open( fileName.c_str() );

    // ignore first two lines
       // function: fstream .ignore
    fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );
    fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );

    // get number of data sets
       // function: fstream .ignore, >>
    fileInStream.ignore( MEDIUM_TEXT_SIZE, COLON );
    fileInStream >>  numDataSets;
    fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );

    // ignore next two lines
       // function: fstream .ignore
    fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );
    fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );

    // loop across all data

        // start loop, up to number of data sets
        for( dataSetCtr = 1; dataSetCtr <= numDataSets; dataSetCtr++ )
           {
            // get data collection date

               // get date number
                  // function: fstream .ignore, fstream >>
            fileInStream.ignore( MEDIUM_TEXT_SIZE, COLON );
            fileInStream >> dateNumber;

               // get month
                  // function: fstream >>
               fileInStream >> month;

               // get year
                  // function: fstream >>, .ignore
               fileInStream >> year;
               fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );
               dateString = dateNumber + SPACE + month + SPACE + year;    

            // get number of items in data set
               // function: fstream .ignore, fstream >>
            fileInStream.ignore( MEDIUM_TEXT_SIZE, COLON );
            fileInStream >> numItems;
            fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );

            // ignore "data collected" line
               // function: fstream .ignore
            fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );

            // load and add data items

            // select on which average to calculate
            switch( dataSetCtr )
               {
                // first data set case
                case 1:
                   // get date, calculate average for first data set
                      // function: getOneAverage
                   colDat1 = dateString;
                   avg1 = getOneAverage( fileInStream, numItems );
                   break;

                // second data set case
                case 2:
                   // calculate average for second data set
                      // function: getOneAverage
                   colDat2 = dateString;
                   avg2 = getOneAverage( fileInStream, numItems );
                   break;

                // third data set case
                case 3:
                   // calculate average for third data set
                      // function: getOneAverage
                   colDat3 = dateString;
                   avg3 = getOneAverage( fileInStream, numItems );
                   break;

                // fourth data set case
                case 4:
                   // calculate average for fourth data set
                      // function: getOneAverage
                   colDat4 = dateString;
                   avg4 = getOneAverage( fileInStream, numItems );
                   break;

                // fifth data set case
                default:
                   // calculate average for fifth data set
                      // function: getOneAverage
                   colDat5 = dateString;
                   avg5 = getOneAverage( fileInStream, numItems );
                   break;
               }          

            // ignore end of data line, and divider line
               // function: fstream .ignore
            fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );
            fileInStream.ignore( MEDIUM_TEXT_SIZE, ENDLINE_CHAR );
           }        
    // end loop
    
    // close data file
       // function: fstream .close
    fileInStream.close();

    // return number of data sets
    return numDataSets;
   }

double getOneAverage( ifstream &inFileStream, int numOfNums )
   {
    // initialize function/variables
    
       // initialize working sum to zero
       double workingSum = 0.0000;

       // declare other variables
       int dataItemsCtr, dataItem;
       char dummyChar;

    // check for empty array
    if( numOfNums == 0 )
       {
        // return zero
        return 0;
       }

    // start loop, up to number of data items
    for( dataItemsCtr = 1; dataItemsCtr <= numOfNums; dataItemsCtr++ )
       {
        // get data value
           // function: fstream >>
        inFileStream >> dataItem;

        // add item to working sum
        workingSum += dataItem;

        // check for not last item
        if( dataItemsCtr != numOfNums )
           {
            // get comma from data stream
               // function: fstream >>
            inFileStream >> dummyChar;
           }
       }
    // end loop

    // return calculated average
    return workingSum / numOfNums;
   }

void showSystemMessage( const string &message )
   {
    // initialize function/variables
       // none

    // display message with leading and ending endlines
       // function: printTitle
    printTitle( message, MESSAGE_BLOCK_SIZE, NO_UNDERLINE, 
                                                  PRE_ENDLINE, POST_ENDLINE );
   }

void showErrorMessage()
   {
    // initialize function/variables
       // none

    // clear screen
       // function: system/cls
    system( "cls" );

    // show title
       // function: printTitle
    printTitle( "DATA ANALYSIS PROGRAM", 
                   SCREEN_WIDTH, SHOW_UNDERLINE, PRE_ENDLINE, POST_ENDLINE );

    // drop message down
       // function: iostream <<
    cout << endl << endl;

    // show message
       // function: printTitle
    printTitle( "ERROR: Data not found, Program Aborted.", SCREEN_WIDTH, 
                                  SHOW_UNDERLINE, PRE_ENDLINE, POST_ENDLINE );

    // make vertical spaces
       // function: iostream <<
    cout << endl << endl;
   }

bool checkDataInLimits( int number )
   {
    // initialize function/variables
       // none

    // return value tested in limits
    return ( number <= MAX_NUMBER_OF_BARS && number >= MIN_NUMBER_OF_BARS );
   }

bool promptForContinue()
   {
    // initialize function/variables
    char userResponse;

    // show user prompt
       // function: iostream <<
    cout << endl << "Continue program (y/n)? ";

    // get user input
       // function: iostream >>
    cin >> userResponse;

    // return user response result
    return ( userResponse == 'Y' || userResponse == 'y' );
   }

void showProgramEnd()
   {
    // initialize function/variables
       // none

    // clear screen
       // function: system/cls
    system( "cls" );

    // display vertical spaces to center text
       // function: printEndLines
    printEndLines( HALF_SCREEN_HEIGHT );

    // display program end text
       // function: printTitle
    printTitle( "END DATA ANALYSIS PROGRAM", SCREEN_WIDTH, SHOW_UNDERLINE, 
                                            NO_PRE_ENDLINE, NO_POST_ENDLINE );

    // display vertical spaces to position screen hold
       // function: printEndLines
    printEndLines( HALF_SCREEN_HEIGHT );

    // offset press any key statement
       // function: iostream <<
    cout << endl;

    // hold program for user
       // function: system/pause
    system( "pause" );
   }

void displayDividerSpaces( int numDividerSpaces )
   {
    // initialize function/variables
    int dividerCtr;

    // loop across number of divider spaces
    for( dividerCtr = 0; dividerCtr < numDividerSpaces; dividerCtr++ )
       {
        // display empty legend
           // function: displayLegend, iostream <<
        displayLegend( "", POST_ENDLINE );
       }
    // end loop
   }

void displayLegend( const string &legend, bool postEndLine )
   {
    // initialize function/variables
       // none

    // print legend
       // function: printTitle
    printTitle( legend, VERT_BLOCK_WIDTH, NO_UNDERLINE, 
                                             NO_PRE_ENDLINE, NO_POST_ENDLINE );

    // show divider pipe
       // function: iostream <<
    cout << PIPE;

    // check for post endline
    if( postEndLine )
       {
        // show endline
           // function: iostream <<
        cout << endl;
       }
   }

void displayBar( const string &barLegend, int width, int length )
   {
    // initialize function/variables
    int widthCtr, lengthCtr;
    string barString = barLegend;

    // loop across bar width
    for( widthCtr = 0; widthCtr < width; widthCtr++ )
       {
        // display empty legend
           // function: displayLegend
        displayLegend( barString, NO_POST_ENDLINE );

        // empty bar legend
        barString = "";

        // loop across bar length
        for( lengthCtr = 0; lengthCtr < length; lengthCtr++ )
           {        
            // display bar character
               // function: iostream <<
            cout << BAR_GRAPH_CHAR;
           }
       // end bar length loop

       // show endline
          // function: iostream <<
        cout << endl;        
       }
   }

void printCharacters( int numTimes, char dispChar )
   {
    // initialize function/variables
       // none

    // loop across number of characters
    while( numTimes > 0 )
       {
        // display character
           // function: iostream <<
        cout << dispChar;

        // decrement count
        numTimes--;
       }
    // end loop
   }

void printEndLines( int numEndLines )
   {
    // initialize function/variables
    int ctr;

    // loop for height of half screen
    for( ctr = 0; ctr < numEndLines; ctr++ )
       {
        // display vertical line
           // function: iostream <<
        cout << endl;
       }
    // end loop
   }









