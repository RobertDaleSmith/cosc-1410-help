/*  COSC 1410     Fall 2010   
    Programmer:   Robert Dale Smith
    Assignment:   2  (two)
    Due Date:     09/15/2010
    Class Time:   Mon-Thur 1PM-2:30PM      */

#include <cstdlib>
#include <iostream>

using namespace std;

char questionChar;
int sentinelInt;

int main()
{   
    cout << "Animal Classifier App \n\n";
    cout << "  This program will help you classify an animal as an\n";
    cout << "  Insect, Reptile, Bird or Mammal.\n\n";
        
    //Primary loop that keeps going until the user doesn't want to continue.
    do
    {
        //Start loop and decision statements for asking questions and classifing animal type.    
        do
        {
            sentinelInt = 0;
            cout << "Does your animal have a backbone? (y/n): ";
            cin  >> questionChar;
            if (questionChar == 'y' || questionChar == 'Y' || questionChar == 'n' || questionChar == 'N')
               {
                   if (questionChar == 'n' || questionChar == 'N')
                       {
                             cout << "\n\n     Your animal is classified as an Insect. \n\n";
                             
                       }
                   if (questionChar == 'y' || questionChar == 'Y')
                       {
                        //Second loop for second question nested into the first loop.
                            do
                            {
                                sentinelInt = 0;
                                cout << "Is your animal warm-blooded? (y/n): ";
                                cin  >> questionChar;
                                if (questionChar == 'y' || questionChar == 'Y' || questionChar == 'n' || questionChar == 'N')
                                   {
                                       if (questionChar == 'n' || questionChar == 'N')
                                           {
                                                 cout << "\n\n     Your animal is classified as a Reptile. \n\n";
                                                 
                                           }
                                       if (questionChar == 'y' || questionChar == 'Y')
                                           {
                                            //Third loop for third question nested into the second loop.
                                                do
                                                {
                                                    sentinelInt = 0;
                                                    cout << "Can your animal fly? (y/n): ";
                                                    cin  >> questionChar;
                                                    if (questionChar == 'y' || questionChar == 'Y' || questionChar == 'n' || questionChar == 'N')
                                                       {
                                                           if (questionChar == 'n' || questionChar == 'N')
                                                               {
                                                                     cout << "\n\n     Your animal is classified as a Mammal. \n\n";
                                                                     
                                                               }
                                                           if (questionChar == 'y' || questionChar == 'Y')
                                                               {
                                                                     cout << "\n\n     Your animal is classified as a Bird. \n\n";
                                                                     
                                                               }
                                                       }
                                                    else
                                                       {
                                                             cout << "\n Please enter only (y/n) answer.  ";
                                                             sentinelInt = 1;
                                                       }
                                                }
                                                while (sentinelInt == 1);                                       
                                                
                                           }
                                   }
                                else
                                   {
                                         cout << "\n Please enter only (y/n) answer.  ";
                                         sentinelInt = 1;
                                   }
                            }
                            while (sentinelInt == 1);
         
                       }
               }
            else
               {
                     cout << "\n Please enter only (y/n) answer.  ";
                     sentinelInt = 1;
               }
        }
        while (sentinelInt == 1);
        
        //Asks user if they want to try again. If they choose yes, then it loops the whole program.
        do
         {
            sentinelInt = 0;
            cout << "Do you want to start over? (y/n): ";
            cin  >> questionChar;
            cout << "\n";
            if (questionChar == 'y' || questionChar == 'Y' || questionChar == 'n' || questionChar == 'N')
               {
                   if (questionChar == 'n' || questionChar == 'N')
                       {     
                             sentinelInt = -1;
                       }     
                   if (questionChar == 'y' || questionChar == 'Y')
                       {     
                             sentinelInt = 1;
                       }
               }
            else
               {
                     cout << "\n Please enter only (y/n) answer.  ";
                     sentinelInt = 0;
               }
         }
         while (sentinelInt == 0);
    }
    while (sentinelInt != -1);                                       
    
    //All loops have been triggered to end, so program is ending here.
    system("PAUSE");
    return EXIT_SUCCESS;
}
