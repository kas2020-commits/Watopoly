#ifndef __LOGIC_EXCEPTION_H__
#define __LOGIC_EXCEPTION_H__
#include <string>

//
class LogicException {
  public:
    virtual std::string getMessage() { return ""; }
};

#endif

