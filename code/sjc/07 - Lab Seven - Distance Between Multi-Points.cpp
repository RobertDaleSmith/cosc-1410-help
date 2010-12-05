// Lab7 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
//		This program asks the user to enter a set of points, and then
//		calculates the distance between the points.
//
// Inputs:	A set of up to ten x points.
//			A set of up to ten y points.
//								
// Outputs: Distance between each point.
//			Sum of the distance between the points.
//
#include <iomanip>		//Input/Output Manipulator Library
#include <iostream>		//Input/Output Stream Library
#include <string>		//String Library
#include <cmath>		//Math Calculations Library

using namespace std;

/*Function Prototypes Start*/
int GetPoints      (float xPoints[],			//X-Points Array Variable
					float yPoints[],			//Y-Points Array Variable
					int   maxSize			);	//Maximum size of arrays
float DisplayPoints(float xPoints[],			//X-Points Array Variable
					float yPoints[],			//Y-Points Array Variable
					int   numPoints			);	//Number of points entered
float CalcDistance (float fltFirstXCoord,		//First X-point to be calculated
					float fltFirstYCoord,		//First Y-point to be calculated
					float fltSecondXCoord,		//Second X-point to be calculated
					float fltSecondYCoord	);	//Second Y-point to be calculated
void ProgramTitle();
int YesNo();
/*Function Prototypes End*/

int main()
{
const int INT_MAX_POINTS = 10;					//Maximum size of arrays constant
float xPoints[INT_MAX_POINTS];					//X-Points Array Variable
float yPoints[INT_MAX_POINTS];					//Y-Points Array Variable
float floatTotalDistance;						//Total distance Variable
int intNumPoints;								//Number of points entered
ProgramTitle();									//Displays the program's title.
do												
{
	//Gets points and returns the number of points entered.
	intNumPoints = GetPoints(xPoints, yPoints, INT_MAX_POINTS);
	//Displays points entered and the distance between them, and then returns the total distance.
	floatTotalDistance = DisplayPoints(xPoints, yPoints, intNumPoints);
	//Outputs the total distance.
	cout << endl << "The total distance between all points is: " << floatTotalDistance << endl;
}while(YesNo() == 1);//end do while Loop		//Asks the user if they want to do it again. 
}//end main Function

int GetPoints(float xPoints[], float yPoints[], int maxSize)
{
	int intXYSize;								//Size of X & Y Arrays
	int intRepeatQuest;							//Marker to check the repeat question.
	char charYesNoQuest;						//Chracter to hold the answer to the question.
	for (intXYSize = 0; intXYSize < maxSize; intXYSize++)
	{								//Loops until the max size is reached of x&y is reached.
		cout << "Enter the x-point: ";
		cin  >> xPoints[intXYSize];				//Gets a x-point.
		cout << "Enter the y-point: ";
		cin  >> yPoints[intXYSize];				//Gets a y-point.
		cout << endl;
			if(intXYSize < (maxSize-1) && intXYSize > 0)
			{			//If at least two points have been entered and the maximum limit of 
				do		//points has not been met, then ask if they want to enter another point.			
				{								//Loops until a valid answer is given.
					cout << "Would you like to enter another point? (y/n): ";
					cin  >> charYesNoQuest;
					cout << endl;
					intRepeatQuest = 0;
					switch (charYesNoQuest)
					{
						case 'Y':	
						case 'y':	break;
						case 'N':	
						case 'n':	
									return ++intXYSize;
						default:	intRepeatQuest = 1;
					}//end switch Decision
				} while(intRepeatQuest == 1); //end do Loop
			}//end if Decision
	}//end for Decision
	return intXYSize;
}//end GetPoints Function

float DisplayPoints(float xPoints[], float yPoints[], int numPoints)
{
	int intCounter;								//Counter for the loop.
	float fltFirstXCoord;						//First X-point to calculate.
	float fltFirstYCoord;						//First Y-point to calculate.
	float fltSecondXCoord;						//Second X-point to calculate.
	float fltSecondYCoord;						//Second Y-point to calculate.
	float fltDistance;							//Distance between the points.
	float fltAccumDistance;						//Accumulated total distance.
	fltAccumDistance = 0.0;						//Re-sets variable to zero.
	for(intCounter = 0; intCounter < (numPoints - 1); intCounter++)
	{						//Loops until all the distances between the points have been calculated.
	fltFirstXCoord = xPoints[intCounter];
	fltFirstYCoord = yPoints[intCounter];
	fltSecondXCoord = xPoints[intCounter+1];
	fltSecondYCoord = yPoints[intCounter+1];
	//Calculates the distance between two points and returns the distance.
	fltDistance = CalcDistance( fltFirstXCoord, fltFirstYCoord, fltSecondXCoord, fltSecondYCoord);
	fltAccumDistance += fltDistance;			//Accumulates the total distance of the points.
	//Outputs the two points and the distance between the two.
	cout << "The distance between (" << fltFirstXCoord << "," << fltFirstYCoord << ") and ("; 
	cout << fltSecondXCoord << "," << fltSecondYCoord << ") is: " << fltDistance << endl;
	}
	return fltAccumDistance;					//Returns the Accumulated Distance.
}//end DisplayPoints Function

float CalcDistance ( float fltFirstXCoord,		//First X-point to calculate.
					 float fltFirstYCoord,		//First Y-point to calculate.
				   	 float fltSecondXCoord,		//Second X-point to calculate.
					 float fltSecondYCoord)		//Second Y-point to calculate.
{
	//Calculates the distance between two points and returns the value to the calling function.
	return	(
				sqrt( 
					  (pow((fltFirstXCoord - fltSecondXCoord),2))
					  +
					  (pow((fltFirstYCoord - fltSecondYCoord),2)) 
					)
			);
}//end CalcDistance Function
void ProgramTitle()
{
	//Title for the program. Includes name, version, programming class, and a short description.
	cout << "Distance Between A Set of Points Calculator ver 1.7 \n" << "ITSE 1307 C++ - Lab #7 \n\n"
		 << "\t This program asks the user to enter a set of points, and then\n"
		 << "\t calculates the distance between the points.\n\n";
}//end ProgramTitle Function

int YesNo()
{
	int intRepeatQuest;							//Marker to check if valid response was given.
	char charYesNoQuest;						//Character to hold user's response.
				do
				{			//Loop until valid resonse is given.
				cout << endl << "Would you like to enter another set of points? (y/n): ";
				cin >> charYesNoQuest;
				cout << endl;
				intRepeatQuest = 0;
					switch (charYesNoQuest)
					{
						case 'Y':	
						case 'y':	return(1);
						case 'N':	
						case 'n':	return(0);
						default:	intRepeatQuest = 1;
					}//end switch Decision
				} while(intRepeatQuest == 1); //end do while Loop
				return(0);
}//end YesNo Function
