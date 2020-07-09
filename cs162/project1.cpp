/*
Kyle Zhang
CS 162
6/22/2020

Project 1: Shopper Calculator Solution :)
Sources: None
*/
#include <iostream>

using namespace std;

// // Display Conventions that aren't needed
// cout.setf(ios::fixed, ios::floatfield);
// cout.setf(ios::showpoint);
// cout.precision(2);

const int MAX_CHARS = 101;

// Function Declaration
int getInt();
int getIntInRange(int min, int max);
void enterAProductName();
int getDollarCost();
int getCentCost();
void getString(char string[], int maxChars);
void enterAProductName(char name[]);
void wantToChangeAnythingElse();

int main() {
  char productName[MAX_CHARS];
  int response = 1; // response 0 means quit, 1 means proceed/certain
  int costDollars;
  int costCents;
  double cost;
  double grandTotal = 0;

  cout << "Welcome to Kyle's Shopper Calculator!" << endl;

  while (response != 0) {
    enterAProductName(productName);
    costDollars = getDollarCost();
    costCents = getCentCost();
    // Format issues, need to add 0 for cents less than 10
    if (costCents >= 10) {
      cout << "Are you certain of the purchase of: " << endl
           << productName << " with a cost of $" << costDollars << "."
           << costCents << "?" << endl;
    } else {
      cout << "Are you certain of the purchase of: " << endl
           << productName << " with a cost of $" << costDollars << ".0"
           << costCents << "?" << endl;
    }
    cout << "Type a number: Certain (1), Changing the Product Name (2), Dollar "
            "cost (3), cent cost (4)? ";
    response = getIntInRange(1, 4);

    while (response != 1) {
      if (response == 2) {
        cout << "You have chosen to change the product's name." << endl;
        enterAProductName(productName);
        if (costCents >= 10) {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << "."
               << costCents << "?" << endl;
        } else {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << ".0"
               << costCents << "?" << endl;
        }
        wantToChangeAnythingElse();
        response = getIntInRange(1, 4);
      }
      if (response == 3) {
        cout << "You have chosen to change the product's dollar cost." << endl;
        costDollars = getDollarCost();
        if (costCents >= 10) {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << "."
               << costCents << "?" << endl;
        } else {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << ".0"
               << costCents << "?" << endl;
        }
        wantToChangeAnythingElse();
        response = getIntInRange(1, 4);
      }
      if (response == 4) {
        cout << "You have chosen to change the product's cents cost." << endl;
        costCents = getCentCost();
        if (costCents >= 10) {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << "."
               << costCents << "?" << endl;
        } else {
          cout << "Are you certain of the purchase of: " << endl
               << productName << " with a cost of $" << costDollars << ".0"
               << costCents << "?" << endl;
        }
        wantToChangeAnythingElse();
        response = getIntInRange(1, 4);
      }
    }
    // calculate cost of the product and add to sum
    cost = costDollars + static_cast<double>(costCents) / 100;
    grandTotal += cost;

    cout << "Do you wish to check out (0) or enter another product into your "
            "shopping cart (1)? Type a number: ";
    response = getIntInRange(0, 1);
  }
  cout << "Your grand total is: $" << grandTotal << endl;
  cout << "Thanks for using my shopping calculator!" << endl;

  return 0;
}

void wantToChangeAnythingElse() {
  cout << "Do you wish to change anything else? Type a number: Certain(1),"
          " Changing the Product Name (2), Dollar "
          "cost (3), cent cost (4)? ";
}

void enterAProductName(char name[]) {
  cout << "Enter a product's name: ";
  getString(name, MAX_CHARS);
}

int getInt() {
  int num;

  cin >> num;
  while (!cin) {
    cin.clear();
    cin.ignore(MAX_CHARS, '\n');

    cout << "You entered an illegal number. Please try again: ";
    cin >> num;
  }
  cin.ignore(MAX_CHARS, '\n');
  return num;
}

int getIntInRange(int min, int max) {
  int num;

  num = getInt();
  while (num < min || num > max) {
    cout << "The number must be between (inclusive) " << min << " and " << max
         << endl;
    cout << "Please try again: ";
    num = getInt();
  }
  return num;
}

int getCentCost() {
  int cost;
  int min = 0;
  int max = 99;

  cout << "Please enter the product's cent cost: ";
  cost = getInt();
  while (cost < min || cost > max) {
    cout << "The cent cost must be between (inclusive) " << min << " and "
         << max << endl;
    cout << "Please try again: ";
    cost = getInt();
  }
  return cost;
}

int getDollarCost() {
  int cost;
  int min = 0;

  cout << "Please enter the product's dollar cost: ";
  cost = getInt();
  while (cost < min) {
    cout << "The dollar cost mustn't be less " << min << endl;
    cout << "Please try again: ";
    cost = getInt();
  }
  return cost;
}

void getString(char string[], int maxChars) {
  cin.get(string, maxChars, '\n');
  while (!cin) {
    cin.clear();
    cin.ignore(maxChars, '\n');

    cout << "You forgot to enter in something! Please try again: ";
    cin.get(string, maxChars, '\n');
  }
  cin.ignore(maxChars, '\n');
}
