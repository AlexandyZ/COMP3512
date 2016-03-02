#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, string> Name;
typedef map<string, int>     Grades;


class Student{
public:
    //operations on Student objects
    void display(ostream& os) const;
    
private: 
    string id_;
    Name   name_;
    Grades grades_;
}

//overload operator << 
ostream&
operator<<(ostream& os, const Student& st){
	os << st.id_ << '\n' << st.name_.first << ' ' << st.name_.second << '\n' << st.grades_.size() << '\n';
	for (auto& x : st.grades_)
		os << x->first << '\n' << x->second << endl;
	return os;
}

//overload operator >>
istream&
operator>>(istream& is, Student& st){
	if (!(is >> st.id_))
		return is;
    is >> st.name_.first >> st.name_.second;
	int n, score;
	string course;
	is >> n;
	for (auto i = 0; i < n; i++){
		is >> course >> score;
		g.grades_[course] = score;
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
	operator()(Student& st1, Student& st2) const {
		if(st1.grades_.find(course) != st1.grades_.end())
			return true;
		if(st2.grades_.find(course) != st2.grades_.end())
			return false;
		return st1.grades_[course] < st2.grades_[course];	
	}
};

int main(){
	vector<Student> vst;
	Student st;

	while (cin >> st)
		v.push_back(st);
	for(auto& x: vst)
		cout << x << endl;
	
	sort(vst.begin(), vst.end(), Cmp("COMP3512"));
	for(auto& x: vst)
		cout << x << endl;
}