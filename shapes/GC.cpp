#include <string>
#include <map>
#include "GC.h"
using namespace std;

// generally, static members need to be initialized in .cpp file
// type  class::name
map<GC::Colour, string>  GC::colourMap_ = {
  { Colour::Default, "\x1b[39;49m" },
  { Colour::Red, "\x1b[31m" },
  { Colour::Blue, "\x1b[34m" },
  { Colour::Green, "\x1b[32m" }
};
