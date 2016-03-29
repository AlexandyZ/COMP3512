#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#define BUFSIZE 1024

using namespace std;
typedef pair<string, string> Name; // first name, last name
typedef map<string, int> Grades; // map courses to scores
class Student {
public:
	void display(ostream& os) const;
	void displayId(ostream& os) const;
	// friend declarations & additional function declarations if necessary
	void insert(string id,Name name,Grades grades) {
		grades_.clear();
		id_ = id;
		name_ = name;
		grades_ = grades;
	}
	string getId() const {
		return id_;
	}
	Name getName() const {
		return name_;
	}

	Grades getGrades() const {
		return grades_;
	}
private:
	string id_; // e.g. "a22222222"
	Name name_; // e.g. {"ned", "flanders"}
	Grades grades_; // e.g. {{"comp1510", 90}, {"comp2510", 85}}
};


void Student::displayId(ostream& os) const {
	os << id_ << endl;
}

void Student::display(ostream& os) const {
	os << id_ << endl;
	os << name_.first << " " << name_.second << endl;
	for (auto& x:grades_) {
		os << x.first << " " << x.second << endl;
	}
	
}

istream& operator>>(istream& is, Student& s) {
	Grades grade;
	size_t size;
	Name name;
	string id;
	string course;
	int score;
	
	if (!(is >> id)) {
		return is;
	}
	is >> name.first;
	is >> name.second;
	is >> size;
	grade.clear();
	for (size_t i = 0; i < size;i++) {
		is >> course;
		is >> score;
		grade.insert(make_pair(course,score));
	}
	s.insert(id,name,grade);

	return is;

}

struct IdFinder{
	IdFinder(const string& s) {
		id = s;
	}
	void operator()(const Student& std) {
		string i = std.getId();
		if (id == i) {
			v.push_back(std);
		}
	}
	vector<Student> v;
	string id;

};

struct NameFinder {
	NameFinder(const string& first, const string& second) {
		coursef = first;
		courses = second;
	}
	void operator()(const Student& s) {
		name = s.getName();
		if (coursef == "*") {
			if ((courses == "*")||(courses != "*" && courses == name.second )) {
				v.push_back(s);
			}
		}
		else {
			if (courses != "*" && courses == name.second && coursef == name.first) {
				v.push_back(s);
			}
			else if (courses == "*" && coursef == name.first) {
				v.push_back(s);
			}
		}
		
	}
	Name name;
	vector<Student> v;
	string coursef,courses;
};

struct gradeFinder{
	gradeFinder(const string& s, const int& i) {
		score = i;
		course = s;
	}

	gradeFinder(const string& s, const int& i,const int& i2) {
		score = i;
		course = s;
		score2 = i2;
	}

	void operator()(const Student& std) {
		grades = std.getGrades();
		auto it = grades.find(course);
		
		if (it != grades.end()) {
			if (score2 <= score) {
				if (it->second == score) {
					v.push_back(std);
				}
			}
			else {
				if (it->second <= score2 && it->second >= score) {
					v.push_back(std);
				}
			
			}
		}
	}
	Grades grades;
	string course;
	vector<Student> v;
	int score = -1;
	int score2 = -1;
};

struct Cmp {
	Cmp(const string s) {
		type = s;
	}
	bool operator()(const Student& lhs, const Student& rhs) const {
		string first = lhs.getId();
		string second = rhs.getId();
		if (type == "+") {
			return second > first;
		}
		else {
			return first > second;
			
		}
		
	}
	string type;
};

