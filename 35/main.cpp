#include <iostream>
#include <vector>
#include "Name.h"
#include "Employee.h"
#include "FullTimeEmployee.h"
using namespace std;

/*
int main(){
    //===
    try{
        Name n1("", ""), n2("", "");
    } catch (const char *s){
        cerr << s << endl;
    }
    
    //===
    Name n;
    vector<Name> v;
    while(cin >> n)
        v.push_back(n);
    
    for(auto& n: v)
        cout << n << endl;
}
*/

int main(){
    vector<Employee *> v;
    v.push_back(new Employee);
    v.push_back(new FullTimeEmployee);
    
    for(auto& e: v){
        e -> print(cout);
    }
    return 0;
}