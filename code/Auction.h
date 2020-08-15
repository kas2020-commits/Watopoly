#ifndef __AUCTION_H__
#define __AUCTION_H__

#include <map>
#include <string>

#include "Player.h"
#include "Property.h"

//
class Auction {
  private:
    Property* property;
    std::map<std::string, Player*> bidders;
  public:
    Auction(Property* pr);
    bid(std::string name, int amount);
    addBidder(std::string name, Player* p)
};

#endif