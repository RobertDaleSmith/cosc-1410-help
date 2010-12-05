#include <cstdlib>
#include <iostream>

using namespace std;

const double HAMBURGER_PRICE = 1.5;
const double HOTDOG_PRICE = 1.75;
const double DRINK_PRICE = 1.25;
const double TAX = 0.0825;

int main()
{
    int numHamburgers;
    int numHotdogs;
    int numDrinks;
    double hotdogTotal, hamburgerTotal, drinkTotal, taxTotal, finalSubTotal, finalTotal;
    
    cout<<"How many hamburgers do you want? ";
    cin>>numHamburgers;
    cout<<"How many hotdogs do you want? ";
    cin>>numHotdogs;
    cout<<"How many drinks do you want? ";
    cin>>numDrinks;
    cout<<endl;
    
    hamburgerTotal = numHamburgers * HAMBURGER_PRICE;
    hotdogTotal = numHotdogs * HOTDOG_PRICE;
    drinkTotal = numDrinks * DRINK_PRICE;
    
    finalSubTotal = hamburgerTotal + hotdogTotal + drinkTotal ;
    
    taxTotal = finalSubTotal * TAX;
    
    finalTotal = finalSubTotal + taxTotal;
    
    cout<<"Total Hamburgers Cost: "<<hamburgerTotal<<endl;
    cout<<"Total Hotdogs Cost: "<<hotdogTotal<<endl;
    cout<<"Total Drinks Cost: "<<drinkTotal<<endl;
    cout<<"Sub-Total: "<<finalTotal<<endl;
    cout<<"Tax: "<<taxTotal<<endl;
    cout<<"Final Total: "<<finalTotal<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
