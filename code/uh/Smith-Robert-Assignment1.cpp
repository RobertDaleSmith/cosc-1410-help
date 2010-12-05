/*  COSC 1410     Fall 2010   
    Programmer:   Robert Dale Smith
    Assignment:   1  (one)
    Due Date:     09/08/2010
    Class Time:Mon-Thur 1PM-2:30PM      */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const double DATA_QUOTA_DBL = 6000;
const double FEE_DBL = 60.00;
const int USER_COUNT_INT = 3;
double costPerMBDbl;
double userOneDbl;
double userTwoDbl;
double userThreeDbl;
double owedOneDbl;
double owedTwoDbl;
double owedThreeDbl;
double owedTotalDbl;
double dataTotalDbl;
double dataLeftOverDbl;
double costLeftOverDbl;

int main()
{
    //Requests the data usage of three users and stores in proper variables.
    cout << "How many MB of data did user 1 use? ";
    cin  >> userOneDbl;
    cout << "How many MB of data did user 2 use? ";
    cin  >> userTwoDbl;
    cout << "How many MB of data did user 3 use? ";
    cin  >> userThreeDbl;
    
    //Calculates the cost per megabyte.
    costPerMBDbl = FEE_DBL / DATA_QUOTA_DBL;
    
    //Calculates how much is owed by each user based on usage.
    owedOneDbl = userOneDbl * costPerMBDbl;
    owedTwoDbl = userTwoDbl * costPerMBDbl;
    owedThreeDbl = userThreeDbl * costPerMBDbl;
    
    //Calculates total data usage by all three users.
    dataTotalDbl = userOneDbl + userTwoDbl + userThreeDbl;
    
    //Calculates the amount of data remaining for the month.
    dataLeftOverDbl = DATA_QUOTA_DBL - dataTotalDbl;
    
    //Calculates the cost of the leftover bandwidth for each user.
    costLeftOverDbl =  dataLeftOverDbl / USER_COUNT_INT  * costPerMBDbl;
    
    /*Calculates the total amount owned by each user. 
      Bandwidth usage cost plus leftover bandwidth cost. */
    owedOneDbl = owedOneDbl + costLeftOverDbl;
    owedTwoDbl = owedTwoDbl + costLeftOverDbl;
    owedThreeDbl = owedThreeDbl + costLeftOverDbl;
    
    /*Calculates the final total owed by all three users.
      Should equal FEE_DBL, but rounding may cause result to not be exact. */
    owedTotalDbl = owedOneDbl + owedTwoDbl + owedThreeDbl;
    
    //Prints to the screen the amount of data used and amounts owed by users.
    cout << fixed << setprecision (2);
    cout << "\nCell phone data bill:";
    cout << "\n-----------------------------------";
    cout << "\nTotal data used: " << dataTotalDbl <<" MB\n";
    cout << "\nUser 1 owes: " << setw(16) << "$" << owedOneDbl;
    cout << "\nUser 2 owes: " << setw(16) << "$" << owedTwoDbl;
    cout << "\nUser 3 owes: " << setw(16) << "$" << owedThreeDbl;
    cout << "\n-----------------------------------";
    cout << "\nTOTAL FEE: " << owedTotalDbl <<"\n";
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
