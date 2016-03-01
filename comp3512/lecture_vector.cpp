#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<int> v{3,2,7,6,8}; //only supported in c++11
	int a[5] = {6,5,5,3,6};
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout<<*it<< ' ';
	}
	cout<<endl;

	for(auto x:v){
		cout<<x<<' ';
	}
	cout<<endl;

	for(auto& x:v){
		x*=2;
		cout<<x<<' ';
	}
	cout<<endl;

	v.push_back(7); //add elements to end of vector
	v.push_back(-1);
	for(auto x:v){
		cout<<x<<' ';
	}
	cout << endl;

	v[0] = 10; //random access
	v.pop_back(); //removes last element
	v.back(); //find last element
	for(auto x:v){
		cout<<x<<' ';
	}
	cout<<endl;

	vector<int> v2(a, a+5); //2 iterators specify a range
	for(auto x:v2){
		cout<<x<<' ';
	}
	cout<<endl;

	auto i = v2.begin();
	++i;
	v2.insert(i,9);
	for(auto x:v2){
		cout<<x<<' ';
	}
	cout<<endl;
	
	i = v2.begin() + 2;
	v2.erase(i);
	for(auto x:v2){
		cout<<x<<' ';
	}
	cout<<endl;
}