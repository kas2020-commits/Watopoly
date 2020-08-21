#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <string>
#include <vector>
#include "Observer.h"

class Subject {
  private:
    std::vector<Observer*> observers;
  protected:
    void attachSelf(Observer* ob); // attaches observer to current subject
    virtual void attachMembers(Observer* ob); // attaches observer to subject's subject members
    void attachObservers(Subject* s); // attaches observers of current subject to another subject
    void updateObservers();
    void updateObservers(std::string message);
  public:
    virtual ~Subject();
    void attach(Observer* ob); // template pattern function
};

#endif

