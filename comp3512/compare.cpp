#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Student {
	string id, firstname, lastname;
	int score;
	Student(const string& i = "default", const string& f = "first",
		const string& l = "last", int s = 0) : id(i), firstname(f), lastname(l), score(s){}
};

//for using multimap; function class
struct NameCmp{
	bool operator()(const Student& lhs, const Student& rhs)const{
		if(lhs.lastname!=rhs.lastname){
			return lhs.lastname<rhs.lastname;
		}
		return lhs.lastname<rhs.lastname;
	}
};

//overload output operator
ostream& operator<<(ostream& os, const Student& s){
	return os<<s.id<<' '<<s.firstname<< ' '<<s.lastname<<' '<<s.score;
}
//overload input operator
istream& operator>>(istream& is, Student& s){
	return is>>s.id>>s.firstname>>s.lastname>>s.score;
}

bool operator<(const Student& lhs, const Student& rhs){
	return lhs.id < rhs.id;
}
int main(){
	set<Student> s;
	set<Student, NameCmp> ss;
	/*string id, first, last;
	int score;

	while(cin>>id>>first>>last>>score){
		s.insert(Student(id,first,last,score));
	}
	for(const auto& st:s){
		cout <<st.id<<' '<<st.firstname<< ' '<<st.lastname<< ' '<<st.score<<endl;
	}*/
	Student st;

	while(cin>>st){
		ss.insert(st);
	}
	for(const auto& x : ss){
		cout << x << endl;
	}
	//using overloaded input and output operators
}