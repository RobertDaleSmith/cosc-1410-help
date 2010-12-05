// Lab2 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
// This program converts miles, yards, feet, and inches into meters. 
// Once it is converted it is printed in a table onto the screen.
//
// Inputs:	Miles
//			Yards
//			Feet
//			Inches
// Outputs:	Miles in Meters
//			Yards in Meters
//			Feet in Meters
//			Inches in Meters
//			Total # of Meters
//
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int intFeet;							// inputed number of feet
int intInches;							// inputed number of inches
int intMiles;							// inputed number of miles
int intYards;							// inputed number of yards
int intTotalInches = 0;					// total in inches
float fltMilesInMeters;					// holds value for miles converted into meters
float fltYardsInMeters;					// holds value for yards converted into meters
float fltFeetInMeters;					// holds value for feet converted into meters
float fltInchesInMeters;				// holds value for inches converted into meters
float fltMeters;						// calculated number of meters
const int MILES_TO_INCHES = 63360;		// multiplied by miles to get inches
const int YARDS_TO_INCHES = 36;			// multiplied by yards to get inches
const int FEET_TO_INCHES = 12;			// multiplied by feet to get inches
const float INCHES_TO_METERS = 0.0254;	// multiplied by inches to get meters

// header, title and description of app
cout << "Standard to Metric System Converter" << endl << endl << "\tConverts miles, yards, feet, and inches into meters." << endl << endl;

// input from user, miles, yards, feet, and inches
cout << "Enter the number of miles:  ";
cin >> intMiles;
cout << "Enter the number of yards:  ";
cin >> intYards;
cout << "Enter the number of feet:   ";
cin >> intFeet;
cout << "Enter the number of inches: ";
cin >> intInches;

// calculuations
intTotalInches += intMiles * MILES_TO_INCHES;							// converts inputed data to inches and adds together
intTotalInches += intYards * YARDS_TO_INCHES;							//   ||
intTotalInches += intFeet  * FEET_TO_INCHES;							//   ||
intTotalInches += intInches;											//   ||
fltMilesInMeters = (intMiles * MILES_TO_INCHES) * INCHES_TO_METERS;		// converts miles to meters
fltYardsInMeters = (intYards * YARDS_TO_INCHES) * INCHES_TO_METERS;		// converts yards to meters
fltFeetInMeters = (intFeet * FEET_TO_INCHES) * INCHES_TO_METERS;		// converts feet to meters
fltInchesInMeters = intInches * INCHES_TO_METERS;						// converts inches to meters
fltMeters = intTotalInches * INCHES_TO_METERS;							// converts the total inches to meters

// outputs data onto a table
cout << endl << endl << fixed << setprecision(2);
cout << "Units\t\t" << "Value\t\t" << "Meters" << endl <<'\n';
cout << "Miles\t\t" << intMiles << " mi\t\t" << fltMilesInMeters << " m" <<  '\n';
cout << "Yards\t\t" << intYards << " yd\t\t" << fltYardsInMeters << " m" <<  '\n';
cout << "Feet\t\t" << intFeet << " ft\t\t" << fltFeetInMeters << " m" <<  '\n';
cout << "Inches\t\t" << intInches << " in\t\t" << fltInchesInMeters << " m" << endl << '\n';
cout << "Total\t\t" << intTotalInches << " in\t" << fltMeters << " m" << endl <<  '\n';

// pauses the program and prompts the user to press any key to exit
cout << endl << "To Exit this program ";
system ("pause");
return 0;
}

