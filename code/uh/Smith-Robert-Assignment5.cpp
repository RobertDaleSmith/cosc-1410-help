//  Assignment 5: Functions & Parameters          COSC 1410 Mon-Thur 1PM-2:30PM 
//  By: Robert Dale Smith
//                
//  Description:  This program is a simple two player game that uses everything
//  that we have learned up to this point.
//                
//  Game Rules:   There are three stacks (A, B and C) of sticks on the table. 
//  Each stack is initialized with a random number of sticks between 3 and 10
//  (inclusive). Each player takes turns choosing a stack and taking a number 
//  of sticks form that stack. A player may take either ONE stick or TWO sticks 
//  from that (selected) stack. After a player has removed a number of sticks
//  from a stack, play is then passed to the other player. The game continues
//  as long as there are sticks in any one of the stacks.
//                 
//  Game Objective: The player who takes the last stick from the 
//  table is the winner.
//                
//  Inputs:       Stack Selected
//                Number of Sticks to Remove
//                Yes or No to Play Again
//                
//                
//  Outputs:      Random number of sticks in three stacks.
//                Requests user to input data.
//                Displays the Winner
//                Asks if users want to playa gain.
//                
#include <iostream>    //Library included for Input/Output Functions.
#include <iomanip>     //Library included for spacing and formating.
#include <ctime>       //For generating random number based on the time.

using namespace std;

//Declaring Prototypes for Functions
void initStack(int& stackAInt, int& stackBInt, int& stackCInt);
void outputStacks(int stackAInt, int stackBInt, int stackCInt);
void outputSticks(int stackAInt, int stackBInt, int stackCInt);
void setPlayer(int& playersTurnInt);
void displayPlayer(int playersTurnInt);
char getStack(int errorChkInt, char stackSelectChar);
int  getSticks(int errorChkInt, int& sticksSelectInt);
bool remove(char stackSelectChar, int sticksSelectInt, int& stackAInt, 
            int& stackBInt, int& stackCInt, int& errorChkInt);
bool gameOver(int stackAInt, int stackBInt, int stackCInt, int playersTurnInt);
bool playAgain();

//Main Program FUNCTION
int main()
{
    int  playersTurnInt, stackAInt, stackBInt, stackCInt,
         sticksSelectInt, errorChkInt;
    char stackSelectChar;
    cout << "Simple C++ Game v0.5 (2 players)\n"
         << "First player to remove all sticks Wins\n";
    do  // Loops Until user declines to play again.
    {
        initStack(stackAInt, stackBInt, stackCInt);
        playersTurnInt = 0;
        do   // Loops until the game is over.
        {
            setPlayer(playersTurnInt);
            outputStacks(stackAInt, stackBInt, stackCInt);
            displayPlayer(playersTurnInt);
            errorChkInt = 0;
            do   // Loops until the correct number of sticks is entered.
            {
                 if ( errorChkInt == 1)
                 {
                     cout << "\nYou can't remove " << sticksSelectInt
                          << " Sticks from Stack " << stackSelectChar
                          << "\nPlease try again!\n";
                 }
                 stackSelectChar =  getStack(errorChkInt, stackSelectChar);
                 sticksSelectInt = getSticks(errorChkInt, sticksSelectInt);
            }
            while (!remove(stackSelectChar, sticksSelectInt, stackAInt, 
                           stackBInt, stackCInt, errorChkInt)            );
        }
        while(!gameOver(stackAInt, stackBInt, stackCInt, playersTurnInt));
    }
    while (playAgain()); 
    return EXIT_SUCCESS;     //Ends program...
}

//Stack Initialization FUNCTION
void initStack(int& stackAInt, int& stackBInt, int& stackCInt)
{
     srand(time(NULL));
     stackAInt = rand() % 8 + 3;
     stackBInt = rand() % 8 + 3;
     stackCInt = rand() % 8 + 3;
}

//Output All Stacks FUNCTION
void outputStacks(int stackAInt, int stackBInt, int stackCInt)
{
     int spacingInt;
     if (stackAInt < 10)
     {
         spacingInt = 12;
     }
     else
     {
         spacingInt = 11;
     }
     cout << endl;
     cout << "Stack A: " << stackAInt << setw(spacingInt);
     if (stackBInt < 10)
     {
         spacingInt = 12;
     }
     else
     {
         spacingInt = 11;
     }
     cout << "Stack B: " << stackBInt << setw(spacingInt);
     cout << "Stack C: " << stackCInt << endl;
     cout << "-----------" << setw(13)
          << "-----------" << setw(13)
          << "-----------" << endl;
     outputSticks(stackAInt, stackBInt, stackCInt);
}

