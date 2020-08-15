#ifndef __GAME_EXCEPTION_H__
#define __GAME_EXCEPTION_H__

#include <string>

class GameException {
  private:
    std::string message;
  public:
    GameException(std::string message) : message{message} {}
    std::string getMessage() { return message; }
};

#endif

