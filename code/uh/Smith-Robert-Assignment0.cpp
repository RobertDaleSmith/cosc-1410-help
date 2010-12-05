/*  COSC 1410     Fall 2010   
    Programmer:   Robert Dale Smith
    Assignment:   0  (zero)
    Due Date:     09/01/2010
    Class Time:Mon-Thur 1PM-2:30PM      */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string nameString;
    string nameString2;
    cout.setf(ios::fixed | ios::showpoint);
    cout<<"Hello World!!!"<<endl;
    cout<<endl;
    cout<<"   Objectives: The purpose of this assignment is to make sure "<<endl;
    cout<<"   that students are familiar with the computer system(s) and "<<endl;
    cout<<"   the IDE in the Lab and at home. In addition, we would like "<<endl;
    cout<<"   to be sure that the students know how to edit, compile and "<<endl;
    cout<<"   execute a program. You can copy the program from the notes "<<endl;
    cout<<"   or the textbook. All you need to do is to modify the Hello "<<endl;
    cout<<"   Wolrd program so that it will also say hello to you."<<endl;
    cout<<endl;
    cout<<"   My name is Robert Smith & Welcome to Assignment 0"<<endl;
    cout<<"   for COSC1410 in Fall 2010!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"What is your first name?: ";
    cin>>nameString;
    cout<<endl;
    cout<<"What is your last name?: ";
    cin>>nameString2;
    cout<<endl;
    cout<<"     Hello, "<<nameString<<" "<<nameString2<<"   ...unfortunately my programmer"<<endl;
    cout<<"decided this is where it ends. Goodbye "<<nameString<<".   -The Command Prompt"<<endl;
    cout<<endl;
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
