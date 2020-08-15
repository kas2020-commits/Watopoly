#include "Auction.h"
#include "GameException.h"

//
Auction::Auction(Property* pr) : property{pr},
  highestBidder{nullptr}, highestBid{0}, ended{false} {}

//
Auction::Auction() : property{nullptr},
  highestBidder{nullptr}, highestBid{0}, ended{true} {}

//
void Auction::bid(std::string name, int bid) {
    if (!bidders.count(name))
        throw GameException{"Player \"" + name + "\" does not exist.\n"};
    else if (bid <= highestBid)
        throw GameException{"Bid not high enough.\n"};
    // check if bidder can make payment
    bidders[name]->withdraw(bid); // will throw exception if lack of funds
    bidders[name]->deposit(bid);
    // player has funds, so set as highest bidder
    highestBidder = bidders[name];
    highestBid = bid;
}

//
void Auction::addBidder(std::string name, Player* p) {
    if (p) bidders[name] = p;
}

//
void Auction::end() {
    if (highestBidder) { // if no bids, we leave property unpurchased
        highestBidder->withdraw(highestBid);
        property->setOwner(highestBidder);
    }
    ended = true;
}

//
std::string Auction::getMessage() {/*
    if (!highestBid) return "Auction for \"" + property->getName() "\""
    return "Highest "*/
}

//
std::string Auction::getConclusion() {
    if (!ended) return "";
}