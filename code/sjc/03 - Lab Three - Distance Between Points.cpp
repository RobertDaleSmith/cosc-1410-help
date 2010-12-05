// Lab3 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
// This program finds the distance between two points.
//
// Inputs:	First X Coordinate
//			Second X Coordinate
//			First Y Coordinate
//			Second Y Coordinate
// Outputs:	Distance between two points
//
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//prototypes of the calculate function, x/y coordinate questions function, and the exit question function.
void calculate( float fltFirstXCoord,
				float fltFirstYCoord,
				float fltSecondXCoord,
				float fltSecondYCoord,
				float& fltDistance);
void questions();
void exitquestion( string& stringAnotherDistance );

int main()
{
int intLoopEnd;					//Value to determine if the user wants to exit or find another.
string stringAnotherDistance;	//String to determine if user wants to find another distance.

//Heading
cout << "Distance Between Two Points Calculator" << endl << "ITSE 1307 C++ - Lab #3" << endl << endl << "\tCalculates the distance between two points." << endl << endl;

intLoopEnd = 0;					//sets loop value to zero.
	while ( intLoopEnd == 0)	//loops as long as the loop value is zero.
	{
	intLoopEnd = 1;
	questions();									//call questions procedure
	exitquestion( stringAnotherDistance );			//call exit question procedure

	//determin if user wants to find another value.
		if (stringAnotherDistance == "y" || stringAnotherDistance == "Y")
			{
				cout << endl;
				intLoopEnd = 0;
			}
	}
}

void questions()
{
float fltFirstXCoord;	//input of the first X-coordinate
float fltFirstYCoord;	//input of the first Y-coordinate
float fltSecondXCoord;	//input of the second X-coordinate
float fltSecondYCoord;	//input of the second Y-coordinate
float fltDistance;		//distance between the points
cout << "Please enter the X-Coordinate of the first point: ";
cin >> fltFirstXCoord;
cout << "Please enter the Y-Coordinate of the first point: ";
cin >> fltFirstYCoord;
cout << endl << "Please enter the X-Coordinate of the first point: ";
cin >> fltSecondXCoord;
cout << "Please enter the Y-Coordinate of the first point: ";
cin >> fltSecondYCoord;

//calls the calulation function.
calculate( fltFirstXCoord, fltFirstYCoord, fltSecondXCoord, fltSecondYCoord, fltDistance);

cout << endl << "The distance between the points (" << fltFirstXCoord << "," << fltFirstYCoord << ") and (" << fltSecondXCoord << "," << fltSecondYCoord << ") is: "<< fltDistance << endl << endl;
}

void calculate( float fltFirstXCoord,		// first X coordinate in
				float fltFirstYCoord,		// first Y coordinate in
				float fltSecondXCoord,		// second X coordinate in
				float fltSecondYCoord,		// second Y coordinate in
				float& fltDistance)			// distance out
{
	//calculates the distance between two points.
	fltDistance = sqrt( (pow((fltFirstXCoord - fltSecondXCoord),2)) + (pow((fltFirstYCoord - fltSecondYCoord),2)) );
}

void exitquestion( string& stringAnotherDistance )
{
	//asks the user if they wanna find another.
	cout << "Would you like to find the distance between two other points? (Y/N) ";
	cin >> stringAnotherDistance;
}
