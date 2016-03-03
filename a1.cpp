#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, string> Name;
typedef map<string, int>     Grades;

class Student {
public:
    //operations on Student objects
    void display(ostream& os) const;
    void displayId(ostream& os) const;
    //get values from private members
    string getID() const { return id_; }
    Name getName() const { return name_; }
    Grades getGrades() const { return grades_; }
    
private: 
    string id_;
    Name   name_;
    Grades grades_;
};

//overload operator >>
istream&
operator>>(istream& is, Student& st) {
	if (!(is >> st.getID()))
		return is;
    is >> st.getName().first >> st.getName().second;
	
    size_t n;
    int score;
	string course;
	is >> n;
	for (auto i = 0; i < n; i++) {
		is >> course >> score;
		st.getGrades()[course] = score;
	}
	return is;
}

//display functions to display Student records formattedly
void Student::display(ostream& os) const {
    os << id_ << '\n' << name_.first << ' ' << name_.second << '\n';
    for(auto& x : grades_)
        os << x.first << ' ' << x.second << endl;
}

void Student::displayId(ostream& os) const {
    os << id_ << endl;
}

//define the Cmp function class
struct Cmp {
	string mode;
	
	//initialize the constructor
	Cmp(const string& m) : mode(m) {}
	//overload constructor
	bool
	operator()(Student& st1, Student& st2) const {
		if(mode == "as")
			return st1.getID() > st2.getID();
		if(mode == "ds")
			return st1.getID() < st2.getID();	
	}
};

//Finders are used to find specific records
struct IDFinder{
    vector<Student> v;
    string id;
	IDFinder(const string& str): id(str) {}
    //overload the operator
	void operator()(const Student& s) {
		if (id == s.getID())
			v.push_back(s);
	}
};

struct NameFinder {
    vector<Student> v;
    Name name;
	string first, last;
	NameFinder(const string& fn, const string& ln): first(fn), last(ln) {}
	//overload the operator
    void operator()(const Student& s) {
		name = s.getName();
		if(first == name.first) {
            if(last == name.second)
                ;
            else if(last == "*")
                ;
		}
		else if(first == "*") {
			if(last == name.second)
                ;
            else if(last == "*")
                v.push_back(s);
		}		
	}
};

struct GradeFinder1{
    Grades grades;
	string course;
	vector<Student> v;
    int score;
	GradeFinder1(const string& c, const int& sc): course(c),score(sc) {}

	void operator() (const Student& s) {
		grades = s.getGrades();
		auto it = grades.find(course);
		while(it != grades.end())
            if(it->second == score)
                v.push_back(s);
	}
};

struct GradeFinder2{
    Grades grades;
	string course;
	vector<Student> v;
	int lowerScore;
	int higherScore;
	GradeFinder2(const string& c, const int& ls, const int& hs):
                 course(c), lowerScore(ls), higherScore(hs) {}

	void operator() (const Student& s) {
		grades = s.getGrades();
		auto it = grades.find(course);
		while(it != grades.end())
            int sc = it->second;
            if(sc >= lowerScore && sc <= higherScore)
                v.push_back(s);
	}
};

