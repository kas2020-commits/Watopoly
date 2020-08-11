#ifndef __TRAPPED_H__
#define __TRAPPED_H__

#include <string>
#include "Player.h"

//
class Trapped {
  protected:
    Player* player;
    std::string message;
  public:
    Trapped() : player{nullptr}, message{""} {}
    Trapped(Player* p, std::string message) :
      player{p}, message{message} {}
    virtual std::string getMessage() { return message; }
};

#endif