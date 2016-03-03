#include <iostream>
#include <bitset>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define NUM 10000000
using namespace std;

bool isPermutaion(const int& num1, const int& num2){
    string a = to_string(num1);
    string b = to_string(num2);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

string isMax(const map<string, set<int>>& m){
    string key;
    int max = 0;
    for(auto it = m.begin(); it != m.end(); ++it) {
        int tmp = it->second.size();
        if(tmp >= max) {
            max = tmp;
            key = it->first;
        }
    }
    return key;
}

int main() {
    bitset<NUM> ip;
    ip.set();
    vector<int> v;
    map<string, set<int>> m;
    
    for(size_t i = 2; i < sqrt(NUM); i++)
        if(ip[i]) {
            for(size_t j = i; j * i < NUM; j++)
                ip[j*i] = 0;
        }
    for(size_t i = 2; i < NUM; i++)
        if(ip[i] & (i > 1000000) & (i < 10000000))
            v.push_back(i);
    for(size_t i = 0; i < v.size(); i++) {
        for(size_t j = i; j < v.size(); i++){
            if(isPermutaion(v[i],v[j])) { 
                string key = to_string(v[i]);
                sort(key.begin(), key.end());
                m[key].insert(v[j]);
            }
        }
    }
    string k = isMax(m);
    cout << m.find(k)->second.size() << m.find(k)->second << endl;
    
    return 0;
}