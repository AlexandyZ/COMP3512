#include <string>
#include <iostream>
#include <cctype>

using namespace std;

string ltrim(const string& s, int (*is_junk)(int));
string rtrim(const string& s, int (*is_junk)(int));
string cdelete(const string& s, int (*is_junk)(int));
string sdelete(const string& s, const string& junk);
string squeeze(const string& s, char c);
int junk(int n);

int main(){

cout<<ltrim("   hello world  ", ::isspace)<<endl;
cout<<rtrim("   hello world\t ", ::isspace)<<endl;
cout<<cdelete("   hello world\t  ", ::isspace)<<endl;
cout<<sdelete("hoomnmer simpsoomnn", "omn")<<endl;
cout<<squeeze("naahaaasapeemaapetilon", 'a');
return 0;
}

string ltrim(const string& s, int (*is_junk)(int))
{
	string::size_type i;

	for(i = 0; i < s.size(); i++){
		if(!is_junk(s[i])){
			break;
		}
	}
	return s.substr(i);
}

string rtrim(const string& s, int (*is_junk)(int))
{
	string::size_type i = s.size();

	while(i != 0 && is_junk(s[--i])){

	}
	return s.substr(0,(i + 1));
}

string cdelete(const string& s, int (*is_junk)(int))
{
	string::size_type i;
	string t;

	for(i = 0; i < s.size(); i++){
		if(!is_junk(s[i])){
			t += s[i];
		}
	}
	return t;
}

string sdelete(const string& s, const string& junk)
{
	size_type i = 0, junklen = junk.length();
	string copy = s;
	string empty = "";

	while((i = copy.find(junk, i)) != string::npos){
		copy.replace(i,junklen,empty);
	}
	return copy;
}

string squeeze(const string& s, char c)
{
	string::size_type i;
	int prev = 1;
	string temp;

	for(i = 0; i < s.size(); i++){
		if(s[i] != c || prev == c){
			temp += s[i];
			c = s[i];
		}
	}
	return temp;
}

int junk(int n)
{
	return n;
}