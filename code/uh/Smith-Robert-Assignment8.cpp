//  Assignment 8: C-Strings and Structures        COSC 1410 Mon-Th5ur 1PM-2:30PM 
//  By: Robert D. Smith
//                
//  Description:  In this assignment you are creating a menu-driven address book
//                application. The address book should have features to  insert 
//                new record, display records, search  for  an entry, and delete
//                an entry.
//  
     
#include <iostream>
#include <string>
using namespace std;

//STRUCTURES INITIALIZATION
struct dateType
{      int year, month, day;      };
struct studentType
{      char iD[8], firstName[21], lastName[21], phoneNum[16], address[101];
       dateType dOB;              };

//FUNCTION PROTOTYPES
int addressBookMenu(int entriesCount);
studentType addAnEntry(int& entriesCount);
void displayAllEntries(int entriesCount);
void displayAnEntry(int entriesCount, int x);
void deleteEntry(int& entriesCount);
int searchAnEntry(int entriesCount);
void emptyError();

//GLOBAL VARIABLES
studentType addressBook[200];

//MAIN PROGRAM FUNCTION
int main()
{   
    int entriesCount = 0, exitTrigger = 0;
    do
    {
        switch(addressBookMenu(entriesCount))
            {
             case 1: addressBook[entriesCount] = addAnEntry(entriesCount);break;
             case 2: displayAllEntries(entriesCount);                     break;
             case 3: searchAnEntry(entriesCount);                         break;
             case 4: deleteEntry(entriesCount);                           break;
             case 5: exitTrigger = 1;                                     break;
            }
    } while (!exitTrigger);
}

//ADDRESS BOOK MAIN MENU FUNCTION
int addressBookMenu(int entriesCount)
{
    int selection;
    cout << "\n************** Address Book Menu *********** " 
         << entriesCount << " ****"  << endl
         << "1. Add an Entry"        << endl
         << "2. Display all Entries" << endl
         << "3. Search an Entry"     << endl
         << "4. Delete an Entry"     << endl
         << "5. Exit"                << endl;
    do
    { 
       cout << ">> ";
       cin  >> selection;
       cout << "\n";
    }  while(!(selection > 0 && selection <= 5));
    cin.ignore(1000, '\n');
    return selection;
}

//ADD SINGLE ENTRY FUNCTION
studentType addAnEntry(int& entriesCount)
{
    studentType student;
    cout << "\n************** Add To Address Book ****************\n\n" 
         << "Student ID:     ";  cin>>student.iD;        cin.ignore(1000, '\n');
    cout << "First Name:     ";  cin>>student.firstName; cin.ignore(1000, '\n');
    cout << "Last Name:      ";  cin>>student.lastName;  cin.ignore(1000, '\n');
    cout << "Phone Number:   ";  cin>>student.phoneNum;  cin.ignore(1000, '\n');
    cout << "Home Address:   ";  cin.getline(student.address,  101, '\n');
    cout << "Date of Birth \n";  
    cout << "         Year:  ";  cin >> student.dOB.year;
    cout << "         Month: ";  cin >> student.dOB.month;
    cout << "         Day:   ";  cin >> student.dOB.day;
    entriesCount++;
    cout << "\n************** Student Added To Entry " << entriesCount 
         << " ***********\n\n" ;
    return student;
}

//DISPLAY ALL ENTRIES FUNCTION
void displayAllEntries(int entriesCount)
{
    cout << "\n************** Full Address Book View *************\n";
    for (int x = 0; x < entriesCount; x++)
        displayAnEntry(entriesCount, x);
    if (entriesCount == 0)
       emptyError();
}

//DISPLAY SINGLE ENTRY FUNCTION
void displayAnEntry(int entriesCount, int x)
{
    cout << "\n********** Student # "<< (x+1) << " **********";
    cout << "\n   ID:            " << addressBook[x].iD;
    cout << "\n   First Name:    " << addressBook[x].firstName;
    cout << "\n   Last Name:     " << addressBook[x].lastName;
    cout << "\n   Phone Num:     " << addressBook[x].phoneNum;
    cout << "\n   Address:       " << addressBook[x].address;
    cout << "\n   Date of Birth: " << addressBook[x].dOB.year  << "-"
                                   << addressBook[x].dOB.month << "-"
                                   << addressBook[x].dOB.day;
    cout << "\n*********************************\n";
}

//DELETE ENTRY FUNCTION
void deleteEntry(int& entriesCount)
{
    int selection;
    cout << "\n************** Delete From Address Book ***********\n";
    if (entriesCount > 0)
    {
        cout << "\nWhich student would you like to delete?: \n";
        do
        { 
           cout << ">> ";
           cin  >> selection; cin.ignore(1000, '\n');
        }  while(!(selection > 0 && selection <= entriesCount));
        
        cout << "\n************** Student " << selection 
             << " Has Been Removed *********\n\n" ;
             
        for ( ; selection <= entriesCount ; selection++)
        {   addressBook[selection-1] = addressBook[selection];   }
        entriesCount--;
    }
    else if (entriesCount == 0)
       emptyError();
}

//SEARCH FUNCTION
int searchAnEntry(int entriesCount)
{
     int selection, searchForInt, i, x;
     char searchFor[20];
     cout << "\n************** Search Menu ************************\n"
          << "1. Based on ID"            << endl
          << "2. Based on Last Name"     << endl
          << "3. Based on Year of Birth" << endl;
     do
     { 
        cout << ">> "; cin  >> selection; cin.ignore(1000, '\n');  cout << "\n";
     }  while(!(selection > 0 && selection <= 3));
     switch(selection)
           {
            case 1:
                 cout << "Search for StudentID: ";
                 cin.getline(searchFor, 8, '\n');
                 for (x = 0; x < entriesCount ; x++)
                 {   if (strcmp(addressBook[x].iD, searchFor) == 0)
                      { displayAnEntry(entriesCount, x); i = x;}      }return i;
            case 2:
                 cout << "Search for Last Name: ";
                 cin.getline(searchFor, 8, '\n');
                 for (x = 0; x < entriesCount ; x++)
                 {   if (strcmp(addressBook[x].lastName, searchFor) == 0)
                      { displayAnEntry(entriesCount, x); i = x;}      }return i;
            case 3:
                 cout << "Search for Year Born: ";
                 cin >> searchForInt;
                 for (x = 0; x < entriesCount ; x++)
                 {   if (addressBook[x].dOB.year == searchForInt)
                      { displayAnEntry(entriesCount, x); i = x;}      }return i;
           }
}

//EMPTY ADDRESS BOOK FUNCTION
void emptyError()
{
      cout << "\n        !The Address Book is Empty!\n\n"
           << "      Press 1 on the main menu to add\n"
           << "       students to the address book.\n";
}
