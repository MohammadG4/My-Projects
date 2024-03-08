# Program:Assignment 1 Task 3
# Authors:
       # Mohammed Walid Abdulmotal - 20230362 - Problem 3 & 4
       # Nour Maged Mahmoud - 20230446 - Problem 1 & 6
       # Karen Fady Nabil - 20230291 - Problem 2 & 5
# Version: 3.0
# Date: 24/2/2024

def problem1():
    def again1():  # to make the user choose if he calculates again or exit the program
        user_choice = input("A) Calculate a new grade\nB) Main Menu\n").upper()
        while user_choice != "A" and user_choice != "B":  # to validate the choice
            user_choice = input("invalid choice\nA) Calculate new grade\nB) Main Menu\n").upper()
        if user_choice == "A":  # to restart the program if user choose this option
            grade_calculator()
        else:
            menu()

    def grade_calculator():
        while True:
            try:  # to make sure that user enter a float value
                mark = float(input("Enter your mark: "))
                while mark < 0 or mark > 100:  # choose the range where mark should be
                    mark = float(input("invalid number\nPlease enter your mark: "))
                break
            except ValueError:  # runs when user enter a not integer value
                print("invalid number")
        if mark >= 96:
            print("Your grade is A+")
        elif mark < 96 and mark >= 92.5:
            print("Your grade is A")
        elif mark < 92.5 and mark >= 90:
            print("Your grade is A-")
        elif mark < 90 and mark >= 87.5:
            print("Your grade is B+")
        elif mark < 87.5 and mark >= 82.5:
            print("Your grade is B")
        elif mark < 82.5 and mark >= 80:
            print("Your grade is B-")
        elif mark < 80 and mark >= 77.5:
            print("Your grade is C+")
        elif mark < 77.5 and mark >= 72.5:
            print("Your grade is C")
        elif mark < 72.5 and mark >= 70:
            print("Your grade is C-")
        elif mark < 70 and mark >= 67.5:
            print("Your grade is D+")
        elif mark < 67.5 and mark >= 62.5:
            print("Your grade is D")
        elif mark < 62.5 and mark >= 60:
            print("Your grade is D-")
        elif mark < 60:
            print("Your grade is F")
        again1()

    print("*** Welcome to our Grade Calculator ***")  # welcome message
    grade_calculator()


def problem2():
    print("*** Welcome to Armstrong Number Checker ***")  # welcome message
    flag = "Y"

    while flag == "Y":  # for repeating the program if user wanted

        number = int(input("Please Enter a positive Integer \n"))

        while number < 0:  # for validating the input
            print("==== Invalid Input ====")
            number = int(input("Please Enter a positive Integer \n"))

        digits = [int(digit) for digit in
                  str(number)]  # for making a list to take every digit from the number the user provided

        result = 0

        for digit in digits:  # loop to multiply the number
            result += digit ** len(digits)

        if (result == number):  # condition to determine if itss armstrong number or not
            print("The number is an Armstrong number")

        elif (result != number):
            print("The number isn't an Armstrong number")

        flag = input("If you want to continue enter Y else type N \n").upper()

        if flag == "N":
            menu()
            break

        elif flag != "Y":
            print("==== Invalid input ====")
            flag = input("Please Enter a Valid Choice \n").upper()


def problem3():
    def again3():
        while True:
            try:  # validating the input
                choice = int(input("1) Calculate Again\n2) Main Menu\n"))  # asking for calculating again if user wanted
                if choice == 1:
                    calc()
                    break
                elif choice == 2:
                    menu()  # returning to main menu
                else:
                    print("Please Enter a valid input")
            except ValueError:  # runs if user entered a not integer number
                print("Please Enter a valid input")

    def calc():
        while True:
            try:  # for validating the input
                no_terms = int(input("Enter number of terms: "))
                while no_terms <= 0:  # validating number of inputs
                    print("invalid input")
                    no_terms = int(input("Enter number of terms: "))  # input again
                x = 1  # initializing X = 1
                term_sum = 0  # initializing term_sum = 1
                for n in range(1, no_terms + 1):
                    term_val = (-1) ** (n - 1) * float(1 / x)  # Calculating every term
                    term_sum = term_sum + term_val  # adding it to term_sum
                    x += 2  # adding 2 for always odd
                print("Pi value is :", term_sum * 4)
                again3()  # calling again function
                break
            except ValueError:  # runs when user enter a not integer value
                print("invalid input")

    print("*** Welcome to Pi Calculator ***")
    calc()


