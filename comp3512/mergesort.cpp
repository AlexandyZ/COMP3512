#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> merge(const vector<int>& v1, const vector<int>& v2){
	vector<int> result;
	vector<int>::size_type i1 = 0, i2 = 0, n1 = v1.size(), n2 = v2.size();
	result.reserve(n1 + n2);
	while(i1 < n1 && i2 < n2){
		result.push_back(v1[i1] < v2[i2]? v1[i1++]:v2[i2++]);
	}
	result.insert(result.end(),v1.begin() + i1,v1.end());
	result.insert(result.end(),v2.begin() + i2, v2.end());
	return result;
}
vector<int> mergesort(const vector<int>& v){
	auto sz = v.size();
	if (sz == 1){
		return v;
	}
	return merge(mergesort(vector<int>(v.begin(),v.begin()+sz/2)),
				mergesort(vector<int>(v.begin()+sz/2,v.end())));
}
vector<int> mergesort_nonrecursive(const vector<int>& v){
	deque<vector<int>> d;
	for(auto& c:v){
		d.push_back(vector<int> (1,c));
	}
	while(d.size() > 1){
		d.push_back(merge(d[0],d[1]));
		d.pop_front();d.pop_front();
	}
	return d[0];
}

int main(){
	vector<int> a{8,3,6,2,7,5,1,0,4};
	
	//mergesort(a);
	for(auto& x : a){
		cout<<x<<' ';
	}cout << endl;
	mergesort_nonrecursive(a);
	for(auto& x : a){
		cout<<x<<' ';
	}
}