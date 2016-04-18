#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholder;

int f(int a, int b){
    return a / b;
}

int main(){
    f(1, 2);
    auto g = bind(f, _1, 4);  //_1 means the first argument of bind function.
    auto h = bind(f, 4, _1);
    cout << g(12) << endl;
    cout << h(2) << endl;
}