#ifndef GC_H
#define GC_H
// graphics context
#include <iostream>
#include <string>
#include <map>

class GC {
public:
  // C++11 scoped enumerators
  enum class Colour { Default, Red, Blue, Green }; 

  explicit GC(std::ostream& os): osp_(&os) {}

  ~GC() { *osp_ << defaultColour_; }

  void setColour(const Colour& colour) {
    *osp_ << colourMap_[colour];
  }

  void draw(const std::string& shape) {
    *osp_ << shape;
  }

  GC(const GC&) = delete;
private:
  std::ostream *osp_;
  static std::map<Colour,std::string>  colourMap_;
  static constexpr const char *defaultColour_ = "\x1b[39;49m";  // c++11
};

inline std::ostream&
operator<<(std::ostream& os, const GC::Colour& colour) {
  return os << static_cast<int>(colour);
}

inline std::istream&
operator>>(std::istream& is, GC::Colour& colour) {
  int  c;
  is >> c;
  colour = static_cast<GC::Colour>(c);
  return is;
}
#endif
