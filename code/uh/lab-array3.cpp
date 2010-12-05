//In Lecture Example

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void fillArray(int a[]);
void processArray(int a[]);
void printArray(int a[]);
void createArray(int size);

int main()
{
    int a[10], size;
    fillArray(a);
    processArray(a);
    printArray(a);
    createArray(5);
    
    createArray(7);
    cin>>size;
    createArray(size);
    
    system ("Pause");
    return 0;
}

void fillArray(int a[])
{
     for (int i=0; i<10; i++)
     {
         a[i]=i*10;
     }    
}

void processArray(int a[])
{
     for (int i=0; i<10; i++)
     {
         a[i]=(i*2)*10;
     }    
}

void printArray(int a[])
{
     for (int i=0; i<10; i++)
     {
         cout <<"a["<<i<<"] = "<<a[i];
         cout<<endl;
     }
     cout<<endl;
}

void createArray(int size)
{
     int x[size];
     int startTime, endTime, elapse;
     
     startTime = clock();
     for (int i=0; i<size; i++)
     {
         x[i]=i*100;
     }   
     for (int i=0; i<size; i++)
     {
         cout <<"x["<<i<<"] = "<<x[i];
         cout<<endl;
     }
     cout<<endl;
     endTime = clock();
     elapse = (endTime - startTime) / 1000;  
     cout << "Time Elapsed: " << elapse << endl;
}
