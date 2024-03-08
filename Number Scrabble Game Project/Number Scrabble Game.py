# File: CS112_A1_T2_2_20230362.py
# Purpose: (Number scrabble game) is played with the list of numbers between 1 and 9. Each player takes turns picking a number from the list. First player who has picked three numbers that add up to 15 wins.
# Author: Mohammad Walid Abdulmotal
# ID: 20230362


import sys  # Importing sys for sys.exit() function


def number_scrabble():  # Scrabble Game function

    while True:  # for repeating the game

        numbers_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        p1choices = []
        p2choices = []

        for turn in range(1, 10):
            print(numbers_list)

            if turn % 2 != 0:  # First Player's turn
                choice = int(input("Player 1 choose a number:"))

                while choice not in numbers_list:  # Choice number validation
                    print("please enter a valid choice")
                    choice = int(input("Player 1 choose a number:"))

                p1choices.append(choice)  # Adding first player's choice in his list
                numbers_list.remove(choice)  # Removing first player's choice for the numbers list

                if turn > 2:  # checking the sum of the first player's choices
                    for x in range(len(p1choices)):
                        for y in range(x + 1, len(p1choices)):
                            for i in range(y + 1, len(p1choices)):

                                if p1choices[x] + p1choices[y] + p1choices[i] == 15:
                                    print(p1choices[x], '+', p1choices[y], '+', p1choices[i],
                                          '= 15 \nCongrats player 1 you have won!')

                                    while True:  # Asking for playing again and validate his choice

                                        again = input("Do you want to play again? Y or N : ").upper()

                                        if again == 'Y':
                                            number_scrabble()
                                            break
                                        elif again == 'N':
                                            print("*** Thank You For Playing ***")
                                            sys.exit()  # Exit program
                                        else:
                                            print('Please enter a valid choice !')

            if turn % 2 == 0:  # Second Player's turn
                choice = int(input("Player 2 choose a number:"))

                while choice not in numbers_list:  # Choice number validation
                    print("please enter a valid choice")
                    choice = int(input("Player 2 choose a number:"))

                p2choices.append(choice)  # Adding second player's choice in his list
                numbers_list.remove(choice)  # Removing second player's choice for the numbers list

                if turn > 2:  # checking the sum of the second player's choice
                    for x in range(len(p2choices)):
                        for y in range(x + 1, len(p2choices)):
                            for i in range(y + 1, len(p2choices)):

                                if p2choices[x] + p2choices[y] + p2choices[i] == 15:
                                    print(p2choices[x], '+', p2choices[y], '+', p2choices[i],
                                          '= 15 \nCongrats player 2 you have won!')

                                    while True:  # Asking for playing again and validate his choice

                                        again = input("Do you want to play again? Y or N : ").upper()

                                        if again == 'Y':
                                            number_scrabble()
                                            break
                                        elif again == 'N':
                                            print("*** Thank You For Playing ***")
                                            sys.exit()  # Exit program
                                        else:
                                            print('Please enter a valid choice !')

            if turn == 8:  # In Draw condition

                print("It's a draw!")

                while True:  # Asking for playing again and validate his choice

                    again = input("Do you want to play again? Y or N : ").upper()

                    if again == 'Y':
                        number_scrabble()
                        break
                    elif again == 'N':
                        print("*** Thank You For Playing ***")
                        sys.exit()  # Exit program
                    else:
                        print('Please enter a valid choice !')

            print("\nPlayer's 1 number list :", p1choices)  # Displaying Player's 1 number list
            print("Player's 2 number list :", p2choices)  # Displaying Player's 2 number list


print("*** Welcome to Number Scrabble game ***\n")
number_scrabble()  # Calling Scrabble Game function
