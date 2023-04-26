#ifndef GROTTO_H
#define GROTTO_H

#include <iostream>

using namespace std;

// Declaring class
class Grotto {
  // Private variables to be used in Grotto methods
  private:
    int age, id; 
    string all, pref, aca;
  public:
    // Listing all methods in Grotto
    Grotto();
    void setAttributes();
    void listAttributes();
    bool login(int, bool);
    ~Grotto() { };
};

#endif
