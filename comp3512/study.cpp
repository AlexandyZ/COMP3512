#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

struct Cmp{
	bool operator()(int i, int j){
	return i>j;
	}
}myObj;

struct Total{
	int count;
	int count2;
	Total(int sum = 0, int sum2 = 0):count(sum),count2(sum2){}

	void operator()(int a){
		if( a < 0){
			count++;
		}
		if( a >= 100){
			count2++;
		}
	}
}obj;



template<typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator cpy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate f);
bool is_even(int n){ return (n % 2 == 0);}

int main(){
	vector<int> v{3,2,7,6,8};
	vector<int> v2{300,-2,7,-6,800,100,40,-5};
	list<int> lst{10,11,12,13,14,15};
	vector<int> vv (5);
#if 0
	//--------------------a
	copy(v.begin()+3, v.end(), vv.begin());

	for(auto& it : vv){
		cout<<it <<' ';
	}cout<<endl;

	//--------------------b
	copy(lst.begin(),lst.end(),v.begin()+2);

	for(auto& it : v){
		cout<<it <<' ';
	}cout<<endl;

	//--------------------c
	copy(lst.begin(),lst.end(),inserter(v,v.begin()+3));

	for(auto& it : v){
		cout<<it <<' ';
	}cout<<endl;

	//--------------------d
	sort(v.begin(),v.end(),[](int a, int b){return a>b;});
	for(auto& it : v){
		cout<<it<<' ';
	}cout<<endl;

	//--------------------d - function object

	sort(v.begin(),v.end(),myObj);

	for(auto& it : v){
		cout<<it<<' ';
	}cout<<endl;

	//---------------------e
	
	transform(lst.begin(),lst.end(),v.insert(v.end(),lst.begin(),lst.end()),[](int i){return i*3;});
	for(auto& i : v){
		cout<<i<<' ';
	}

	//--------------------f
	v.erase(remove_if(v.begin(),v.end(),[](int i){return i < 5;}),v.end());

	for(auto& it:v){
		cout<<it<<' ';
	}
	//--------------------g
	Total t = for_each(v2.begin(),v2.end(),obj);
	cout<<t.count<<endl;
	cout<<t.count2<<endl;
#endif

	auto it = cpy_if(v.begin(),v.end(),lst.begin(),is_even);
	for(list<int>::iterator it = lst.begin();it!=lst.end();++it){
		cout << *it << ' ';
	}
}

template<typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator cpy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate f){
	for(auto it = first; it!= last; ++it){
		if(f(*it)){
			*result = *it;
			++result;
		}
	}
	return result;
}

