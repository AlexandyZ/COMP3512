#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "ColoredShape.h"
#include "ColoredShapeFactory.h"
#include "GC.h"
using namespace std;
using namespace std::placeholders;
int main(){
	vector<shared_ptr<ColoredShape>> v;
	ColoredShapeFactory              sf(cin);
	shared_ptr<ColoredShape>         p;
	GC                               gc(cout);
	
	while((p = sf.create()) != nullptr){
		v.push_back(p);
	}
	/*for(auto x: v)
		p-> draw(gc);*/
    
    // note: arguments to bind are passed by value
	for_each(v.begin(), v.end(), 
	         bind(mem_fn(&ColoredShap::draw), _1, ref(gc)));
}
