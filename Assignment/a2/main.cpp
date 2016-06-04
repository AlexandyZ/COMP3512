#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Shape.h"
#include "ShapeFactory.h"
#include "TranslationVisitor.h"
#include "XReflectionVisitor.h"
#include "YReflectionVisitor.h"
using namespace std;

int main(int argc, char * argv[]) {
    string line;
    vector <Shape *> v;
    Shape * sp;
    
    if(argc != 2)
        cerr << "cannot read file" << endl;

    ifstream ifs(argv[1]);
    //ifstream ifs;
    //ifs.open(argv[1], ifstream::in);
    if(ifs.good()){
        while(!ifs.eof()){
            ShapeFactory sf(ifs);
            if((sp = sf.create()) != 0)
                v.push_back(sp);
        }
        for(auto& x : v)
           x -> draw();
    }
    ifs.close();
    
    cerr << "> ";
    while(getline(cin, line)){
        string op;
        istringstream iss(line);
        if(iss >> op) {
           // try{
                if(op == "c"){
                    try{
                        ShapeFactory sf(iss);
                        if((sp = sf.create()) != 0){
                            v.push_back(sp);
                            for(auto& x : v)
                            x -> draw();
                        }
                    }
                    catch(...){
                        continue;
                    }   
                } else if(op == "d"){
                    for(auto& x : v)
                    x -> draw();
                } else if(op == "t"){
                    Point p;
                    if(iss >> p){
                        TranslationVisitor tv(p);
                        for(auto& x : v){
                            x -> accept(tv);
                            x -> draw();
                        }   
                    }
                } else if(op == "x"){
                    XReflectionVisitor xrv;
                    for(auto& x : v){
                        x -> accept(xrv);
                        x -> draw();
                    }           
                } else if(op == "y"){
                    YReflectionVisitor yrv;
                    for(auto& x : v){
                        x -> accept(yrv);
                        x -> draw();
                    }  
                }
            /*}
            catch(exception& e){
                continue;
            }*/
            cerr << "> ";
        }
    }
    
    ofstream ofs(argv[1]);   
    for (auto& x : v)
       x -> save(ofs);
    ofs.close();
    
    return 0;
}