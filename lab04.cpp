#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> interleave(int x, const vector<int>& v){
	vector<int> tmp = v;
	vector<vector<int>> vec;

	for (vector<int>::size_type i = 0; i < tmp.size(); i++){
		tmp.insert(tmp.begin() + i, x);
		vec.push_back(tmp);
	}

	return vec;
}

vector<vector<int>> permute(size_t n){
	vector<vector<int>> start = permute(n - 1);
	vector<vector<int>> res;
	vector<vector<int>> intl;
	for (size_t i = 0; i < n; i++){
		intl = interleave(i + 1, start);
		for (size_t j = 0; j < n; j++)
			res.push_back(intl);
	}
	return res;
}

void print(const vector<vector<int>>& v){
	for (vector<int>& x : v){
		for (auto& y : x)
			cout << y << ' ';
		cout << endl;
	}
    cout << endl;		
}

int main(){
	print(permute(4));
	return 0;
}