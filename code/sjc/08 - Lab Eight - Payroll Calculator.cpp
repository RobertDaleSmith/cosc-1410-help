// Lab8 - A option                    ITSE 1307.102 Wed Night 6:00PM
// Programmed by Robert Smith
//
//		This program will allow you to enter a set of employees' names, hours
//		worked, and hourly rate. Then the gross pay, net pay, and total gross
//		pay will be calculated, and you'll have the option to save the payroll
//		to a file and to view a summary of the payroll.
//
// Inputs:	Employee Name
//			Employee Hours
//			Employee Hourly Rate
//								
// Outputs: Employee Net Pay
//			Employee Gross Pay
//			Total Gross Pay
//			Payroll Summary
//
#include <iostream>		//Input/Output Stream Library
#include <iomanip>		//Input/Output Manipulator Library
#include <string>		//String Library
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

void program_title();
void get_employee(struct employee& emp,
				  bool& boolGetLineCheck,
				  int employeeCount);
void calc_payroll(struct employee& emp,
				  float& fltTotalGross);
void save_payroll(employee workers[],
				  int employeeCount);
void disp_employee(employee workers[],
				  int employeeCount,
				  float fltTotalGross);
int yes_no(int intMessage);

struct employee
{
	char name[256];		// name of employee
	float hours;		// hours worked
	float rate;			// pay rate per hour
	float gross;		// gross pay
	float net;			// net pay (after deductions)
};

int main()
{
	struct employee emp1;		// create memory for an employee
	const int MAX = 10;
	employee workers[MAX];
	bool boolGetLineCheck = false;
	program_title();
	do
	{
		int employeeIndex = 0;
		int employeeCount = 0;
		int endLoopInt = 1;
		float fltSingleGross = 0.0f;
		float fltTotalGross = 0.0f;
		for(employeeIndex = 0; endLoopInt == 1 ; employeeIndex++)
		{
			employeeCount += 1;
			get_employee(workers[employeeIndex], boolGetLineCheck, employeeCount);
			if(employeeIndex < (MAX - 1))
			{	endLoopInt = yes_no(1);	}
			else
			{	endLoopInt = 0;			}
		}
		if(employeeCount == MAX)
		{	cout << "\n ALERT: Maximum number of employees has been entered! \n"; }
		for(employeeIndex = 0; employeeIndex < employeeCount; employeeIndex++)
		{
			calc_payroll(workers[employeeIndex], fltSingleGross);
			fltTotalGross += fltSingleGross;
		}
		save_payroll(workers, employeeCount);
		disp_employee(workers, employeeCount, fltTotalGross);
	}while(yes_no(4));
	return 0;
}

void program_title()
{
	//Title for the program. Includes name, version, programming class, and a short description.
	cout << "Employee Payroll Calculator ver 1.8 \n" << "ITSE 1307 C++ - Lab #8		\n\n"
		 << "\t This program will allow you to enter a set of employees' names, hours \n"
		 << "\t worked, and hourly rate. Then the gross pay, net pay, and total gross \n"
		 << "\t pay will be calculated, and you'll have the option to save the payroll\n"
		 << "\t to a file and to view a summary of the payroll.						\n\n";
	return;
}	//end ProgramTitle Function

void get_employee(struct employee& emp, bool& boolGetLineCheck, int employeeCount)
{
	// get the value from the user
	cout << "Employee #" << employeeCount << ":\n";
	cout << "Please enter Name: ";
	if (boolGetLineCheck)
	{	cin.ignore();			 }
	else
	{	boolGetLineCheck = true; }
	cin.getline(emp.name, 256);
	cout << "Please enter Hours: ";
	cin >> emp.hours;
	cout << "Please enter Payrate: ";
	cin >> emp.rate;
}

void calc_payroll(struct employee& emp, float& fltSingleGross)
{
	float ot;				// overtiime pay
	float reg;				// regular pay

	if (emp.hours > 40.0)
	{
		ot = (emp.hours - (float) 40.0) * emp.rate * (float) 1.5;
		reg =  40.0f * emp.rate;
	}
	else
	{
		ot = 0.0;
		reg = emp.hours * emp.rate;
	}
	emp.gross = ot + reg;
	emp.net = emp.gross * 0.65f;
	fltSingleGross += emp.gross;
	return;
}

void save_payroll(employee workers[], int employeeCount)
{
	char strFileName[256];
	bool boolFileFound = 1;			//Used to check if the file was found or not.
	struct employee emp;
	ofstream fsOutFile;				//Output file stream.

	if (yes_no(2) == 0)
	{	return;		  }
	while (boolFileFound)		
	{
		boolFileFound=0;		//Sets the file not found status to false.
		cout << "Please enter the file name to open: ";
		cin.ignore();
		cin.getline(strFileName, 256);	//Ask user to input filename
		fsOutFile.open(strFileName);		// 	 and opens that filename.
		if (fsOutFile.fail() )					//If it fails to open the file,
		{										//	then it shows an error, and 
			cerr << "File not found...\n\n";	//	resets the file not found
			boolFileFound=1;					//	status to true.
			fsOutFile.clear();
		}//end if decision
	}//end while loop
	cout << "\n ALERT: Payroll has been saved to: \"" << strFileName << "\"\n\n"; 
	for(int employeeIndex = 0; employeeIndex < employeeCount; employeeIndex++)
	{
		emp = workers[employeeIndex];
		fsOutFile << emp.name << endl;
		fsOutFile << emp.hours << endl;
		fsOutFile << emp.rate << endl;
		fsOutFile << emp.gross << endl;
		fsOutFile << emp.net << endl;
	}
	fsOutFile.close();		//Closes the output file stream.
	return;
}

void disp_employee(employee workers[], int employeeCount, float fltTotalGross)
{
	struct employee emp;

	if (yes_no(3) == 1)
	{
		for(int employeeIndex = 0; employeeIndex < employeeCount; employeeIndex++)
		{
			emp = workers[employeeIndex];
			cout << endl << "Employee #" << (employeeIndex + 1) << ":\n";;
			cout << "     Name: " <<  emp.name  << fixed << setprecision(0) << endl;
			cout << "    Hours: " <<  emp.hours << fixed << setprecision(2) << endl;
			cout << " Pay Rate: $" << emp.rate << endl;
			cout << "Gross pay: $" << emp.gross << endl;
			cout << "  Net pay: $" << emp.net << endl;
			cout << endl;	
		}
	}
	cout << "Gross salary for all employees: $" << fltTotalGross << endl;
	return;
}

int yes_no(int intMessage)
{
	int intRepeatQuest;							//Marker to check if valid response was given.
	char charYesNoQuest;						//Character to hold user's response.
	string stringMessage;
	switch (intMessage)
	{
		case 1:	stringMessage = "Would you like to enter another employee? (y/n): ";
				break;
		case 2:	stringMessage = "Would you like to save the payroll to a file? (y/n): ";
				break;
		case 3: stringMessage = "Would you like to display a full summary? (y/n): ";
				break;
		case 4: stringMessage = "Would you like to enter another set of employees? (y/n): ";
				break;
	}
	do
	{			//Loop until valid resonse is given.
		cout << endl << stringMessage;
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
}//end yes_no Function
