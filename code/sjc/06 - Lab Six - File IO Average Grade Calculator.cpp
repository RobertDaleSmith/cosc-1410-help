// Lab6 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
//		This program reads data from a text file. The lab and test averages 
//		are found and then printed to the screen and an output file.
//
// Inputs:	File:	Student ID.
//					Number of lab grades.
//					Number of test grades.
//					Lab grades.
//					Test grades.
//								
// Outputs: File:	Student ID.
//					Average of lab grades.
//					Average of test grades.
//
//			Screen:	Student ID.
//					Lab grades.
//					Average lab grades.
//					Test grades.
//					Average test grades.
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

template <class T>
std::string toString( T value )	//Used for converting values to a string.
{								//	I use this in the program to convert
   std::ostringstream oss;		//	a float value to a string value.
   oss << value;
   return oss.str();
}
using namespace std;

void programTitle();
void dataHeader();

int main()
{
	int intStudentID;			//Student ID.
	int intNumOfLabGrades;		//Number of lab grades.
	int intNumOfTestGrades;		//Number of test grades.
	int intNumOfLabGradesCount;	//Counter for number of lab grades loop.
	int intNumOfTestGradesCount;//Counter for number of test grades loop.
	bool boolFileFound;			//Used to check if the file was found or not.
	float fltLabGrade;			//Lab grade.
	float fltTestGrade;			//Test grade.
	float fltSumLabGrades;		//Sum of lab grades.
	float fltSumTestGrades;		//Sum of test grades.
	float fltAveLabGrades;		//Average of lab grades.
	float fltAveTestGrades;		//Average of test grades.
	string strLabGrades;		//List of lab grades.
	string strTestGrades;		//List of test grades.
	char strFileName[100];		//Name of file to be opened.
	ifstream fsInFile;			//Input file stream.
	ofstream fsOutFile;			//Output file stream.
	
	programTitle();				//Calls function that displays the title.

	boolFileFound=1;			//Sets the file not found status to true.
	while (boolFileFound)		
	{
		boolFileFound=0;		//Sets the file not found status to false.
		cout << "Please enter the file name to open: ";
		cin.getline(strFileName, 100);	//Ask user to input filename
		fsInFile.open(strFileName);		// 	 and opens that filename.
		if (fsInFile.fail() )					//If it fails to open the file,
		{										//	then it shows an error, and 
			cerr << "File not found...\n\n";	//	resets the file not found
			boolFileFound=1;					//	status to true.
			fsInFile.clear();
		}//end if decision
	}//end while loop

	fsOutFile.open("lab6 s07 averages.txt");	//Opens the output file stream.

	dataHeader();				//Calls function for the header.

	while(1)		//Loops as long as there is data in the input file stream.
	{
		fsInFile >> intStudentID >> intNumOfLabGrades >> intNumOfTestGrades;	//Reads in the student ID, number of lab and test grades.
		if(fsInFile.fail())		//Exits the loop if end of file is reached.
		{
			break;
		}//end if decision
		cout << setw(10) << left << intStudentID;	//Outputs the student ID to the screen.
		fsOutFile << intStudentID << " ";			//Outputs the student ID to the output file stream.
		fltSumLabGrades = 0.0F;						//Resets the sum of lab grades to zero.
		strLabGrades = "";							//Resets the string of lab grades to a blank string.

		//Loops until all lab grades are read in from the input file stream.
		for (intNumOfLabGradesCount = 0; intNumOfLabGradesCount < intNumOfLabGrades; intNumOfLabGradesCount++)
		{
			fsInFile >> fltLabGrade;
			strLabGrades += toString(fltLabGrade);
			strLabGrades += " ";
			fltSumLabGrades += fltLabGrade;
		}//end for loop
		fltAveLabGrades = fltSumLabGrades / (float)intNumOfLabGrades;	//Calculates the lab average.
		cout << setw(22) << strLabGrades;			//Prints the list of lab grades to the screen.
		cout << setw(10) << fltAveLabGrades;		//Prints the lab average to the screen.
		fsOutFile << fltAveLabGrades << " ";		//Prints the lab average to the output file stream.
		fltSumTestGrades = 0.0F;					//Resets the sum of the test grades to zero.
		strTestGrades = "";							//Resets the string of test grades to a blank string.

		//Loops until all test grades are read in from the input file stream.
		for (intNumOfTestGradesCount = 0; intNumOfTestGradesCount < intNumOfTestGrades; intNumOfTestGradesCount++)
		{
			fsInFile >> fltTestGrade;				
			strTestGrades += toString(fltTestGrade);
			strTestGrades += " ";
			fltSumTestGrades += fltTestGrade;
		}//end for loop
		fltAveTestGrades = fltSumTestGrades / (float)intNumOfTestGrades;	//Calculates the test average.
		cout << setw(20) << strTestGrades;			//Prints the list of test grades to the screen.
		cout << fltAveTestGrades << '\n';			//Prints the test average to the screen.
		fsOutFile << fltAveTestGrades << '\n';		//Prints the test average to the output file stream.
	}//end while loop
		fsInFile.close();		//Closes the input file stream.
		fsOutFile.close();		//Closes the output file stream.
		cout << '\n';			
		system("pause");		//Pauses so that the user can view calculated data.
}//end main function

void programTitle()
{
	//Title for the program. Includes name, version, programming class, and a short description.
	cout << "File I/O Average Grade Calculator ver 1.6 \n" << "ITSE 1307 C++ - Lab #6 \n\n"
		 << "\t Reads from a file and calculates the lab and test averages.\n\n";
}
void dataHeader()
{
	//Header for data outputed to the screen.
	cout << '\n' << setw(10) << left << "Student" << setw(22) << "Lab" << setw(10) << "Lab" << setw(20) << "Test" << "Test\n";
	cout << setw(10) << "ID" << setw(22) << "Grades" << setw(10) << "Average" << setw(20) << "Grades" << "Average\n\n";
}
