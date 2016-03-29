#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> subsets(size_t n){
    vector<string> v;
    vector<string> v2;
    for(size_t i = 0; i < n; i++)
        v.push_back("0");
    for(auto x:v)
        v.push_back("1");      
}
int main(){
    cout << subsets(4) << endl;
}