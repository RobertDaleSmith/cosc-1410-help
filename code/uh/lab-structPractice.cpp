#include <iostream>
#include <string>
using namespace std;



struct StudentRecord
{
       string name;
       string telNum;
       int classCode;
       double gpa;
};

void getData(StudentRecord& student);

//Main Program FUNCTION
int main()
{   
    StudentRecord student;
    getData(student);
    
    cout << "\n Name: "  << student.name 
         << "\n Number: "<< student.telNum
         << "\n Class Code: ";
    switch(student.classCode)
    {
        case 1: cout << "Freshman"; break;
        case 2: cout << "Sophmore"; break;
        case 3: cout << "Junior"; break;
        case 4: cout << "Senior"; break;
        case 5: cout << "Grad"; break;
    }
    cout << "\n GPA: " << student.gpa << "\n\n\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

void getData(StudentRecord& student)
{
     cout << "Name: ";
     // cin.getline(student.name);  This way only works for array of char
     getline(cin, student.name);
     cout << "\nPhone: ";
     cin  >> student.telNum;
     cout << "\nEnter Class Level \n (1=Freshman, 2=Sophmore, 3=Junior, 4=Senior, 5=Grad): ";
     cin  >> student.classCode;
     cout << "\nGPA:";
     cin  >> student.gpa;
}
    
//    string name
//    string telNum
//    int classCode
//    // 1=freshman, 2=soph, 3= jun, 4= sen, 5=grad
//    double gpa
//    
//    
//    
//    variable type of StudentRecord (call by ref)
//    
//    prompt the user to enter in values of the members of the structure.
    
    
