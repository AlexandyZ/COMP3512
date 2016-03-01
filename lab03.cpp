#include <iostream>
#include <string>
#include <vector>
using namespace std;

string rtrim(const string& s){
	string::size_type i, size = s.size();
	for(i = size - 1; i > 0; i--){
		if(!isspace(s[i]))
			break;
	}	
	return s.substr(0,i+1);
}

string replace_all(const string& s, const string& oldstr, const string & newstr){
	string::size_type sz = s.size();
	string s2 = s.substr(0, sz);
	string::size_type os = oldstr.size(), ns = newstr.size(), i = 0;
	while((i = s2.find(oldstr, i)) != string::npos){
		s2.replace(i, os, newstr);
		i += ns;
	}
	return s2;
}

string squeeze(const string& s, char c){
	string::size_type sz = s.size();
	string s2 = s.substr(0, sz);
	string::size_type i = 0;
	while((i = s2.find(c, i)) != string::npos){
		s2.erase(i, 1);
	}
	return s2;
}

vector<string> split(const string& s, const string& delim){
	string::size_type start = 0;
	vector<string> v;
}

int main(){
	cout << rtrim("   hello world\t ") << endl;	
	cout << replace_all("alley-dalley", "al", "oke") << endl;
	cout << squeeze("naahaaasapeemaapetilon", 'a');
}