//  Assignment 3:   Loops    COSC 1410 Mon-Thur 1PM-2:30PM 
//  By: Robert Dale Smith
//  
//  This program requests a positive integer from the user
//  and then checks every natual number that is less than
//  or equal to the user's input. Program generates a list
//  of all divisors of each of these natural numbers. Also
//  tests to see if these natual numbers are prime.
//  
//  Inputs:       Positive Integer (natual number)
//  Outputs:      Testing Numbers
//                Divisors
//                Prime Number or Not
//
#include <cstdlib>
#include <iostream>
using namespace std;

int positiveInt;        //Positive Integer Entered by the User.
int testingInt;         //Counter used to hold integer being tested.
int divisorInt;         //Counter used to hold divisor being tested.
int primeChkInt;        //Counter used to signal if prime or not.
int posChkInt = 0;      //Trigger used to validate positive integer is entered.

int main()
{
    while ( posChkInt <= 1 )      //Loops until positive interger is entered.
    {
        if ( posChkInt == 1 )     //Error message triggered if negative entered.
         {
           cout << "\n  Please enter only positive numbers! \n";    
         }   
        posChkInt = 1;  //Sets trigger to display error if loop doesn't break.
        
        cout << "Input a positive integer : ";
        cin >> positiveInt;       //Natual integer input by user.

        if ( positiveInt >= 1)    //Breaks question loop if valid integer.
         {
             break;
         }
    }
    
    //Starts loop for testing from 1 to the user's input.
    for ( testingInt = 1 ; testingInt <= positiveInt ; testingInt++ )
     {
         cout << "\nTesting " << testingInt << " -> \n";
         cout << "    The divisors: ";
         
         divisorInt = 1;         //Resets divisor to one to be checked again.
         primeChkInt = 0;        //Resets prime number trigger for next test.
         
         //Starts loop to find and output divisors.
         for ( divisorInt = 1 ; divisorInt <= testingInt ; divisorInt++ )
          {
              //Prints to screen valid divisors only.
              if ( testingInt % divisorInt == 0 )
                {
                    cout << divisorInt << " ";
                    primeChkInt++;              
                }           
          }
          //Checks Prime Trigger if the number had two divisors, then its prime.
          if ( primeChkInt == 2 )
            {
              cout << "\n    The number " << testingInt;
              cout << " is a prime number.\n";
            }
          else     //The number is not prime if it doesnt have two divisors.
            {
              cout << "\n    The number " << testingInt;
              cout << " is not a prime number.\n";
            }          
     }
    
    cout << "\n";            //Just a line break.
    system("PAUSE");         //Pauses program and prompts the user to press
    return EXIT_SUCCESS;     //any key to end the program.
}
