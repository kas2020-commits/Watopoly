#include "Game.h"

std::shared_ptr<Board> board;
std::map<std::string, std::shared_ptr<Player>> players;
std::map<std::string, std::shared_ptr<Player>>::iterator curPlayer;
bool started;

// Constructor
Game::Game() board{std::make_unique<Board>{}} {}

Game::~Game();
Game::attachToMembers(Observer* ob) override;
void Game::addPlayer();
void Game::bankruptPlayer();
std::shared_ptr<Player> Game::start(); // all players must be added before game started
std::shared_ptr<Player> Game::nextTurn();


#endif