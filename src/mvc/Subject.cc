#include <algorithm>
#include "Subject.h"

Subject::~Subject() {}

// lets observer know the subject's stat has changed
void Subject::updateObservers() {
    for (auto it = observers.begin(); it != observers.end(); it++) {
        (*it)->update(this);
    }
}

// sends a message to display in observer
void Subject::updateObservers(std::string message) {
    for (auto it = observers.begin(); it != observers.end(); it++) {
        (*it)->update(message);
    }
}

// attaches observer to self
void Subject::attachSelf(Observer* ob) {
    observers.emplace_back(ob);
    updateObservers();
}

//
void Subject::attachObservers(Subject* s) {
    for (auto it = observers.begin(); it != observers.end(); it++) {
        s->attach(*it);
    }
}

// virtual method for attaching observer to subject's members
void Subject::attachMembers(Observer* ob) {}

// template pattern for attach, purpose is to let a subject attach some of its
//  members if wants to. This will be useful for the Game class implentation,
//  so it can attach the observer to the playrs and tiles
void Subject::attach(Observer* ob) {
    attachSelf(ob);
    attachMembers(ob);
}

