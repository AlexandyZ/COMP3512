#include <map>
#include <string>
#include "GC.h"

std::map<GC::Colour, std::string>  // need GC:: 
GC::colours_ {  // definition (static not repeated)
  {Colour::Default, "\033[39;49m"},
    {Colour::Black, "\033[0;30m"},
    {Colour::Red, "\033[0;31m"},
    {Colour::Green, "\033[0;32m"},
    {Colour::Brown, "\033[0;33m"},
    {Colour::Blue, "\033[0;34m"},
    {Colour::Purple, "\033[0;35m"},
    {Colour::Cyan, "\033[0;36m"},
    {Colour::Grey, "\033[0;37m"}
};