def problem4():
    def again4():
        while True:
            try:  # for validating the input
                choice = int(input("1) Encrypt again \n2) Main Menu\n"))  # asking for encrypting again if user wanted
                if choice == 1:
                    encryption()
                    break
                elif choice == 2:
                    menu()  # returning to main menu
                else:
                    print("Please Enter a valid input")
            except ValueError:  # runs when user enter a not integer value
                print("Please Enter a valid input")

    def encryption():
        while True:
            try:
                user_str = str(input("Enter your string: "))  # input users string
                result = ""  # initiallizing result string
                for n in range(len(user_str)):
                    asc_val = ord(user_str[n])  # get ascii code for every character

                    if asc_val == 32 or 33 <= asc_val <= 64 or 91 <= asc_val <= 96 or 123 <= asc_val <= 155:  # skiping symbols and numbers
                        res_chr = chr(asc_val)  # return character from its ascii code
                    else:
                        res_chr = chr(asc_val + 1)  # return character from its ascii code + 1

                    if asc_val == 90:  # z ---> a
                        res_chr = chr(65)
                    elif asc_val == 122:  # Z--->A
                        res_chr = chr(97)

                    result = result + res_chr  # adding it as a string

                print(result)  # printing final result
                again4()
                break
            except ValueError:  # runs when user enter a not integer value
                print("invalid input")

    print("*** Welcome to Encryption Program ***")
    encryption()


def problem5():

    def again5():

        user_choice = input("A) Check a new list\nB) Main Menu\n").upper()

        while user_choice != "A" and user_choice != "B":  # Validate user input
            user_choice = input("Invalid choice\nA) Check a new list\nB) Main Menu\n").upper()

        if user_choice == "A":
            sorting()
        else:
            menu()  # returning to main menu

    def array_sort(arr):  # To sort the array in ascending order
        n = len(arr)
        for i in range(n):
            for j in range(0, n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Swap the elements if they are in wrong sort

    def sorting():

        while True:  # Get numbers from the user
            try:
                count = int(input("How many numbers are there in the lists? \n"))
                while count <= 1:
                    count = int(input("Invalid input!\nHow many numbers are there in the lists? \n"))
                break
            except ValueError:
                print("Invalid input!")

        numbers1_list = []  # initializing numbers1_list[]
        numbers2_list = []  # initializing numbers2_list[]

        # Get numbers for the first list
        for i in range(count):
            while True:
                try:
                    numbers1 = int(input("Enter a number for the first list \n"))
                    break
                except ValueError:
                    print("Invalid input!")

            numbers1_list.append(numbers1)

        # Get numbers for the second list
        for i in range(count):
            while True:
                try:
                    numbers2 = int(input("Enter a number for the second list \n"))
                    break
                except ValueError:
                    print("Invalid input!")

            numbers2_list.append(numbers2)

        # calling sort function to sort list
        array_sort(numbers1_list)
        array_sort(numbers2_list)

        if numbers1_list == numbers2_list:  # see if they equal each other
            print("Lists are equal = True")
        else:
            print("Lists are equal = False")

        again5()  # call again menu

    print("*** Welcome to Equality list Checker Program ***")
    sorting()


def problem6():
    def again6():
        choice = input(
            "\nA) Enter a new number\nB) Main Menu\n").upper()  # to make the user choose if he calculates again or exit the program
        while choice != "A" and choice != "B":  # to validate the choice
            choice = input("invalid choice\nA) Enter a new number\nB) Main Menu\n").upper()
        if choice == "A":  # to restart the program if user choose this option
            calculator()
        else:
            menu()

    def calculator():
        while True:
            try:  # to make sure that user enter an int value
                num = int(input("Enter your number: "))
                print("number factors are:", end=" ")
                for i in range(1, num + 1):
                    if num % i == 0:
                        print(i, end=' ')
                break
            except ValueError:  # runs when user enter a not integer value
                print("invalid")
        again6()

    print("*** Welcome to Number Factors Calculator ***")
    calculator()


def menu():
    choice = input(
        "choose the problem:\nA) Problem 1  ( Grade Calculator )\nB) Problem 2  ( Armstrong Number Checker )\nC) Problem 3  ( Pi Calculator )\nD) Problem 4  ( Encryption Program )\nE) Problem 5  ( Equality list Checker Program )\nF) Problem 6  ( Number Factors Calculator )\nG) Exit\n").upper()

    while choice != "A" and choice != "B" and choice != "C" and choice != "D" and choice != "E" and choice != "F" and choice != "G":
        print("Invalid choice!")
        choice = input(
            "choose the problem:\nA) Problem 1  ( Grade Calculator )\nB) Problem 2  ( Armstrong Number Checker )\nC) Problem 3  ( Pi Calculator )\nD) Problem 4  ( Encryption Program )\nE) Problem 5  ( Equality list Checker Program )\nF) Problem 6  ( Number Factors Calculator )\nG) Exit\n").upper()

    if choice == "A":
        problem1()
    elif choice == "B":
        problem2()
    elif choice == "C":
        problem3()
    elif choice == "D":
        problem4()
    elif choice == "E":
        problem5()
    elif choice == "F":
        problem6()
    elif choice == "G":
        print("Thank you!")
        exit()


print("*** Welcome to Task 3 Program ***")
menu()
