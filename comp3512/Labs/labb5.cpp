#include <iostream>
#include <vector>
using namespace std;

int kth_selection(const vector<int>& v, size_t k);
vector<string> subsets(size_t n);
vector<string> add(vector<string> v);
void print_vi(const vector<int>& v);
void print_vs(const vector<string>& v);

int main(){
	//part 1
	vector<int> v = {8, 7, 4, 19, 27, 13, 7, 19, 8};
	for(size_t i = 1; i < v.size()+1; i++){
		cout << "kth selection " << kth_selection(v, i) << endl;
	}

	//part 2
	vector<string> v2 = subsets(4);
	print_vs(v2);
}

//precondition: v.size() > 0 && 1 <= k && k <= v.size()
int kth_selection(const vector<int>& v, size_t k){
	vector<int> left;	//ints less than v[0]
	vector<int> mid;	//int equal to v[0]
	vector<int> right;	//ints greater than v[0]

	size_t left_size;
	size_t mid_size;

	for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it){
		if(v[0] > *it){				//less than v[0]
			left.push_back(*it);	
		} else if(v[0] == *it){		//== to v[0]
			mid.push_back(*it);
		} else{						//greater than v[0]
			right.push_back(*it);
		}
	}

	left_size = left.size();
	mid_size = mid.size();

	if(k <= left.size()){				//v[0] is on the left
		return kth_selection(left, k);
	} else if(k > left_size + mid_size){	//v[0] is on the right
		return kth_selection(right, k - left_size - mid_size);
	} else {			
		return v[0];		//found it
	}
}

vector<string> subsets(size_t n){
	if(n == 0){		//base case 0, return an empty string vector
		return {""};
	}
	if(n == 1){		//base case 1, return 0 and 1
		return {"0", "1"};
	} 

	vector<string> prev_result = subsets(n-1);  //result from the previous call
	vector<string> result;						//result from current call

	//adds a "0" character in front of every element of the vector starting from head
	//then adds a "1" character in front of every element of the vector starting from the tail
	// n = 1	0 	 			1
	// n = 2	00 01 			11 10
	// n = 3	000 001 011 010	100 101 111 110
	// n = 4	...
	for(auto it = prev_result.begin(); it != prev_result.end(); ++it){
		result.push_back("0" + *it);
	}
	for(auto it = prev_result.rbegin(); it != prev_result.rend(); ++it){
		result.push_back("1" + *it);
	}
	return result;
}

//helper function to print out vectors int vectors
void print_vi(const vector<int>& v){
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << ' ';
	}
	cout << endl;
}

//helper function to print out string vectors
void print_vs(const vector<string>& v){
	for (auto it = v.begin(); it != v.end(); ++it)
    	cout << *it << ' ';
	cout << endl;
}