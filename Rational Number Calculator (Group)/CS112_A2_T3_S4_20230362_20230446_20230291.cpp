/*
 FCAI – Structured Programming – 2024 - Assignment 2 - Task 3

 Program Name: CS112_A2_T3_S4_20230362_20230446_20230291.cpp

 Program Description: Rational Number Calculator

 Last Modification Date: 3/11/2024

 Author1 and ID and Group: Mohammad Walid Abdulmotal  -  (20230362)
 Author2 and ID and Group: Nour Maged Mahmoud Abdel-Aal  -  (20230446)
 Author3 and ID and Group: Karen Fady Nabil Tawfik  -  (20230291)

 Teaching Assistant: Eng. Ahmed Fouad Lotfy

 Who did what:

 Mohammad Walid Abdulmotal - Algorithm Code - [Regex] Patterns Library - Color Designing
 Nour Maged Mahmoud Abdel-Aal - [Chunk 1 divide - Chunk 3 divide - Equation] Parts
 Karen Fady Nabil Tawfik - [ + , - , * , / ] Operations
*/

#include <iostream>
#include <string>
#include <regex>
#include <cmath>

#define ll long long
using namespace std;

void fraction();


// Again function to use the app again
void again()
{
  char choice;
  cout << "\nDo you want to use Fraction Number Calculator again? Y or N : ";
  cin >> choice;
  cin.ignore();

  // Loop to handle user input for playing again or exiting
  while (true)
  {
    if (choice == 'Y' || choice == 'y')
    {
      fraction(); // Restart the game
      break;
    }
    else if (choice == 'N' || choice == 'n')
    {
      cout << "\033[1;36m" << "Thank You!" << "\033[0m";
      exit(EXIT_SUCCESS); // Exit the program
    }
    else
    {
      cout << "\033[1;31m" << "Please input a valid input" << "\033[0m" << endl;
      cout << "Do you want to use the Fraction Number Calculator again? Y or N : ";
      cin >> choice;
      cin.ignore();
    }
  }
}
// The fraction function 
void fraction()
{
  // Defining Variables 
  
  int array1;
  string RED = "\033[1;31m";
  string GREEN = "\033[1;32m";
  string RESET = "\033[0m";
  string num1 = "";
  string num2 = "";
  string num3 = "";
  string num4 = "";
  string chunk1 = "";
  string chunk2 = "";
  string chunk3 = "";
  string message = "";

  cout << "\033[1;36m" <<"Enter an Equation (x/y + a/b): " << RESET;

  // Getting the whole equation and validating it 
  
  while (true)
  {
    message = "";
    chunk1 = "";
    chunk2 = "";
    chunk3 = "";
    int array1;

    getline(cin, message);

    for (int i = 0; i < message.length(); i++)
    {

      if (!isspace(message[i]))
      {
        chunk1 += message[i]; // updating chunk1
      }

      else
      {
        array1 = i;
        break;
      }
    }

    for (int i = array1 + 1; i < message.length() - 1; i++)
    {

      if (!isspace(message[i]))
      {
        chunk2 += message[i]; // updating chunk2
      }

      else
      {
        array1 = i;
        break;
      }
    }

    for (int i = array1 + 1; i < message.length(); i++)
    {

      if (!isspace(message[i]))
      {
        chunk3 += message[i]; // updating chunk3
      }

      else
      {
        array1 = i;
        break;
      }
    }

    // Validating the message by using Regex

    if ((!regex_match(chunk1, regex("[\\-, \\+]?\\d+\\/?[\\-, \\+]?(?!0)\\d*"))) || (!regex_match(chunk3, regex("[\\-, \\+]?\\d+\\/?[\\-, \\+]?(?!0)\\d*"))))
    {
      cout << RED << "Invalid operand! Please enter a valid equation: " << RESET;
      cin.clear();
      continue;
    }

    if (!regex_match(chunk2, regex("[\\+,\\-,\\*,\\/]")))
    {
      cout << RED << "Invalid operation! Please enter a valid equation: " << RESET;
      cin.clear();
      continue;
    }

    break;
  }

  //------------------------------------------------------------Chunk 1 divide---------------------------------

  // testcase : 12/34 or 23

  for (int i = 0; i < chunk1.length(); i++)
  {

    if (isdigit(chunk1[i]) || chunk1[i] == '-')
    {
      num1 = num1 + chunk1[i];
    }

    if (i == chunk1.length() - 1)
    {
      num2 = "1";
      break;
    }

    if (chunk1[i] == '/')
    {
      for (int j = i + 1; j < chunk1.length(); j++)
      {
        num2 += chunk1[j];
      }
      break;
    }
  }

  //------------------------------------------------------------Chunk 3 divide---------------------------------

  // testcases : 12/34 or 23

  for (int i = 0; i < chunk3.length(); i++)
  {

    if (isdigit(chunk3[i]) || chunk3[i] == '-')
    {
      num3 = num3 + chunk3[i];
    }

    if (i == chunk3.length() - 1)
    {
      num4 = "1";
      break;
    }

    if (chunk3[i] == '/')
    {
      for (int j = i + 1; j < chunk3.length(); j++)
      {
        num4 += chunk3[j];
      }
      break;
    }
  }

  //----------------------------------------------------Equation-----------------------------------------------

  long double result;

  if (chunk2 == "+")
  {
    result = (stold(num1) / stold(num2)) + (stold(num3) / stold(num4));
  }

  else if (chunk2 == "-")
  {
    result = (stold(num1) / stold(num2)) - (stold(num3) / stold(num4));
  }

  else if (chunk2 == "*")
  {
    result = (stold(num1) / stold(num2)) * (stold(num3) / stold(num4));
  }

  else if (chunk2 == "/")
  {
    result = (stold(num1) / stold(num2)) / (stold(num3) / stold(num4));
  }

  // -------------------------------------------------- +ve operation -----------------------------------------------

  // * 2 denom
  // * first mum and second denom
  // +
  // * second num and first denom
  // result = * first num and second denom+* second num and first denom / * 2 denom

  string fresult = to_string(result);

  //-12/3 - 5 = 9

  long double first_denom = stold(num2);
  long double second_denom = stold(num4);
  long double first_num = stold(num1);
  long double second_num = stold(num3);

  if (chunk2 == "+")
  {
    long double num = (first_num * second_denom) + (second_num * first_denom);
    long double denom = first_denom * second_denom;

    if (num == denom)
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }
    else if (result == round(result))
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }

    else
    {
      cout << endl
           << GREEN << message << " = " << num << "/" << denom << RESET << endl;
    }
  }

  // -------------------------------------------------- -ve operation -----------------------------------------------
  // result = * first num and second denom - * second num and first denom / * 2 denom

  if (chunk2 == "-")
  {
    long double num = (first_num * second_denom) - (second_num * first_denom);
    long double denom = first_denom * second_denom;

    if (num == denom)
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }
    else if (result == round(result))
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }

    else
    {
      cout << endl
           << GREEN << message << " = " << num << "/" << denom << RESET << endl;
    }
  }

  // -------------------------------------------------- * operation -----------------------------------------------
  // *2 num
  // *2 denom
  // result = *2 num / *2 denom

  if (chunk2 == "*")
  {
    long double num = first_num * second_num;
    long double denom = first_denom * second_denom;

    if (num == denom)
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }
    else if (result == round(result))
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }

    else
    {
      cout << endl
           << GREEN << message << " = " << num << "/" << denom << RESET << endl;
    }
  }

  // -------------------------------------------------- / operation -----------------------------------------------
  // changing num to denom
  // 1/2 / 3/4

  if (chunk2 == "/")
  {
    long double num = first_num * second_denom;
    long double denom = first_denom * second_num;

    if (num == denom)
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }
    else if (result == round(result))
    {
      cout << endl
           << GREEN << message << " = ";
      cout << result << RESET;
    }

    else
    {
      cout << endl
           << GREEN << message << " = " << num << "/" << denom << RESET << endl;
    }
  }

  again(); // Calling again() Function
}

