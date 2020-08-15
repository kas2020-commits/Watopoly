#ifndef __LOGIC_EXCEPTION_H__
#define __LOGIC_EXCEPTION_H__
#include <string>

//
class LogicException {
  private:
    std::string message;
  public:
    LogicException() : message{""} {}
    void setMessage(std::string m) { message = m; }
    std::string getMessage() { return message; }
};

#endif
