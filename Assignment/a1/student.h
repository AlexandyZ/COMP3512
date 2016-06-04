#include<iostream>
#include<map>
#include<string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

typedef pair<string, string> Name; // first name, last name
typedef map<string, int> Grades; // map courses to scores

//class of Student object, define a Student struct
class Student {
public:
	void display(ostream& os) const;
	void displayId(ostream& os) const;
	// friend declarations & additional function declarations if necessary
	void insert(string id, Name name, Grades grades) {
		id_ = id;
		name_ = name;
        grades_.clear();
		grades_ = grades;
	}
	string getId() const { return id_; }
	Name getName() const { return name_; }
	Grades getGrades() const { return grades_; }
private:
	string id_; // e.g. "a22222222"
	Name name_; // e.g. {"ned", "flanders"}
	Grades grades_; // e.g. {{"comp1510", 90}, {"comp2510", 85}}
};

//overload input stream operator
istream&
operator>>(istream& is, Student& s) {
	string id;
	Name n;
    Grades g;
	string cs;
	int sc;
    size_t n;
	
	if (!(is >> id)){
		return is;
    }
	is >> n.first >> n.second;
    is >> n;
	g.clear();
	for (size_t i = 0; i < n; i++) {
		is >> cs;
        is >> sc;
		g.insert(make_pair(cs,sc));
	}
	s.insert(id, n, g);

	return is;
}

//implement output functions
void Student::display(ostream& os) const {
	os << id_ << endl;
    os << name_.first << " " << name_.second << endl;
	for (auto& x: grades_){
		os << x.first << " " << x.second << endl;	
    }
}

void Student::displayId(ostream& os) const {
	os << id_ << endl;
}

//class of Cmp object is used to compare 2 ids
struct Cmp {
    string mode;
    //initialize operator
	Cmp(const string m): mode(m) {}
    //overload operator
	bool
    operator()(const Student& s1, const Student& s2) const {
		if(mode == "as")
			return s1.getId() > s2.getId();
		if(mode == "ds")
			return s1.getId() < s2.getId();
	}
};

//Finders are used to find specific records
struct IdFinder{
    vector<Student> v;
	string id;
    //Initialize operator
	IdFinder(const string& st) {
        id = st; 
    }
    //overload operator
	void operator()(const Student& s) {
		if (id == s.getId())
			v.push_back(s);
	}
};

struct NameFinder {
    vector<Student> v;
    Name name;
	string fname, lname;
    //Initialize operator
	NameFinder(const string& fn, const string& ln) {
        fname = fn;
        lname = ln; 
    }
	//overload operator
    void operator()(const Student& s) {
		name = s.getName();
		if(fname == name.first) {
            if(lname == name.second)
                v.push_back(s);
            else if(lname == "*")
                v.push_back(s);
		}
		else if(fname == "*") {
			if(lname == name.second)
                v.push_back(s);
            else if(lname == "*")
                v.push_back(s);
		}
	}
};

struct GradeFinder{
    vector<Student> v;
    Grades grades;
    string course;
	int sc, lsc, hsc;
    //initialize operators
    GradeFinder(const string& c, const int& cs) {
        course = c;
        sc = cs;
    }
    GradeFinder(const string& c, const int& ls, const int& hs) {
        course = c;
        lsc = ls;
        hsc = hs;
    }
    //overload operators
	void operator()(const Student& s) {
		grades = s.getGrades();
		auto it = grades.find(course);
		while (it != grades.end()) {
            int score = it->second;
			if (score == sc) 
				v.push_back(s);
			else if (score >= lsc && score <= hsc)
				v.push_back(s);			
		}
	}
};
