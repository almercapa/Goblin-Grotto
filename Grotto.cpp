include "GetValid.h"
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

// Grotto constructor
Grotto::Grotto() {
  
}

// LOGIN METHOD
bool Grotto::login(int option, bool vip) {
  // If statement for if user chooses to login as VIP member
  // Skips if statement if user continues as guest
  if (option == 1) {
    // Login variables
    bool valid = false;
    string username, password;
    int retry, tries = 3;
    while (valid == false) {
      // Asks for login details
      cout << "Username: ";
      cin >> username;
      cout << "Password: ";
      cin >> password;
      // Returns true for vip variable if login details are correct
      if (username == "key" && password == "gotero") {
        cout << "Access confirmed. Please come in!" << endl;
        return true;
      } else if ((username != "key" || password != "gotero") && tries > 0) {
        // EXTRA: Asks if user would like to try to login again (4 total attempts)
        cout << "Username or password denied. " << tries << " attempt(s) remaining." << endl;
        cout << "1. Try again" << endl;
        cout << "2. Continue as guest" << endl;
        do {
          cout << "Please select an option: ";
        } while ((!(getValidInt(retry)) || (retry > 2) || (retry <= 0)));
        // Returns false if user does not want to try again
        if (retry == 2) {
          return false;
        }
        // Otherwise decrements number of attempts
        tries--;
        cout << "" << endl;
      } else if (tries <= 0) {
        // EXTRA: Returns false if user runs out of attempts
        cout << "Out of attempts. Continuing as guest." << endl;
        string dummy;
        getline(cin, dummy);
        return false;
      }
    }
  }
  return false;
}

// SETTING ATTRIBUTES
void Grotto::setAttributes() {
  // Flag for randomization
  srand((unsigned)time(0));
  // User input for attributes
  cout << "List any allergies: ";
  getline(cin, all);
  cout << "It doesn't matter, our menu is allergy free HAHAHAHAH" << endl;
  cout << "List any preferences: ";
  getline(cin, pref);
  cout << "List your academy: ";
  getline(cin, aca);
  do {
    cout << "Please list your age: ";
  } while ((!(getValidInt(age))));
  // Sets id as random number between 999 and 1
  id = (rand() % 999) + 1;
}

// PRINTING ATTRIBUTES
void Grotto::listAttributes() {
  // Prints all private variables
  cout << "Order #" << id << endl;
  cout << "Allergies: " << all << endl;
  cout << "Preferences: " << pref << endl;
  cout << "Academy: " << aca << endl;
  cout << "Age: " << age << endl;
}
