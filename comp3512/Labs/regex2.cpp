#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
  string  s("ABCdef123xyZUVW");
  regex   re(R"(([a-z]+)(\d+)([a-z]+))");  // 3 capturing groups
  smatch  m;

  if (regex_search(s, m, re)) {
    for (auto i = 0; i < m.size(); i++)
      cout << m.str(i) << endl;
    // can also print the submatches using:
    // for (const auto& c: m)
    //   cout << c << endl;
  }

}

