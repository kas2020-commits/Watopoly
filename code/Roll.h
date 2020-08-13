#ifndef __ROLL_H__
#define __ROLL_H__

#include <string>

// a struct of 2 die rolls
extern class Roll {
  private:
    std::string message;
  public:
    int die1;
    int die2;
    int total;
    Roll();
    bool isDouble();
    std::string getMessage(moreInfo = false);
};