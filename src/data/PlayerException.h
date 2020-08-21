#ifndef __PLAYER_EXCEPTION_H__
#define __PLAYER_EXCEPTION_H__
#include "../logic/GameException.h"

struct PlayerException : public GameException {
	PlayerException(std::string message) : GameException{message} {}
};

#endif

