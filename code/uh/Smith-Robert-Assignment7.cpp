//  Assignment 7: 2-Dimensional Arrays            COSC 1410 Mon-Thur 1PM-2:30PM 
//  By: Robert D. Smith
//                
//  Description:  In this assignment, you will implement the Vigenere cipher. 
//                The Vigenere cipher will encrypt a plaintext message by 
//                shifting its letters. The number of times each letter gets 
//                shifted is determined by the keyword. For this assignment, 
//                encryption must be executed by means of a Vigenere table.
//  
     
#include <iostream>


using namespace std;

//Function PROTOTYPES
void init_vigenere_table(char vigenere_table[27][27],char alphabet[]);
void disp_vigenere_table(char vigenere_table[27][27]);
void encrypt(char plaintext[],char keyword[],char ciphertext[], 
             char vigenere_table[27][27]);
void shift(char alphabet[]);
void init_key(char keyword[]);
void disp_array(char array[]);
bool question();


//Main Program FUNCTION
int main()
{   
    //Main VARIABLES
    char alphabet[27] = {'a','b','c','d','e','f','g','h','i',
                         'j','k','l','m','n','o','p','q','r',
                         's','t','u','v','w','x','y','z',' '};
    char vigenere_table[27][27];
    char plaintext[20];    
    char keyword[20];
    char ciphertext[20];

    //Initialize Vigenere Table
    init_vigenere_table(vigenere_table, alphabet);
    
    //Get Plaintext
    cout << "                                  [....................]\n";
    cout << "Input any plaintext of length 20:  ";
    cin.getline( plaintext, 21, '\n');
    
    //Get Keyword
    cout << "                                  [...]\n";
    cout << "Input any keyword of length 3:     ";
    cin.getline( keyword, 4, '\n');
    
    //Build Full Key
    init_key(keyword);

    //Build Cipher
    encrypt(plaintext, keyword, ciphertext, vigenere_table);

    //Display Results
    cout << "\nPlaintext:     [ ";    disp_array(plaintext);     cout << " ]";
    cout << "\nFull Key:      [ ";    disp_array(keyword);       cout << " ]";
    cout << "\nCiphertext:    [ ";    disp_array(ciphertext);    cout << " ]";
    
    //Ask If User wants to display the Vigenere Table.
    cout << "\n\nWould you like to see the Vigenere Table? (Y/N) ";
    if(question())
      disp_vigenere_table(vigenere_table);
    
    //End Program
    cout << "\n\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}



//Initialize Vigenere Table FUNCTION
void init_vigenere_table(char vigenere_table[27][27],char alphabet[])
{  
    int n, x, y;
    for (x = 0 ; x < 27 ; x++)
    {
        for (y = 0 ; y < 27 ; y++)
        {
            vigenere_table[x][y] = alphabet[x];
            shift(alphabet);
        }
    }
}

//Display Vigenere Table FUNCTION
void disp_vigenere_table(char vigenere_table[27][27])
{
    int x,y;
    for (x = 0 ; x < 27 ; x++)
    {
        for (y = 0 ; y < 27 ; y++)
        {
            cout << vigenere_table[x][y] << " ";
        }
        cout << endl;
    }
}

//Alphabet Shift FUNCTION
void shift(char alphabet[])
{
    int n, x, y;
    n = alphabet[0];
    for (x = 0 ; x < 27 ; x++)
    {
        y = x + 1;
        alphabet[x] = alphabet[y];
    }
    alphabet[26] = n;
}

//Encryption FUNCTION
void encrypt(char plaintext[],char keyword[],char ciphertext[], 
             char vigenere_table[27][27])
{
    int n, x, y;
    for (n = 0; n < 20 ; n++)
        {
            for (x = 0; x < 27 ; x++)
            {   
                if ( vigenere_table[0][x] == plaintext[n] )
                   break;
            } 
            for (y = 0; y < 27 ; y++)
            {   
                if ( vigenere_table[y][0] == keyword[n] )
                   break;
            }
            ciphertext[n] = vigenere_table[x][y];
        }
}

//Initialize Full Key FUNCTION
void init_key(char keyword[])
{
    int x, y;
    for (x = 3, y = 0; x < 20 ; x++, y++)
    {       
        keyword[x] = keyword[y];
    }   
}

//Display Arrays FUNCTION
void disp_array(char array[])
{
    int x;
    for (x = 0 ; x < 20 ; x++)
    {
        cout << array[x];
    }
}

//Question FUNCTION
bool question()
{
     int sentinelInt;
     char questionChar;
     do{
        sentinelInt = 1;
        cin  >> questionChar;
        questionChar = toupper(questionChar);
        cout << "\n";
        if (questionChar == 'Y' || questionChar == 'N')
           {
               if (questionChar == 'N')
                   return 0;       
               if (questionChar == 'Y')
                   return 1;
               sentinelInt = 1;
           }   
        else   
           {   
               cout << "\n Please enter only (y/n) answer.  ";
               sentinelInt = 0;
           }
     } while (sentinelInt == 0); 
}
