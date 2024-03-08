// Program: Number Scrabble game - Game 2 - C++ version
// Author: Mohammad Walid Abdulmotal - 20230362
// Version: 2.0
// Date: 28/2/2024

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <array>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>

#define ll long long
using namespace std;

void again();


void number_scrabble() // main function
{
    while (true)
    {
        list<int> numbers_list = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //initialinzing the number list
        list<int> p1choices; //initialinzing the Player's 1 list
        list<int> p2choices; //initialinzing the Player's 2 list

        for (int turn = 1; turn <= 9; ++turn)
        {
            int choice;
            cout << "Numbers List: { ";

            
            for (int num : numbers_list) // Displaying the current number list
            {
                cout << num << " ";
            }

            cout << "}" << endl;

            if (turn % 2 != 0) // Player 1's turn
            {
                cout << "Player 1 choose a number: ";
                cin >> choice;

                while (find(numbers_list.begin(), numbers_list.end(), choice) == numbers_list.end()) // Validate the input
                {
                    cout << "Please enter a valid choice" << endl;
                    cout << "Player 1 choose a number: ";
                    cin >> choice;
                }

                p1choices.push_back(choice); // add the choosen number in player's list 
                numbers_list.remove(choice); // remove the choosen number form the main number's list

                
                if (p1choices.size() >= 3) // Check if Player 1 has selected three numbers that add up to 15
                {
                    for (ll x : p1choices)
                    {
                        for (ll y : p1choices)
                        {
                            if (x == y)
                            {
                                continue;
                            }
                            for (ll i : p1choices)
                            {
                                if (i == y || i == x)
                                {
                                    continue;
                                }
                                if (x + y + i == 15) // check if player wins
                                {
                                    cout << x << " + " << y << " + " << i << " = 15 \nCongrats player 1 you have won!\n"; 
                                    again(); // Ask if players want to play again
                                }
                            }
                        }
                    }
                }
            }

            if (turn % 2 == 0) // Player 2's turn
            {
                cout << "Player 2 choose a number: ";
                cin >> choice;

                while (find(numbers_list.begin(), numbers_list.end(), choice) == numbers_list.end()) // Validate the input
                {
                    cout << "Please enter a valid choice" << endl;
                    cout << "Player 2 choose a number: ";
                    cin >> choice;
                }

                p2choices.push_back(choice); // add the choosen number in player's list 
                numbers_list.remove(choice); // remove the choosen number form the main number's list

                
                if (p2choices.size() >= 3) // Check if Player 2 has selected three numbers that add up to 15
                {
                    for (ll x : p2choices)
                    {
                        for (ll y : p2choices)
                        {
                            if (x == y)
                            {
                                continue;
                            }
                            for (ll i : p2choices)
                            {
                                if (x + y + i == 15)
                                {
                                    cout << x << " + " << y << " + " << i << " = 15 \nCongrats player 2 you have won!\n";
                                    again(); // Ask if players want to play again
                                }
                            }
                        }
                    }
                }
            }

            if (turn == 9) // draw condition
            {
                cout << "\nIt is a draw!\n"
                     << endl;
                again(); // Ask if players want to play again
            }

            cout << "\nPlayer's 1 number list: { "; //Display Player 1's list
            for (int num : p1choices)
            {
                cout << num << " ";
            }
            cout << "}" << endl;

            cout << "Player's 2 number list: { "; //  and Player 2's list
            for (int num : p2choices)
            {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }
}


void again() // Function to ask players if they want to play again
{
    void number_scrabble();
    char choice;
    cout << "Do you want to play again? Y or N : ";
    cin >> choice;
    while (true)
    {
        if (choice == 'Y' || choice == 'y')
        {
            number_scrabble(); // Restart the game
            break;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Thank you for playing!";
            exit(EXIT_SUCCESS); // Exit the program
        }
        else
        {
            cout << "Please input a valid input" << endl;
            cout << "Do you want to play again? Y or N : ";
            cin >> choice;
        }
    }
}

// Main function
int main()
{
    cout << "*** Welcome to Number Scrabble game ***\n"
         << endl;
    number_scrabble(); // Start the number scrabble game

    return 0;
}
