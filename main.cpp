// Jarl Ramos
// Cross Cipher
// 05/03/2022
//
// Program Name: CrossCipher.cpp
// Description:
// This program demonstrates the "Cross Cipher" concept
// to where a string of text is encrypted has its constituent
// characters stored within four arrays. This will take form
// of a "cross" with each point represented by a distinct
// array. Characters are fed one-by-one in each array in
// clockwise order where the program inserts one character
// each in every array in this order. The array-loading
// process will start at the top-right point of the cross
// going clockwise while outputting the arrays on a single
// line will start at the top-left point of the cross and
// will go counter-clockwise.
//
// A sample cross for the string "Kimberly" is given below:

/*
   * c4 = "by"     * c1 = "Ke"
     *           *
       *       *
         *   *
           *
         *   *  
       *       *
     *           *
   * c3 = "ml"     * c2 = "ir"
                     */

#include <iostream>
using namespace std;

// the number of arrays needed for this encryption algorithm to function
const int MAX_ARR = 4;
const char SP = ' ';
const char TI = '~';

// struct represents both the array containing the input and its size
struct CipherArray
{
    char string[1000];
    // size of only the array items inputted by the user
    int size = 0;
};

// the following function will load the arrays with
// letters from the user-inputted string
void encode(string s, CipherArray & a, CipherArray & b,
            CipherArray & c, CipherArray & d)
{
    // will go through the entire user string
    for (int i = 0; i < s.length(); ++i)
    {
        // a position will be calculated with each
        // passing index, i.e. the char at index 5
        // will go into cipher array b (5 % 4 = 1)
    
        int position = i % MAX_ARR;
        
        // a special case has been made with spaces;
        // they will be represented as tildes in the
        // four arrays
        switch (position)
        {
            case 0:
                if (s[i] != SP)
                {
                    a.string[a.size] = s[i];
                }
                else
                {
                    a.string[a.size] = TI;
                }
                // array size increments with each char addition
                ++a.size;
                break;
            case 1:
                if (s[i] != SP)
                {
                    b.string[b.size] = s[i];
                }
                else
                {
                    b.string[b.size] = TI;
                }
                ++b.size;
                break;
            case 2:
                if (s[i] != SP)
                {
                    c.string[c.size] = s[i];
                }
                else
                {
                    c.string[c.size] = TI;
                }
                ++c.size;
                break;
            case 3:
                if (s[i] != SP)
                {
                    d.string[d.size] = s[i];
                }
                else
                {
                    d.string[d.size] = TI;
                }
                ++d.size;
                break;
        }
    }
}

// this function shows the contents of one of the four arrays
// followed by a space; this will be an integral component to
// the embedded string
void show_cipher_string(CipherArray a)
{
    for (int i = 0; i < a.size; ++i)
    {
        cout << a.string[i];
    }
    cout << " ";
}

int main()
{
    // the string to be encrypted
    string userString;
    
    // the four arrays needed
    CipherArray c1;
    CipherArray c2;
    CipherArray c3;
    CipherArray c4;
    
    cout << "Please enter a string: ";
    cin  >> userString;
    
    cout << endl;
    cout << "Before encryption: " << userString << endl;
    
    encode(userString, c1, c2, c3, c4);
    
    cout << endl;
    // the algorithm dictates that outputting the array contents must
    // start at the top-left point of the cross and go counter-clockwise, which
    // means the correct order is as follows:
    // 4th array -> 3rd array -> 2nd array -> 1st array
    cout << "After encryption: ";
    show_cipher_string(c4);
    show_cipher_string(c3);
    show_cipher_string(c2);
    show_cipher_string(c1);
    cout << endl;
   
    return 0;
}
