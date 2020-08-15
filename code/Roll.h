#ifndef __ROLL_H__
#define __ROLL_H__

#include <string>

// a struct of 2 die rolls
extern class Roll {
  private:
    static Roll nextRoll;
    static bool nextRollLoaded;
    Roll(int die1, int die2);
  public:
    static void loadNextRoll();
    static void discardNextRoll();
    int die1;
    int die2;
    int total;
    Roll();
    bool isDouble();
    std::string getMessage(moreInfo = false);
};