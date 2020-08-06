#ifndef _OBSERVER_
#define _OBSERVER_

#include <string>

class Subject; // forward declaration

class Observer {
  public:
    virtual ~Observer() {}
    virtual void update(Subject* whoNotified) = 0;
    virtual void update(std::string message) = 0;
};

#endif