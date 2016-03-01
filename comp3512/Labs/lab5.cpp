#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Grades{
	string id;
	map<string,int> scores;
};

//overload output operator
ostream& operator<<(ostream& os, const Grades& gr){
	os<<gr.id;

	for(map<string,int>::const_iterator it = gr.scores.begin(); it != gr.scores.end(); ++it)
	{	
		os << it->first<< ":"<< it->second << endl;		
	}
	return os;
}
//overload input operator
istream& operator>>(istream& is, Grades& gr){
	int n;
	string key;
	int value;

	is >> gr.id;
	is>>n;

	for(int i = 0; i < n; i++){
		is >> key >> value;
		gr.scores.insert(make_pair(key,value));
	}
	return is;
}

//for using multimap; function class
struct Cmp{		
	string course;
	Cmp(const string& c = "default" ): course(c){}

	bool operator()(const Grades& lhs, const Grades& rhs)const{
		auto it1 = lhs.scores.find(course);
		auto it2 = rhs.scores.find(course);

		int score1 = (it1 != lhs.scores.end()) ? it1->second : -1;
		int score2 = (it2 != rhs.scores.end()) ? it2->second : -1;

		return score1 > score2;
	}
};
struct MaxFinder{		
	string course;
	int max;
	vector<string> vec;
	MaxFinder(const string& c = "default", int m = 0, 
		vector<string> v = {} ): course(c), max(m), vec(v){}
	
	void operator()(Grades& gr){
		auto it = gr.scores.find(course);

		if(it != gr.scores.end()){

			if(max < it->second){
				max = it->second;
				vec.clear();
				vec.push_back(gr.id);
			}
			else if (max == it->second){
				vec.push_back(gr.id);
			}
		}
	}
};

int main(){

	vector<Grades> v;

	sort(v.begin(), v.end(), Cmp("COMP3512"));
	for(auto& it : v){
		cout << it << endl;
	}

	cout << "Enter ID: " << endl;
	cout << "Enter the number of courses: ";
	MaxFinder m = for_each(v.begin(), v.end(), MaxFinder("COMP3512"));
	for(auto& it : m.vec){
		cout << it << endl;
	}

return 0;
}