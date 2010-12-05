//  Assignment 4: Functions   COSC 1410 Mon-Thur 1PM-2:30PM 
//  By: Robert Dale Smith
//  
//  This program allows the user to enter the amount they want to invest,
//  the interest rate, and the number of years of the investment. The 
//  program then calculates the interest and displays on screen the
//  amount of interest earned and the ending balance.
//  
//  Inputs:       Principal Amount
//                Interest Rate
//                Time Period
//                Y/N to Loop Program
//  Outputs:      Years (every year from 1 until the inputed time period)
//                Beginning Balance (per year)
//                Interested Earned (per year)
//                Ending Balance (per year)
//                

#include <iostream>
#include <iomanip>
using namespace std;

//Declare Variables
double principalDouble, rateDouble, balanceDouble, interestDouble;
int timeInt, yearInt;

//Declaring Prototypes for Functions
double computeInterest(double balanceDouble, double rateDouble);
double printEarning(double balanceDouble, double interestDouble);
bool repeat();

//MAIN FUNCTION of the Program.
int main()
{
    cout << "Interest Calculator\n\n";    //Prints Program Title On Screen.
    do
    {
        //Requests User to input the initial amount being invested,
        //the interested rate, and the number of years of investment.
        cout << "\nEnter the Principal Value: ";
        cin >> principalDouble;
        cout << "\nEnter the Interest Rate (in %): ";
        cin >> rateDouble;
        cout << "\nEnter the time period (in years): ";
        cin >> timeInt;
        
        //Setting the initial balance for calculations.
        balanceDouble = principalDouble;
        
        //Prints Table Header on Screen.
        cout << "\n"
             << setw(17) << "Beginning"
             << setw(12) << "Interest"
             << setw(13) << "Ending\n";
        cout << setw(1)  << " Year"
             << setw(12) << " Balance"
             << setw(12) << " Earned"
             << setw(13) << " Balance\n";
        cout << setw(1)  << " ----"
             << setw(12) << " ----------"
             << setw(12) << " ----------"
             << setw(13) << " ----------\n";
        
        //Loop to generate each row of the table. Each row in the table displays
        //  the year, starting balance, interest earned, and ending balance.
        for (yearInt = 1; yearInt <= timeInt; yearInt++)
        {
            cout << fixed    << setprecision (2);
            cout << "\n"
                 << setw(5)  << yearInt
                 << setw(11) << balanceDouble;   
            //Calls Function to Calculate Interest.
            computeInterest(balanceDouble, rateDouble); 
            //Adds interest to balance for the next year's calculation.
            balanceDouble = balanceDouble + interestDouble;
            //Calls Function to Print Interest and Ending Balance on screen.
            printEarning(balanceDouble, interestDouble);
            
            if (yearInt % 5 == 0)
            {
                 cout << "\n";
            }
        }
    }
    while(repeat());
    return EXIT_SUCCESS;     //Ends program...
}
//INTEREST COMPUTATION FUNCTION
//   This function passes the variables to calculate interest rate.
double computeInterest(double balanceDouble, double rateDouble)
{
     interestDouble = (rateDouble / 100) * balanceDouble;
}
//PRINT EARNINGS FUNCTION
//   This function prints the interested earned and then the ending balance.
double printEarning(double balanceDouble, double interestDouble)
{
     cout << setw(12) << interestDouble
          << setw(13) << balanceDouble;       
}
//REPEAT FUNCTION
//   This function asks the user if they would like to continue and then 
//   returns the appropriate bool value. 
bool repeat()
{
     char questionChar;
     int sentinelInt;
     do
         {
            sentinelInt = 1;
            cout << "\n\nDo you want to continue? (Y/N) ";
            cin  >> questionChar;
            cout << "\n";
            if (questionChar == 'y' || questionChar == 'Y' || 
                questionChar == 'n' || questionChar == 'N')
               {
                   if (questionChar == 'n' || questionChar == 'N')
                       {     
                           return 0;
                       }     
                   if (questionChar == 'y' || questionChar == 'Y')
                       {     
                           return 1;  
                       }
                   sentinelInt = 1;
               }   
            else   
               {   
                   cout << "\n Please enter only (y/n) answer.  ";
                   sentinelInt = 0;
               }
         }
         while (sentinelInt == 0);    
}