//Output Sticks per Stack FUNCTION
void outputSticks(int stackAInt, int stackBInt, int stackCInt)
{
     int spacingInt;
     int sticksOutInt;
     int stackXInt  = stackAInt;
     int stackXChar = 'A';
     do
     {
           for ( sticksOutInt = 1; sticksOutInt <= stackXInt; sticksOutInt++ )
           {
               cout << "|";
           }
           if ( stackXInt == 0 )
           {
               cout << "";
           }
           switch (stackXChar)
           {   
               case 'A':
                 spacingInt = 14 - stackAInt;
                 cout << setw(spacingInt);
                 stackXChar = 'B';
                 stackXInt = stackBInt;
                 break;
               case 'B':
                 spacingInt = 14 - stackBInt;     
                 cout << setw(spacingInt);
                 stackXChar = 'C';
                 stackXInt = stackCInt;
                 break;
               case 'C':
                 stackXChar = 'Z';
                 break;
           }
     }
     while(stackXChar != 'Z');
     cout << endl;
}

//Display Player FUNCTION
void displayPlayer(int playersTurnInt)
{
     cout << "Player " << playersTurnInt << "'s turn \n";
}

//Get Stack from User FUNCTION
char getStack(int errorChkInt, char stackSelectChar)
{    
     errorChkInt = 0;
     do
     {
         if(errorChkInt == 1)
         {
              cout << "\nInvalid Stack. Please Try Again!\n";
         }
         cout << "Select a Stack (A, B, C): ";
         cin >> stackSelectChar;
         stackSelectChar = toupper(stackSelectChar);
         errorChkInt = 1;
     }
     while(stackSelectChar != 'A' && 
           stackSelectChar != 'B' && 
           stackSelectChar != 'C');
     return stackSelectChar;
}

//Get Sticks from User FUNCTION
int getSticks(int errorChkInt, int& sticksSelectInt)
{
     errorChkInt = 0;
     do
     {
         if(errorChkInt == 1)
         {
              cout << "\nInvalid # of sticks. Please Try Again!\n";
         }    
         cout << "How many sticks do you want to remove (1 or 2)? ";
             cin >> sticksSelectInt;
         errorChkInt = 1;
     }
     while(sticksSelectInt != 1 && sticksSelectInt != 2 );
     return sticksSelectInt;
}

//Remove Sticks from Selected Stack FUNCTION
bool remove(char stackSelectChar, int sticksSelectInt, int& stackAInt, 
            int& stackBInt, int& stackCInt, int& errorChkInt)
{
     switch (stackSelectChar)
     {
           case 'A':
                 if (sticksSelectInt <= stackAInt)
                 {   
                     stackAInt = stackAInt - sticksSelectInt;
                     return 1;
                 }   
                 else
                 {   
                     errorChkInt = 1;
                     return 0;
                 }   
           case 'B':
                 if (sticksSelectInt <= stackBInt)
                 {   
                     stackBInt = stackBInt - sticksSelectInt;
                     return 1;
                 }   
                 else
                 {   
                     errorChkInt = 1;
                     return 0;
                 }                
           case 'C':
                 if (sticksSelectInt <= stackCInt)
                 {   
                     stackCInt = stackCInt - sticksSelectInt;
                     return 1;
                 }   
                 else
                 {   
                     errorChkInt = 1;
                     return 0;
                 }   
     }
}

//Game Over Check FUNCTION
bool gameOver(int stackAInt, int stackBInt, int stackCInt, int playersTurnInt)
{
     if (stackAInt == 0 && stackBInt == 0 && stackCInt == 0)
     {
         cout << "\n\nPlayer " << playersTurnInt << " is the Winner!!";
         return 1;
     }   
     else
     {   
         
         return 0;
     }
}

//Switch Player FUNCTION
void setPlayer(int& playersTurnInt)
{
     if (playersTurnInt != 1)
     {
         playersTurnInt = 1;
     }
     else
     {
         playersTurnInt = 2;
     }
}

//Play Again FUNCTION
bool playAgain()
{
     int sentinelInt;
     char questionChar;
     do
         {
            sentinelInt = 1;
            cout << "\n\nWould you like to play again? (Y/N) ";
            cin  >> questionChar;
            questionChar = toupper(questionChar);
            cout << "\n";
            if (questionChar == 'Y' || questionChar == 'N')
               {
                   if (questionChar == 'N')
                       {     
                           return 0;
                       }     
                   if (questionChar == 'Y')
                       {     
                           return 1;  
                       }
                   sentinelInt = 1;
               }   
            else   
               {   
                   cout << "\n Please enter only (y/n) answer.  ";
                   sentinelInt = 0;
               }
         }
         while (sentinelInt == 0); 
}
