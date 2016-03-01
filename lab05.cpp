#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Grades{
	string id;
	map<string, int> scores;
};

//overload operator << 
ostream&
operator<<(ostream& os, const Grades& g){
	os << g.id << '\n' << g.scores.size() << '\n';
	for (auto& x : g.scores)
		os << x->first << '\n' << x.->second << endl;
	return os;
}

//overload operator >>
istream&
operator>>(istream& is, Grades& g){
	if (!(is >> g.id))
		return is;
	size_t n, score;
	string course;
	is >> n;
	for (auto i = 0; i < n; i++){
		is >> course >> score;
		g.scores[course] = score;
	}
	return is;
}

//define the Cmp function class
struct Cmp{
	string course;
	
	//initialize the constructor
	Cmp(const string& c) : course(c){}
	//overload constructor
	bool
	operator()(Grades& g1, Grades& g2) const {
		if(g1.scores.find(course) != g1.scores.end())
			return true;
		if(g2.scores.find(course) != g2.scores.end())
			return false;
		return g1.scores[course] < g2.scores[course];	
	}
};

//define the MaxFinder function class
struct MaxFinder{
	string course;
	int max = 0;
	vector<string> v;
	MaxFinder(const string& c):course(c) {}
	//overload constructor
	void
    operator()(const Grades& g){
		auto it = g.scores.find(course);
		if(it != g.scores.end()){
			if (max < it -> second) {
				max = it -> second;
				v.push_back(g.id);
			}
        }
	}
};

int main(){
	vector<Grades> v;
	Grades g;

	while (cin >> g)
		v.push_back(g);
	for(auto& x: v)
		cout << x << endl;
	
	sort(v.begin(), v.end(), Cmp("COMP3512"));
	for(auto& x: v)
		cout << x << endl;

	MaxFinder m = for_each(v.begin(), v.end(), MaxFinder("COMP3512"));
	cout << m.max << endl;
}