/*
	Creator: Abdullah Gunay 
*/
#include <iostream>
#include <string>
using namespace std;

typedef unsigned int ui;

template <typename XOR> //templated function xor encryption
void xor_encryption(ui* message_array, XOR key, int no_ints, ui*& ciphertext, ui*& plaintext)
{
    ui newk = 0; //newk is the new form of the key which will be represented in 32 bits for xor encryption
    newk = newk | (ui)key;

    for (int i = 0; i < sizeof(int) - sizeof(XOR); i++) // shifting key to create 32-bit newk which will be used in encryption and decryption
    {
        newk = newk << (sizeof(XOR) * 8);
        newk = newk | (ui)key;
    }

    ciphertext = new ui[no_ints]; // memory allocation for ciphertext array

    for (int i = 0; i < no_ints; i++) // encryption of the message array. xor'ing each element of message array with newk
    {
        ciphertext[i] = message_array[i] ^ newk;
    }

    cout << "Ciphertext is: ";
    for (int i = 0; i < no_ints; i++) //printing ciphertext by simply printing each element in array
    {
        cout << ciphertext[i] << " ";
    }
    cout << endl;

    plaintext = new ui[no_ints]; // memory allocation for plaintext array

    for (int i = 0; i < no_ints; i++) // decryption of the ciphertext. xor'ing each element of the ciphertext with newk
    {
        plaintext[i] = ciphertext[i] ^ newk;
    }

    cout << "Plaintext is: ";
    for (int i = 0; i < no_ints; i++) //printing plaintext by simply printing each element in array
    {
        cout << plaintext[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "\nJust for FYI --------------------------" << endl;
    cout << "size of unsigned char is " << sizeof(char) << endl;
    cout << "size of unsigned short is " << sizeof(short) << endl;
    cout << "size of unsigned int is " << sizeof(int) << endl;
    cout << "---------------------------------------\n\n\n";

    ui* message_array;
    ui* ciphertext;
    ui* plaintext;

    cout << "Size of the message array is ";
    ui no_ints;
    cin >> no_ints;
    message_array = new ui[no_ints];
    cout << "Enter the message array integers one after another by pressing enter after each number:" << endl;
    for (int i = 0; i < no_ints; i++) {
        cin >> message_array[i];
    }
    cout << "Type of key is unsigned ";
    string key_type;
    cin >> key_type;

    if (key_type == "char") {
        unsigned char ch;
        cout << "The value of the key is ";
        cin >> ch;
        xor_encryption(message_array, ch, no_ints, ciphertext, plaintext);
    }
    else if (key_type == "short") {
        unsigned short num;
        cout << "The value of the key is ";
        cin >> num;
        xor_encryption(message_array, num, no_ints, ciphertext, plaintext);
    }
    else if (key_type == "int") {
        ui x;
        cout << "The value of the key is ";
        cin >> x;
        xor_encryption(message_array, x, no_ints, ciphertext, plaintext);
    }
    else { //if key_type is different than int/short/char, the program will close
        cout << "You entered a different type other than int/short/char" << endl;
        return 0;
    }

    cin.get();
    delete[] message_array; //need to free memory allocated for message array in order to prevent memory leak
    delete[] ciphertext; //need to free memory allocated for ciphertext array in order to prevent memory leak
    delete[] plaintext; //need to free memory allocated for plaintext array in order to prevent memory leak
    return 0;
}