int main(int argc, char* argv[])
{
	string c;
	string order[4];
	Student s;
	vector<Student> v;
	int score1,score2;
	if (argc == 2) {
		ifstream in(argv[1]);
		if (!in.is_open())
		{
			cout << "Error opening file"; exit(1);
		}
		else {
			while (in >> s) {
				v.push_back(s);
			}
		}
	}
	else {
		cout << "Wrong input"; exit(1);
	}
	
	while (getline(cin,c)) {
		istringstream iss1(c);
		if (!(iss1 >> order[0])) {
			cout << endl;
			continue;
		}
		if (order[0]=="show") {
			sort(v.begin(), v.end(), Cmp("+"));
			if (!(iss1 >> order[1] >> order[2])) {
				for (auto& x:v) {
					x.display(cout);
				}
			}
			else {
				if (order[1] == "grade") {
					iss1 >> score1;
					if (iss1 >> score2) {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1, score2));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->display(cout);
						}
					}
					else {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->display(cout);
						}
					}
				}
				else if (order[1] == "id") {
					IdFinder m = for_each(v.begin(), v.end(), IdFinder(order[2]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						it->display(cout);
					}
				}
				else if (order[1] == "name") {
					iss1 >> order[3];
					NameFinder m = for_each(v.begin(), v.end(), NameFinder(order[2], order[3]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						(*it).display(cout);
					}
				}	
			}
		}
		else if (order[0] == "-show") {
			sort(v.begin(), v.end(), Cmp("-"));
			if (!(iss1 >> order[1] >> order[2])) {
				for (auto& x : v) {
					x.display(cout);
				}
			}
			else {
				if (order[1] == "grade") {
					iss1 >> score1;
					if (iss1 >> score2) {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1, score2));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->display(cout);
						}
					}
					else {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->display(cout);
						}
					}
				}
				else if (order[1] == "id") {
					IdFinder m = for_each(v.begin(), v.end(), IdFinder(order[2]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						it->display(cout);
					}
				}
				else if (order[1] == "name") {
					iss1 >> order[3];
					NameFinder m = for_each(v.begin(), v.end(), NameFinder(order[2], order[3]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						(*it).display(cout);
					}
				}
			}
		}
		else if (order[0] == "-showid") {
			sort(v.begin(), v.end(), Cmp("-"));
			if (!(iss1 >> order[1] >> order[2])) {
				for (auto& x : v) {
					x.displayId(cout);
				}
			}
			else {
				if (order[1] == "grade") {
					iss1 >> score1;
					if (iss1 >> score2) {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1, score2));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->displayId(cout);
						}
					}
					else {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->displayId(cout);
						}
					}
				}
				else if (order[1] == "id") {
					IdFinder m = for_each(v.begin(), v.end(), IdFinder(order[2]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						it->displayId(cout);
					}
				}
				else if (order[1] == "name") {
					iss1 >> order[3];
					NameFinder m = for_each(v.begin(), v.end(), NameFinder(order[2], order[3]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						(*it).displayId(cout);
					}
				}
			}
		}
		else if (order[0] == "showid") {
			sort(v.begin(), v.end(), Cmp("+"));
			if (!(iss1 >> order[1] >> order[2])) {
				for (auto& x : v) {
					x.displayId(cout);
				}
			}
			else {
				if (order[1] == "grade") {
					iss1 >> score1;
					if (iss1 >> score2) {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1, score2));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->displayId(cout);
						}
					}
					else {
						gradeFinder m = for_each(v.begin(), v.end(), gradeFinder(order[2], score1));
						for (auto it = m.v.begin(); it != m.v.end(); ++it) {
							it->displayId(cout);
						}
					}
				}
				else if (order[1] == "id") {
					IdFinder m = for_each(v.begin(), v.end(), IdFinder(order[2]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						it->displayId(cout);
					}
				}
				else if (order[1] == "name") {
					iss1 >> order[3];
					NameFinder m = for_each(v.begin(), v.end(), NameFinder(order[2], order[3]));
					for (auto it = m.v.begin(); it != m.v.end(); ++it) {
						(*it).displayId(cout);
					}
				}
				
			}
		}
		
		cout << endl;
	}
	/*
	for (const auto& x : v) {
		x.display(cout);

		cout << endl;
	}
	*/
}

