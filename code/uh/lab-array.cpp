#include <iostream>    //Library included for Input/Output Functions.
#include <iomanip>     //Library included for spacing and formating.
#include <ctime>       //For generating random number based on the time.

using namespace std;

const int ARRAY_SIZE_INT = 10;
int numbers[ARRAY_SIZE_INT] = {1,2,3,4,5,6,7,8,9,10};
int numChk;

int main()
{
    for (numChk = 0; numChk < ARRAY_SIZE_INT; numChk++)
    {
        if (numbers[numChk] % 2 == 0)
           {
               cout << numbers[numChk] <<" is even\n";
           }
    }
    cout << "\n\n";
    for (numChk = 0; numChk < ARRAY_SIZE_INT; numChk++)
    {
        if (numbers[numChk] % 2 == 1)
           {
               cout << numbers[numChk] <<" is odd\n";
           }
    }
    
    system("Pause");
}    
