// Lab5 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
//		This program finds the sum of a set of digits.
//
// Inputs:	Set of digits.
//
// Outputs: Sum of the set of digits.

#include <iostream>
#include <string>
using namespace std;

int yesno();

int main()
{
long longInputValue;		//Variable that holds the value entered by the user.
long longDigitTotal;		//Variable that holds the total value of the sum of the digits.
long longOrginalInput;		//Variable that holds the original value.

//Application heading.
cout << "Digit Sum Calculator ver 1.0 \n" << "ITSE 1307 C++ - Lab #5 \n\n" << "\t Calculates the sum of a set of digits.\n\n";

	do 
	{
		cout << '\n' << "Enter a \"long\" number: ";	//Asks the user to enter a number.
		cin >> longInputValue;							//and then stores it in a variable.		
		longDigitTotal = 0;								//Resets value to zero.
		longOrginalInput = longInputValue;				//Backs up the orginal value.
		while (longInputValue > 0)						//Loop finds the sum of the digits.
		{
			longDigitTotal += (longInputValue % 10);	//Finds the remainder of the input value and adds it to the total.
			longInputValue /= (10);						//Prepares the input value for the next time around the loop.
		}	//while
		//Outputs the sum of the digits onto the screen.
		cout << '\n' << "The sum of the digits " << '\"' << longOrginalInput << '\"' << " is: " << longDigitTotal << "." << '\n' << '\n';
	}	while(yesno() == 1);
}	//main


int yesno()
{
	string stringResponse;	//Holds the character of the response entered.
	while(1)				//Loops until a correct value is entered.
	{
		cout << "Would you like to do another number? (y/n): ";	//Asks the user if they wanted to do another
		cin >> stringResponse;									//and stores that value.
		if(stringResponse == "y" || stringResponse == "Y")		//Returns a one if response was yes.
		{
			return(1);
		}	//if
		if(stringResponse == "n" || stringResponse == "N")		//Returns a zero if the response was no.
		{
			return(0);
		}	//if
	}	//while

}	//yesno
