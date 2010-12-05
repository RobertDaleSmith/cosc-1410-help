//Using letters as indicies

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main ()
{
    char line[1000], ch;
    int count[26][2];
    int size=0, i;
    
    for (i=0; i<26 ;i++)
    {
        count[i][0]='a'+i;
        count[i][0];
    }
    cin.get(ch);
    while (ch != '\n') 
    {
        cout << ch;
        line[size++]=ch;
        if (isalpha(ch))
        {
           count[ch-'a'][1]++;
        }
        cin.get(ch);
    }
    cout <<"\n\nSize = " << size << endl;
    for (int i=0; i<26; i++)
    {
       // cout << static_cast<char>(count[i][0])<<" "<<count[];
        cin.get(ch);
        
    }
    system("pause");
    return EXIT_SUCCESS;
}
