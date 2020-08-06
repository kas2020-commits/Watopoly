#include "Observer.h"
#include "Subject.h"

// destructor
Observer::~Observer() {}

//
void Observer::attachTo(Subject* s) {
    s->attach(this);
}