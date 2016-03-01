// Review 1, question 1(g)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct counter {
  size_t n0 = 0, n100 = 0;
  void operator()(int n) {
    if (n < 0)
      n0++;
    else if (n > 100)
      n100++;
  }
};

int main() {
  vector<int>  v;
  int          n;

  while (cin >> n)
    v.push_back(n);

  counter c = for_each(v.begin(), v.end(), counter());
  cout << "count of integers less than 0: " << c.n0 << endl;
  cout << "count of integers greater than 100: " << c.n100 << endl;
}
