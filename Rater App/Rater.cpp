/*

 Program Name: Rater.cpp

 Program Description: Rate movie/tv shows baseed on 5 cat (Cinematography, Acting, Plot, Ending, Music)

 Last Modification Date: 4/17/2024

 Author : Mohammad Walid

 Version : 1.0

*/

#include <iostream>
#include <vector>
#include <numeric>

#include <iomanip>

#define ll long long
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[1m\033[91m";
const string YELLOW = "\033[1m\033[93m";
const string GREEN = "\033[1m\033[38;5;82m";
const string ORANGE = "\033[1m\033[38;5;208m";
const string LIME = "\033[1m\033[38;5;190m";

void again()
{
  string choice;
  cout << "Do you want to calculate again? (Y/N) : ";
  cin >> choice;

  while (choice != "Y" && choice != "y" && choice != "n" && choice != "N")
  {
    cout << "Invalid Choice\nPlease enter a Choice" << endl;
    cout << "Do you want to calculate again? (Y/N) : ";
    cin >> choice;
  }

  if (choice == "Y" || choice == "y")
    return;
  else
  {
    cout << "\n\n*** THANK YOU :> ***";
    exit(EXIT_SUCCESS);
  }
}

double checkValid(double num, string cat)
{
  while (cin.fail() || num < 0 || num > 10)
  {
    cin.clear();
    cin.ignore();
    cout << "Invalid input\nPlease enter a valid positive number from 0 to 10" << endl;
    cout << "Rate the " << cat << " ( /10) : ";
    cin >> num;
    cout << "\n";
  }
  return num;
}

int main()
{
  double num;
  vector<double> total;

  cout << "*** Welcome to Rate Calc ***" << endl;

  while (true)
  {
    // Cinematography
    cout << "\n";
    cout << "Rate the Cinematography ( /10) : ";
    cin >> num;
    num = checkValid(num, "Cinematography");
    total.push_back(num);
    cout << "\n- Cinematography (" << total.at(0) << "/10)\n\n";
    cout << "* The Current Rating is : " << total.at(0) << " / 10\n\n";

    // Acting
    cout << "Rate the Acting ( /10) : ";
    cin >> num;
    num = checkValid(num, "Acting");
    total.push_back(num);
    cout << "\n";
    cout << "- Cinematography (" << total.at(0) << "/10)\n";
    cout << "- Acting (" << total.at(1) << "/10)\n\n";
    cout << "* The Current Rating is : " << reduce(total.begin(), total.end()) / 2.0 << " / 10\n\n";

    // Plot
    cout << "Rate the Plot ( /10) : ";
    cin >> num;
    num = checkValid(num, "Plot");
    total.push_back(num);
    cout << "\n";
    cout << "- Cinematography (" << total.at(0) << "/10)\n";
    cout << "- Acting (" << total.at(1) << "/10)\n";
    cout << "- Plot (" << total.at(2) << "/10)\n\n";
    cout << "* The Current Rating is : " << reduce(total.begin(), total.end()) / 3.0 << " / 10\n\n";

    // Ending
    cout << "Rate the Ending ( /10) : ";
    cin >> num;
    num = checkValid(num, "Ending");
    total.push_back(num);
    cout << "\n";
    cout << "- Cinematography (" << total.at(0) << "/10)\n";
    cout << "- Acting (" << total.at(1) << "/10)\n";
    cout << "- Plot (" << total.at(2) << "/10)\n";
    cout << "- Ending (" << total.at(3) << "/10)\n\n";
    cout << "* The Current Rating is : " << reduce(total.begin(), total.end()) / 4.0 << " / 10\n\n";

    // Music
    cout << "Rate the Music ( /10) : ";
    cin >> num;
    num = checkValid(num, "Music");
    total.push_back(num);
    cout << "\n";
    cout << "- Cinematography (" << total.at(0) << "/10)\n";
    cout << "- Acting (" << total.at(1) << "/10)\n";
    cout << "- Plot (" << total.at(2) << "/10)\n";
    cout << "- Ending (" << total.at(3) << "/10)\n";
    cout << "- Music (" << total.at(4) << "/10)\n\n";

    double finalRating = accumulate(total.begin(), total.end(), 0.0) / 5.0;

    // Determine the color based on the final rating
    string color;
    if (finalRating >= 8)
    {
      color = GREEN;
    }
    else if (finalRating >= 6)
    {
      color = LIME;
    }
    else if (finalRating >= 4)
    {
      color = YELLOW;
    }
    else if (finalRating >= 2)
    {
      color = ORANGE;
    }
    else
    {
      color = RED;
    }

    
    cout <<"\033[40m\033[97m" <<"The Final Rating is: " << color << setprecision(2) << finalRating << " /10" << RESET << "\n\n";

    total.clear();
    again();
  }
  return 0;
}

/*
Cinematography
acting
plot
ending
music
*/