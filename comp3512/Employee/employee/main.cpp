#include <iostream>
#include "FullTimeEmployee.h"

int main() {
  FullTimeEmployee  e("a12345678", Name("bart", "simpson"),
                      Date(2015, 11, 27), 10000);
  std::cout << e << std::endl;
/*
  FullTimeEmployee e;
  if (std::cin >> e)
    std::cout << e << std::endl;
*/
}
