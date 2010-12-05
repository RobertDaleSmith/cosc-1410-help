// Lab4 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
//		This program finds the difference between two times.
//
// Inputs:	First time in (HH:MM:SS)
//			Second time in (HH:MM:SS)
//
// Outputs:	Difference between times.

#include <iostream>
using namespace std;

//Prototypes for the functions used in this project.
int gettime (int& intTotalInSeconds);
int displaytime (int intDifferenceInTimes);

int main()
{
	int intFirstTotalInSeconds;			//Variable to hold the first time in seconds.
	int intSecondTotalInSeconds;		//Variable to hold the second time in seconds.
	int intDifferenceInTimes;			//Variable to hold the difference between the times.
	int intErrorCheck;					//Variable to hold a returned value that is checked for errors.

	//Heading, displays title and short description.
	cout << "Difference Between Two Times Calculator" << endl << "ITSE 1307 C++ - Lab #4" << endl << endl << "\tCalculates the difference between two times." << endl << endl;

	//Asks the user for the first time and checks it for errors.
	cout << "Enter the first time (HH:MM:SS): ";
	intErrorCheck = gettime(intFirstTotalInSeconds);
	if (intErrorCheck <= -1)
		{
			cout << endl << "Error, The time you entered was invalid." << endl;
			system ("pause");
			return 0;
		}

	//Asks the user for the second time and checks it for errors.
	cout << "Enter the second time (HH:MM:SS): ";
	intErrorCheck = gettime(intSecondTotalInSeconds);
	if (intErrorCheck <= -1)
		{
			cout << endl << "Error, The time you entered was invalid." << endl;
			system ("pause");
			return 0;
		}

	//Checks to see if the second time is greater then the first. If so then it will display an error.
	if (intSecondTotalInSeconds > intFirstTotalInSeconds)
	{
			cout << endl << "Error, The second time you entered was greater then the first time." << endl;
			system ("pause");
			return 0;
	}

	//Calculates difference between the times.
	intDifferenceInTimes = (intFirstTotalInSeconds - intSecondTotalInSeconds);

	//Displays difference in times and checks for errors.
	intErrorCheck = displaytime (intDifferenceInTimes);
	if (intErrorCheck <= -1)
		{
			cout << endl << "Error, The time you entered was invalid." << endl;
			system ("pause");
			return 0;
		}
	
	//Skips a line and pauses, to allow the user to see the results.
	cout << endl;
	system ("pause");
}

int gettime(int& intTotalInSeconds)		//Gets the time from the user.
{
	int intHours;						//Variable holds hours inputed.
	int intMinutes;						//Variable holds minutes inputed.
	int intSeconds;						//Variable holds seconds inputed.
	char c;								//Variable that holds the colon inputed in the times.
	const int SECONDS_IN_HOUR = 3600;	//Constant for the number of seconds in a hour.
	const int SECONDS_IN_MINUTE = 60;	//Constant for the number of seconds in a minute.

	//Asks user to input time.
	cin >> intHours >> c >> intMinutes >> c >> intSeconds;

	if (intHours > 23)		//Checks the hours and returns a -1, if the hours are invalid.
		{	
			return -1;
		}
	if (intMinutes > 60)	//Checks the minutes and returns a -2, if the minutes are invalid.
		{	
			return -2;
		}
	if (intSeconds > 60)	//Checks the seconds and returns a -3, if the seconds are invalid.
		{	
			return -3;
		}

	//Converts the hours and minutes to seconds and adds the total seconds together.
	intTotalInSeconds = (intHours * SECONDS_IN_HOUR) + (intMinutes * SECONDS_IN_MINUTE) + (intSeconds);
	return 0;
}

int displaytime (int intDifferenceInTimes)	//Displays the difference in the times.
{
	int intHours;						//Variavle to hold hours.
	int intMinutes;						//Variable to hold minutes.
	int intSeconds;						//Variable to hold seconds.
	const int SECONDS_IN_HOUR = 3600;	//Constant for the number of seconds in a hour.
	const int SECONDS_IN_MINUTE = 60;	//Constant for the number of seconds in a minutes.
	const int SECONDS_IN_DAY = 86400;	//Constant for the number of seconds in a day.

	if (intDifferenceInTimes >= SECONDS_IN_DAY)	//Checks to see if the difference is more then one day. If it is, then it returns a -1.
		{
			return -1;
		}

intHours = (intDifferenceInTimes / SECONDS_IN_HOUR);							//Converts the seconds to hours.
intMinutes = ((intDifferenceInTimes % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE );	//Converts the remaining seconds to minutes.
intSeconds = ((intDifferenceInTimes % SECONDS_IN_HOUR) % SECONDS_IN_MINUTE );	//Finds the amount of remaining seconds.

//Prints to the screen the difference between the two points.
cout << endl << "The difference between the times is (HH:MM:SS): " << intHours << ":" << intMinutes << ":" << intSeconds << endl;
return 0;
}