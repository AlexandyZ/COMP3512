#include <iostream>
#include <vector>
#include "Student.h"
#include "OptionStudent.h"
using namespace std;

int main(){
    //vector<Student *> v;
    vector<OptionStudent *> v;
    //v.push_back(new Student);
    v.push_back(new OptionStudent);
    
    for(auto& e: v){
        e -> print(cout);
        e -> display(cout);
    }
}