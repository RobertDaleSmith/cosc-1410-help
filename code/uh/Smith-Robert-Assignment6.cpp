//  Assignment 6: Array & Functions          COSC 1410 Mon-Thur 1PM-2:30PM 
//  By: Robert D. Smith
//                
//  Description:  In this assignment, you are designing a typing practice 
//  program. For each test/practice, the user will be given a sequence of 
//  randomly generated characters (upper-case and lower-case letters only) to 
//  type. The user will be given 3 seconds to get ready before each test. The 
//  user will need to type the text of exactly the same length. (This is 
//  something that we have to live with before we talk about strings.) At the 
//  end of each test, a score is given based on the correctness of the typing 
// and the elapse time. After all the practices are completed, the program 
//  should print out the score summary on the screen.
//  
     
#include <iostream>    
#include <iomanip>     
#include <ctime>       

using namespace std;

//Function Prototypes
void countDownLine(int chLVLInt);
void sleep(unsigned int miliSecondsInt);
void genOutString(int chLVLInt, char randCharArray[]);
void getInString(int chLVLInt, char inputCharArray[]);
void errorCheckerMarker(int& errorCountInt, int chLVLInt, 
                        char randCharArray[], char inputCharArray[]);
void outputResults(int errorCountInt, int chLVLInt, char inputCharArray[]);
void typingResults(int& chLVLInt, double scoreDbl);
void dispFinalResults(int testCountInt, double testScoresArray[]);
bool practiceAgain(int testCountInt, int maxNumTurnsInt);
double elapsedTimeScore(double currentTimeDbl, double startTimeDbl);
double elapsedTimeScore(int errorCountInt, int chLVLInt, double elapsedTimeDbl);


//Global Variables
int arrayCellInt;

//Main Program FUNCTION
int main()
{   
    //Main Local Variables
    int maxNumTurnsInt = 1000, maxArraySizeInt = 1005, 
        testCountInt = 0, chLVLInt = 5;
    unsigned int miliSecondsInt;
    int errorCountInt;
    double currentTimeDbl, elapsedTimeDbl, startTimeDbl, scoreAvgDbl,
           scoreDbl=0, scoreSumDbl=0;   
    double testScoresArray[maxArraySizeInt];
    char randCharArray[maxArraySizeInt], inputCharArray[maxArraySizeInt];

    
    do {//Loop until user doesn't want to stop or if maximum turns are reached.
        
        //First line with countdown.  
        countDownLine(chLVLInt);
              
        //Second line generates random array and outputs results.
        genOutString(chLVLInt, randCharArray);
        
        //Sets Start Time to keep track of elapsed time.
        startTimeDbl = clock();
            
        //Third line for user input of the array.
        getInString(chLVLInt, inputCharArray);
        
        //Fourth line to test and display results.
         //Count errors and mark them.
         errorCheckerMarker(errorCountInt, chLVLInt, 
                            randCharArray, inputCharArray);

         //Output results
         outputResults(errorCountInt, chLVLInt, inputCharArray);

        //Fifth line to output elapsed time and score.
         //Calc elapsed time and output it.
         elapsedTimeDbl = elapsedTimeScore(currentTimeDbl, startTimeDbl);
         cout << "Elapse Time: " << fixed << setprecision(2) << elapsedTimeDbl;
        
         //Calc score and output it.
         scoreDbl = elapsedTimeScore(errorCountInt, chLVLInt, elapsedTimeDbl);
         cout << "    Score: " << scoreDbl;
        
        //Sixth line outputs results based on score.         
        typingResults(chLVLInt, scoreDbl);
         
        //Stores score for current test. Increments test count variable.
        testScoresArray[testCountInt] = scoreDbl;
        testCountInt++;
        
    } while(practiceAgain(testCountInt, maxNumTurnsInt));

    //Displaying list of scores and total average score.
    dispFinalResults(testCountInt, testScoresArray);
    
    system("PAUSE");
    return EXIT_SUCCESS;     //Ends program...
}

//Sleep FUNCTION
void sleep(unsigned int miliSecondsInt)
{
    clock_t goal = miliSecondsInt + clock();
    while (goal > clock());
}

//Count Down Line FUNCTION
void countDownLine(int chLVLInt)
{        
    int secondsLeftInt;
    cout << "Your practice will start with " << chLVLInt 
         << " characters in 3 seconds. ";
    for (secondsLeftInt = 3 ; secondsLeftInt >= 1 ; secondsLeftInt--)
    {
        cout << secondsLeftInt << ",   ";
        sleep(1000);
    }
    cout << "Start.\n";
}