int main()
{
  cout << "\033[33m" << "\n*** Welcome to Fraction Number Calculator ***\n" << "\033[0m"<< endl;
  fraction(); // Calling fraction() Function 
}

// -------------------------------------------------- Algorithm ------------------------------------------------

// 1. Start the program.

// 2. Display a welcome message for the Fraction Number Calculator.

// 3. Call the fraction() function.

// 4. fraction() function:
//    a. Define necessary variables including strings for colored text output and input processing.
//    b. Prompt the user to enter an equation in the format (x/y + a/b).
//    c. Validate the input equation using regular expressions, checking for valid operands and operations.
//    d. Split the input equation into three chunks: operand1, operation, and operand2.
//    e. Extract numerator and denominator from operand1 and operand2, handling both whole numbers and fractions.
//    f. Perform the arithmetic operation based on the operation extracted from the equation.
//    g. If the operation is addition or subtraction:
//       - Compute the numerator by cross-multiplying and adding or subtracting as appropriate.
//       - Compute the denominator as the product of the denominators.
//       - Simplify the fraction if possible.
//    h. If the operation is multiplication:
//       - Multiply numerators and denominators separately.
//       - Simplify the fraction if possible.
//    i. If the operation is division:
//       - Swap the numerator and denominator of the second operand.
//       - Perform multiplication.
//    j. Display the result of the operation in fraction form if it's not an integer, else display the result as it is.
//    k. Provide an option for the user to use the Fraction Number Calculator again or exit.

// 5. again() function:
//    a. Prompt the user if they want to use the Fraction Number Calculator again.
//    b. Accept user input and validate.
//    c. If the user chooses to continue, call the fraction() function again.
//    d. If the user chooses to exit, display a thank you message and terminate the program.

// 6. End.
