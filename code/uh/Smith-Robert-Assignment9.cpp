//  Assignment 9: Word Ranking                    COSC 1410 Mon-Thurs 1PM-2:30PM 
//  By: Robert D. Smith
//  
//  Description:   In this assignment you, the program you write should  read
//  sentences you entered and collect the following pieces of information: The
//  number of times each word appears: By reading word from the beginning, if
//  this is the first time a word is seen, then create a new entry for the word.
//  If it is not the first time the word  is seen, find that entry from the
//  array and increment its count.  The punctuation at the beginning orthe end
//  of each word should be removed.  For example, words such as stop and “STOP!”
//  should be considered the same word.  However, words like student’s and
//  students are considered as two different words. For hyphenated words, such
//  as "re-design", you should treat it as a single word which is different from
//  "redesign". Ignore the case, so “Don’t” and  “don’t” are treated as the same
//  word.? After collecting the information, sort the array so that the most
//  frequent words appear first. You may use the selection sorting algorithm
//  given in class for this purpose (with some modifications).? Then output the
//  total number of words, total number of distinct words, and a list of each 
//  word and the number of times it appears.
     
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

//Single Word and Count STRUCTURE
struct wordCount
{
    string word;
    int count;
};

//Words and Counts CLASS
class Word
{
    private:
        wordCount allWords[200];
    public:
        void   setName(int index, string singleWord);  //Change word.
        void  setCount(int index, int count);          //Change count.
        int   getCount(int index);                     //Return count.
        string getName(int index);                     //Return word.
        void sortNames(int distCount);
};

//FUNCTION PROTOTYPES
bool getInput(string& inputString, int& totalCount);
string cleanInput(string singleWord);


int main()
{
    //Declare Main Variables
    Word wordList;
    string inputString, singleWord, checkWord;
    int distCount=0, totalCount=0, i;
    bool repeatTrigger;
    
    cout << "Please enter your sentences, you can enter '@@@' \n"
         << "by a new line to finish the input: \n";
    
    //Processes input strings until @@@ is triggered to end input.
    while (getInput(inputString,totalCount))
    {
        istringstream in(inputString); //Declared 'in' istringstream and filled
        do                             //               it with the inputString.
        {   //Reset repeat trigger for next word to check.
            repeatTrigger = 0;
            
            //Pulls word from 'in' istringstream.
            in >> singleWord;
            
            //Removes outer non-alphanumerical char and sets word to lowercase.
            singleWord = cleanInput(singleWord);
            
            //Searches for word and increments counters.
            for (i=0 ; i < 200 && in ; i++)
            {
                   checkWord = wordList.getName(i);
                   if (checkWord.compare(singleWord) == 0)
                   {
                          wordList.setCount( i , ( wordList.getCount(i) + 1 ) );
                          totalCount++;
                          repeatTrigger = 1;
                          break;
                   }
            }
            
            //Adds new word and increments counters.
            if (repeatTrigger == 0 && in)
            {
                   wordList.setName(distCount, singleWord);
                   wordList.setCount(distCount, 1);
                   distCount++;
                   totalCount++;
            }
               
         } while(in); //Loops until 'in' istringstream is empty.
    } //Loops until @@@ is entered on a new line.
    
    wordList.sortNames(distCount);//Sorts Words by Count from Greatest to Least.
    
    //Outputs Results.
    cout << "\n\n\n";
    cout << "         Total number of words: " << totalCount <<"\n";
    cout << "Total number of distinct words: " << distCount <<"\n\n";
    for (i = 0 ; i < distCount ; i++)
    {
        cout << left  << setw(13) << wordList.getName(i) 
             << right << setw(3)  << wordList.getCount(i) << " \n";
    }

    cout << " \n";
    system("PAUSE");
}

//Set Name FUNCTION
void Word::setName(int index, string singleWord)
{   allWords[index].word = singleWord;       }

//Set Count FUNCTION
void Word::setCount(int index, int count)
{   allWords[index].count = count;           }

//Get Count FUNCTION
int Word::getCount(int index)
{   return allWords[index].count;            }

//Get Name FUNCTION
string Word::getName(int index)
{   return allWords[index].word;             }

//Sort Names FUNCTION
void Word::sortNames(int distCount)
{   
    string wordHold;
    int countHold, i, sorted;
    
    do
    {
        sorted = 1;
        for (i = 0 ; i < distCount - 1 ; i++ )
        {   
            if (allWords[i].count < allWords[i+1].count)
            {
                wordHold  = allWords[i].word;
                countHold = allWords[i].count;
                
                allWords[i].word  = allWords[i+1].word;
                allWords[i].count = allWords[i+1].count;
                
                allWords[i+1].word  = wordHold;
                allWords[i+1].count = countHold;
                
                sorted = 0;
                cout << ".";
                break;
            }
        }
    } while(!sorted);
}

//Clean Input FUNCTION
string cleanInput(string singleWord)
{   
    int wordSize, i, n;
    bool resized;
    //Removes non alpha-numeric characters from the START of the string.
    do
    {   
       resized = 0; 
       wordSize = singleWord.length();
       for (i = 0 ; i < wordSize ; i++ )
       {
           if (!isalnum(singleWord[i]))
           {
               for (n = 0 ; n < wordSize ; n++ )
               {
                   singleWord[n] = singleWord[n+1];
               }
               singleWord[wordSize-1] = '\0';
               singleWord.resize (wordSize-1);
               resized = 1;
               break;
           }
           else
           {
               break;
           }
       }
    } while(resized == 1);
    
    //Removes non alpha-numeric characters from the END of the string.
    wordSize = singleWord.length();
    for (i = wordSize ; i >= 0 ; i-- )
    {
       if (!isalnum(singleWord[i]))
       {
           singleWord[i] = '\0';
           singleWord.resize(i);
       }
       else
       {
           break;
       }
    }
    
    //Removes and replaces capital letters with lowercase letters.
    for (i = 0 ; i <= wordSize ; i++ )
    {
       singleWord[i] = tolower(singleWord[i]);
    }
    
    //Returns the clean word without caps and punctuation on the ends.
    return singleWord;
}

//Get Input FUNCTION
bool getInput(string& inputString, int& totalCount)
{
    getline(cin, inputString);
    if (inputString.compare("@@@") == 0)
    {  totalCount++; return 0; }
    else
    {  return 1; }
}

