#ifndef _SUBJECT_
#define _SUBJECT_

#include <string>
#include <vector>
#include "Observer.h"

class Subject {
  private:
    std::vector<Observer*> observers;
    void attachToSelf(Observer* ob);
  protected:
    virtual void attachToMembers(Observer* ob);
    void updateObservers();
    void updateObservers(std::string message);
  public:
    virtual ~Subject();
    void attach(Observer* ob); // template pattern function
};

#endif