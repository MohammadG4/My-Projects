#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

#define ll long long
using namespace std;

// Function declarations
string atbash2(string Pmessage);
string atbash1(string Pmessage);
void again1();
void encrypt();
void decrypt();
void menu1();

// Function to ask players if they want to play again
void again1()
{
    char choice;
    cout << "Do you want to use Atbash cipher again? Y or N : ";
    cin >> choice;

    // Loop to handle user input for playing again or exiting
    while (true)
    {
        if (choice == 'Y' || choice == 'y')
        {
            menu1(); // Restart the game
            break;
        }
        else if (choice == 'N' || choice == 'n')
        {
            exit(EXIT_SUCCESS); // Exit the program
        }
        else
        {
            cout << "Please input a valid input" << endl;
            cout << "Do you want to use the Cipher again? Y or N : ";
            cin >> choice;
        }
    }
}

// Function to perform Atbash Version 2 encryption
string atbash2(string Pmessage)
{

    string Emessage;

    // Atbash Version 2 cipher key
    string atbash_str = "MLKJIHGFEDCBAZYXWVUTSRQPONmlkjihgfedcbazyxwvutsrqpon";
    string main_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Loop through each character in the input message
    for (char i : Pmessage)
    {
        if (isalpha(i))
        {
            // Find the position of the character in the main string and replace it with the corresponding character from the Atbash key
            int position = main_str.find(i);
            Emessage += toupper(atbash_str[position]); // Convert to uppercase
        }
        else
        {
            continue; // Skip non-alphabetic characters
        }
    }
    return (Emessage);
}

// Function to perform Atbash Version 1 encryption
string atbash1(string Pmessage)
{

    string Emessage;

    // Atbash Version 1 cipher key
    string atbash_str = "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba";
    string main_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Loop through each character in the input message
    for (char i : Pmessage)
    {
        if (isalpha(i))
        {
            // Find the position of the character in the main string and replace it with the corresponding character from the Atbash key
            int position = main_str.find(i);
            Emessage += toupper(atbash_str[position]); // Convert to uppercase
        }
        else
        {
            continue; // Skip non-alphabetic characters
        }
    }

    return (Emessage);
    // Display original and encrypted messages
}

// Function  encrypt 
void encrypt()
{
    cout << "Which Version: \nA) Atbash encrypted Version 1 \nB) Atbash encrypted Version 2" << endl;

    // Loop until a valid version is selected
    while (true)
    {
        string ver, result, Pmessage;
        cin >> ver;
        if (ver == "A" || ver == "a")
        {
            cout << "Enter message you want to Encrypt: ";

            cin.ignore();
            getline(cin, Pmessage);

            result = atbash1(Pmessage); // Perform Atbash Version 1 encryption

            // Display original and encrypted messages
            cout << "\nPlain message: " << Pmessage << endl;
            cout << "Encrypted message: " << result << endl;

            break;
        }
        else if (ver == "B" || ver == "b")
        {
            cout << "Enter message you want to Encrypt: ";

            cin.ignore();
            getline(cin, Pmessage);
            result = atbash2(Pmessage); // Perform Atbash Version 2 encryption

            // Display original and encrypted messages
            cout << "\nPlain message: " << Pmessage << endl;
            cout << "Encrypted message: " << result << endl;
            break;
        }
        else
        {
            cout << "\nInvalid Input! Please enter a valid choice\nWhich Version: ";
        }
    }
}

// Function  decrypt 
void decrypt()
{
    cout << "Which Version: \nA) Atbash decryption Version 1 \nB) Atbash decryption Version 2" << endl;

    // Loop until a valid version is selected
    while (true)
    {
        string ver, result, Pmessage;
        cin >> ver;
        if (ver == "A" || ver == "a")
        {
            cout << "Enter message you want to Decrypt: ";

            cin.ignore();
            getline(cin, Pmessage);

            result = atbash1(Pmessage); // Perform Atbash Version 1 Decryption

            // Display  Encrypted  and Decrypted messages
            cout << "\nEncrypted message: " << Pmessage << endl;
            cout << "Decrypted message: " << result << endl;

            break;
        }
        else if (ver == "B" || ver == "b")
        {
            cout << "Enter message you want to Decrypt: ";

            cin.ignore();
            getline(cin, Pmessage);
            result = atbash2(Pmessage); // Perform Atbash Version 2 Decryption

            // Display  Encrypted  and Decrypted messages
            cout << "\nEncrypted message: " << Pmessage << endl;
            cout << "Decrypted message: " << result << endl;
            break;
        }
        else
        {
            cout << "\nInvalid Input! Please enter a valid choice\nWhich Version: ";
        }
    }
}

// Function to handle user menu selection
void menu1()
{
    string choice;

    // Display menu options
    cout << "What do you want to do: \nA) Atbash Cipher \nB) Atbash Decipher \nC) Exit" << endl;

    // Loop until a valid choice is made
    while (true)
    {
        cin >> choice;
        if (choice == "A" || choice == "a")
        {
            encrypt(); // Perform encryption
            again1();   // Ask if the user wants to play again
            break;
        }
        else if (choice == "B" || choice == "b")
        {
            decrypt(); // Perform encryption (same as decryption in this case)
            again1();   // Ask if the user wants to play again
            break;
        }
        else if (choice == "C" || choice == "c")
        {
            cout << "Thank you for using Atbash Cipher!\n";
            exit(EXIT_SUCCESS); // Exit the program
        }
        else
        {
            cout << "\nInvalid Input! Please enter a valid choice\nChoose A/B/C: ";
        }
    }
}

// Main function
int main()
{
    string ver;
    cout << "*** Welcome to Atbash Cipher ***\n\n";
    menu1();
    return 0;
}
