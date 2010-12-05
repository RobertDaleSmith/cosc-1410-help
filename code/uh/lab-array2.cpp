#include <iostream>    //Library included for Input/Output Functions.
#include <iomanip>     //Library included for spacing and formating.
#include <ctime>       //For generating random number based on the time.

using namespace std;

int summation(int array[], int array_length);

int main()
{
    const int A1_LENGTH = 6;
    const int A2_LENGTH = 3;
    int a1[A1_LENGTH] = {2,4,6,8,10,12};
    int a2[A2_LENGTH] = {5,10,15};
    
    cout << summation(a1, A1_LENGTH) << "\n";
    cout << summation(a2, A2_LENGTH) << "\n";
    
    system("Pause");
}    

int summation(int array[], int array_length)
{
    int counterInt;
    int sumTotalInt = 0;
    for ( counterInt = 0 ; counterInt < array_length ; counterInt++)
    {
        sumTotalInt = sumTotalInt + array[counterInt];
    }   
    return sumTotalInt;    
}
