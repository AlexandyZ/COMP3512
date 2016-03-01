#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	map<string, size_t> freq;
	string word;

	while(cin>>word){
		freq[word]++;
	}
	for(auto& p:freq)
	{	
		cout << p.first<< ":"<<p.second<<endl;		
	}
}