#ifndef GC_H
#define GC_H
#include <string>
#include <iostream>
#include <map>

class GC { //used by the base and child classes
  public:
    enum class Colour { 
      Default, Black, Red, Text, Green, Brown, Blue, Purple, Cyan, Grey     };

    explicit GC(std::ostream& os): out_(&os) {}
    ~GC() { *out_ << defColour; }

    void setColour(Colour colour) {
      auto it = colours_.find(colour);
      *out_ << (it != colours_.end() ? it->second : defColour);
    }

    std::ostream& getCanvas() { return *out_; }
    GC(const GC&) = delete;  // disallow copy ctor
  private:
    std::ostream  *out_;
    static constexpr const char *defColour = "\033[39;49m";
    static std::map<Colour, std::string> colours_;  // declaration only
};
#endif
