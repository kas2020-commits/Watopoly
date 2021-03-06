#ifndef __AUCTION_H__
#define __AUCTION_H__

#include <map>
#include <string>

#include "LogicException.h"
#include "../data/Player.h"
#include "../tiles/Property.h"

//
class Auction : public LogicException {
  private:
    Property* property;
    std::map<std::string, Player*> bidders;
    Player * highestBidder;
    int highestBid;
    bool ended;
  public:
    Auction();
    Auction(Property* pr);
    void bid(std::string name, int amount);
    void addBidder(std::string name, Player* p);
    void end();
    virtual std::string getMessage() override;
};

#endif

