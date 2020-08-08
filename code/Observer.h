#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <string>

class Subject; // forward declaration

//
class Observer {
  public:
    virtual ~Observer() {};
    virtual void update(Subject* whoNotified) = 0;
    virtual void update(std::string message) = 0;
};

#endif