//Generate and output random string of characters FUNCTION
void genOutString(int chLVLInt, char randCharArray[])
{    
    int randInt;
    char randChar;
    srand(time(NULL));
    for (arrayCellInt = 0 ; arrayCellInt < chLVLInt ; arrayCellInt++)
    {                       //Randomly selects upper case or lower case.
        randInt = rand() % 2 + 1;   
        if (randInt == 1)                  
        {
            randInt = rand() % 26 + 65;   //Sets random upper case char.
        }
        else if (randInt == 2)
        {
            randInt = rand() % 26 + 97;   //Sets random lower case char.
        }
        randChar = (char) randInt;
        randCharArray[arrayCellInt] = randChar;
    }
    
    cout << "  Testing sting: [ ";
    for (arrayCellInt = 0; arrayCellInt < chLVLInt ; arrayCellInt++)
    {
        cout << randCharArray[arrayCellInt];
    }
    cout << " ]\n";
}        
    
//Get User's Input FUNCTION
void getInString(int chLVLInt, char inputCharArray[])
{
    cout << "Please type here:  ";
    for (arrayCellInt = 0; arrayCellInt < chLVLInt ; arrayCellInt++)
    {
        cin >> inputCharArray[arrayCellInt];
    }
} 

//Error Checker & Marker FUNCTION
void errorCheckerMarker(int& errorCountInt, int chLVLInt, 
                        char randCharArray[], char inputCharArray[])
{
    errorCountInt = 0;
    for (arrayCellInt = 0; arrayCellInt < chLVLInt ; arrayCellInt++)
    {
        if (randCharArray[arrayCellInt] != inputCharArray[arrayCellInt])
        {
            errorCountInt++;
            inputCharArray[arrayCellInt] = '*';
        }
    }
}

//Output Typing Results FUNCTION
void outputResults(int errorCountInt, int chLVLInt, char inputCharArray[])
{
    if (errorCountInt > 0)
    {
        cout << "You have " << errorCountInt 
             << " errors marked as '*' below.\n";
        for (arrayCellInt = 0; arrayCellInt < chLVLInt ; arrayCellInt++)
        {
            cout << inputCharArray[arrayCellInt];
        }
        cout << "\n";
    }
    else
    {
        cout << "Correct.\n";
    }
}

//Calculate & Return Elapsed Time FUNCTION    -overloaded-
double elapsedTimeScore(double currentTimeDbl, double startTimeDbl)
{
    currentTimeDbl = clock();
    return ((currentTimeDbl - startTimeDbl) / 1000);
}

//Calculate & Return Score FUNCTION     -overloaded-
double elapsedTimeScore(int errorCountInt, int chLVLInt, double elapsedTimeDbl)
{
    return (100-(100 * errorCountInt / chLVLInt + elapsedTimeDbl));
}  

void typingResults(int& chLVLInt, double scoreDbl)
{
    if (scoreDbl >= 80)
    {
        chLVLInt++;
        cout << "\nGood job! Your next practice will be longer.";
    }
    else if (scoreDbl <= 60)
    {
        if (chLVLInt > 5)
        {
            chLVLInt--;
            cout << "\nOops! Let's try shorter one next time.";
        }
    }    
    else
    {
        cout << "\nAverage! Let's try this number of characters again.";
    }
}

//Practice Again FUNCTION
bool practiceAgain(int testCountInt, int maxNumTurnsInt)
{
     int sentinelInt;
     char questionChar;
     if (testCountInt >= maxNumTurnsInt)
     {
         cout << "\n";
         return 0;
     }
     do{
        sentinelInt = 1;
        cout << "\n\nDo you want to practice again? (Y/N) ";
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
     } while (sentinelInt == 0); 
}

//Display Final Results FUNCTION
void dispFinalResults(int testCountInt, double testScoresArray[])
{
    double scoreAvgDbl, scoreSumDbl=0;
    cout << "Your test scores are listed below: \n";
    for (arrayCellInt = 0; arrayCellInt < testCountInt ; arrayCellInt++)
    {
        cout << "Test " << arrayCellInt + 1 << ": " 
             << testScoresArray[arrayCellInt] << "\n";
        scoreSumDbl = scoreSumDbl + testScoresArray[arrayCellInt];
    }
    scoreAvgDbl = scoreSumDbl / testCountInt;
    cout << "Your average score is: " << scoreAvgDbl << "\n";
}
