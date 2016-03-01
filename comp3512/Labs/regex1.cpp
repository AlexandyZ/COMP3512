#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
  regex   re(R"(\d+)");  // raw string
  string  s("abc123def45gh67");
  smatch  m;

  for (auto it = s.cbegin(), end = s.cend();
       regex_search(it, end, m, re); 
       it = m.suffix().first)
    cout << m.str() << endl;
}
