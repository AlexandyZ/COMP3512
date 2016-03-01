// Incomplete!
#ifndef DATE_H
#define DATE_H

struct Date {
  int  year, month, day;
  Date(int y = 2000, int m = 1, int d = 1): year(y), month(m), day(d) {}
};

inline std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << d.year << '/' << d.month << '/' << d.day;
}

inline std::istream& operator>>(std::istream& is, Date& d) {
  char  c1, c2;
  return is >> d.year >> c1 >> d.month >> c2 >> d.day;
}
#endif
