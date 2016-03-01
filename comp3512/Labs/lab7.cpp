#include <bitset>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
#define N 10000000

bitset<N> isprime;

int main(){
//for loop to find all primes
//sort and convert characters into a string
//put the key string in a map
	map<string,vector<unsigned long>> m;
	string s;
	unsigned long max = 0;
	string maxKey;

	isprime.set();
	for(size_t i = 2; i < N; i++){
		if(isprime[i]){
			for(size_t j = i; j*i < N; j++){
				isprime[j * i] = 0;
			}
		}
	}
	
	for(size_t i = 1000000; i < N; i++){
		if(isprime[i]){
			ostringstream oss;	
			oss << i;
			s = oss.str();

			sort(s.begin(), s.end());

			m[s].push_back(i);
		}
	}

	for(auto it = m.begin(); it != m.end(); ++ it){
		if(it->second.size() > max){
			max = it->second.size();
			maxKey = it->first;
		}
	}

	for(auto& i : m[maxKey]){
		cout << i << endl;
	}	cout << "size: " << max << endl;
}