int main(int argc, char* argv[]) {
	vector<Student> vst;
	Student st;
    string str;
    string cmd[5];    
    
    if(argc != 2) {
        cerr << "usage: " << argv[0] << "record" << endl;
        exit(1);
    }
    else{
        ifstream fs(argv[1]);
        if(!fs) {
            cerr << "unable to open the file";
            exit(1);
        } else {
            while( fs >> st)
                vst.push_back(st);
        }
    }

    while(getline(cin, str)) {
        istringstream iss(str);
        if(!(iss >> cmd[0]))
            cout << endl;
        switch(cmd[0]) {
            case "show": {
                sort(vst.begin(), vst.end(), Cmp("as"));
                if(!(iss >> cmd[1] >> cmd[2])) {
                    for (auto& x: vst)
                        x.display(cout);
                }                   
                switch(cmd[1]) {
                    case "id": {
                        NameFinder nf = for_each(vst.begin(), vst.end(), IDFinder(cmd[2]));
                        for(auto x: nf.vst)
                            x.display(cout);
                        break;
                    }
                    case "name": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        auto it = for_each(vst.begin(), vst.end(), NameFinder(cmd[2], cmd[3]));
                        for(auto x: it)
                            x.display(cout);
                        break;
                    }
                    case "grade": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        else if(!(iss>>cmd[4])){
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder1(cmd[2], cmd[3]));
                            for(auto x: it)
                                x.display(cout);
                        }
                        else {
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder2(cmd[2], cmd[3], cmd[4]));
                            for(auto x: it)
                                x.display(cout);
                        }
                        break;
                    }
                }
                break;
            }
            case "-show": {
                sort(vst.begin(), vst.end(), Cmp("ds"));
                if(!(iss >> cmd[1] >> cmd[2])) {
                    for (auto& x: vst)
                        x.display(cout);
                }                   
                switch(cmd[1]) {
                    case "id": {
                        auto it = for_each(vst.begin(), vst.end(), IDFinder(cmd[2]));
                        for(auto x: it)
                            x.display(cout);
                        break;
                    }
                    case "name": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        auto it = for_each(vst.begin(), vst.end(), NameFinder(cmd[2], cmd[3]));
                        for(auto x: it)
                            x.display(cout);
                        break;
                    }
                    case "grade": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        else if(!(iss>>cmd[4])){
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder1(cmd[2], cmd[3]));
                            for(auto x: it)
                                x.display(cout);
                        }
                        else {
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder2(cmd[2], cmd[3], cmd[4]));
                            for(auto x: it)
                                x.display(cout);
                        }
                        break;
                    }
                }
                break;
            }
            case "showid": {    
                sort(vst.begin(), vst.end(), Cmp("as"));
                if(!(iss >> cmd[1] >> cmd[2])) {
                    for (auto& x: vst)
                        x.displayId(cout);
                }                   
                switch(cmd[1]) {
                    case "id": {
                        auto it = for_each(vst.begin(), vst.end(), IDFinder(cmd[2]));
                        for(auto x: it)
                            x.displayId(cout);
                        break;
                    }
                    case "name": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        auto it = for_each(vst.begin(), vst.end(), NameFinder(cmd[2], cmd[3]));
                        for(auto x: it)
                            x.displayId(cout);
                        break;
                    }
                    case "grade": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        else if(!(iss>>cmd[4])){
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder1(cmd[2], cmd[3]));
                            for(auto x: it)
                                x.displayId(cout);
                        }
                        else {
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder2(cmd[2], cmd[3], cmd[4]));
                            for(auto x: it)
                                x.displayId(cout);
                        }
                        break;
                    }
                }
                break;
            }
            case "-showid": {    
                sort(vst.begin(), vst.end(), Cmp("ds"));
                if(!(iss >> cmd[1] >> cmd[2])) {
                    for (auto& x: vst)
                        x.displayId(cout);
                }                   
                switch(cmd[1]) {
                    case "id": {
                        auto it = for_each(vst.begin(), vst.end(), IDFinder(cmd[2]));
                        for(auto x: it)
                            x.displayId(cout);
                        break;
                    }
                    case "name": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        auto it = for_each(vst.begin(), vst.end(), NameFinder(cmd[2], cmd[3]));
                        for(auto x: it)
                            x.displayId(cout);
                        break;
                    }
                    case "grade": {
                        if(!(iss>>cmd[3]))
                            cout << endl;
                        else if(!(iss>>cmd[4])){
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder1(cmd[2], cmd[3]));
                            for(auto x: it)
                                x.displayId(cout);
                        }
                        else {
                            auto it = for_each(vst.begin(), vst.end(), GradeFinder2(cmd[2], cmd[3], cmd[4]));
                            for(auto x: it)
                                x.displayId(cout);
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
}