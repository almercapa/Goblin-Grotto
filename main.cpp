#include "GetValid.h"
#include "Grotto.h"
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Declaring starting variables + object
  int option;
  bool vip = false;
  Grotto customer;
  // Introduction + Login
  cout << "Welcome to Gobbler Goblin Grotto! Try one of our petite delights or chase after the heavily revered title; the Greatest Gobbler!" << endl;
  cout << "1. Sign in as VIP member" << endl;
  cout << "2. Proceed as guest" << endl;
  // Error Trapping with do-while loop
  do {
    cout << "What would you like to do?" << endl;
  } while ((!(getValidInt(option)) || (option > 2) || (option <= 0)));
  // Logging in using login method
  vip = customer.login(option, vip);
  if (option == 1 && vip == true) {
    string dummy;
    getline(cin, dummy);
  }
  cout << endl;
  // Sets the user's 5 attributes
  customer.setAttributes();
  
  // Order variables
  vector<string> items;
  int order = 0;
  double stotal = 0;
  // ORDER
  // While loop until order is complete
  while (order != 6) {
    // Listing 5 options + check out
    cout << endl;
    cout << "1. Fun Size Glizzy: $4.99" << endl;
    cout << "2. King Size Glizzy: $14.99" << endl;
    cout << "3. Smooth Glizzy: $7.99" << endl;
    cout << "4. Petite Delight: $2.55" << endl;
    cout << "5. Gobblin's Special: $10 (BEST DEAL)" << endl;
    cout << "6. Check out" << endl;
    do {
      cout << "What would you like to order?" << endl;
    } while ((!(getValidInt(order)) || (order > 6) || (order <= 0)));

    // If statements for each option
    if (order == 1) {
      cout << "Fun Size Glizzy has been added to your order!" << endl;
      // Adds item to vector (vector contains all items ordered)
      items.push_back("Fun Size Glizzy");
      // Adds price of item to subtotal
      stotal += 4.99;
    }
    if (order == 2) {
      cout << "King Size Glizzy has been added to your order!" << endl;
      items.push_back("King Size Glizzy");
      stotal += 14.99;
    }
    if (order == 3) {
      cout << "Smooth Glizzy has been added to your order!" << endl;
      items.push_back("Smooth Glizzy");
      stotal += 7.99;
    }
    if (order == 4) {
      cout << "Petite Delight has been added to your order!" << endl;
      items.push_back("Petite Delight");
      stotal += 2.55;
    }
    if (order == 5) {
      cout << "Gobblin's Special has been added to your order!" << endl;
      items.push_back("Gobblin's Special");
      stotal += 10;
    }
  }
  // Calculates tax using New York sales (4%)
  double tax = stotal * 0.04;
  // Calculates total by adding subtotal and tax
  double total = stotal + tax;
  // Applies 15% discount if user is VIP member
  if (vip == true) {
    total -= (total * 0.15); 
  }

  // BILL
  cout << endl << "Gobbler Goblin Grotto Order:" << endl;
  // Method to print attributes
  customer.listAttributes();
  // If statements to list discount status
  if (vip == true) {
    cout << "Discount: 15%" << endl;
  } else {
    cout << "Discount: None" << endl;
  }
  // For loop to list each item ordered
  for (int i = 0; i < items.size(); i++) {
    cout << "Item " << i+1 << ": " << items[i] << endl;
  }
  // Printing all money values + farewell message
  cout << "Subtotal = $" << stotal << endl;
  cout << "Tax = $" << setprecision(2) << tax << endl;
  cout << "Total = $" << setprecision(4) << total << endl;
  cout << "Come again :)" << endl;
}
