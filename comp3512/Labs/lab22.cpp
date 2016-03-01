#include <iostream>
#include <istream>
#include <sstream>
#include <string>
using namespace std;

bool valid_word(const string& s);
bool valid_num(int n);
bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&));
bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int));

int main(){
string prompt;
string id;
int score;

	get_valid_word("Enter ID: ", id, valid_word);

	get_valid_int("Enter score: ", score, valid_num);

	return 0;
}

bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&)){

string line;

	while(1){
		cout << prompt;
		if(getline(cin,line).eof())
		{
			cin.clear();
			return false;
		}
		istringstream iss(line);
		if(!(iss >> word))
		{
			break;
		}
		if(!(is_valid(word))){
			break;
		}
	}cout << word << endl;
	return true;
}

bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int)){
	string line;

	while(1){
		cout << prompt;
		if(!getline(cin,line).eof())
		{
			cin.clear();
			return false;
		}
		istringstream iss(line);
		if(!(iss >> n))
		{
			break;
		}
		if(!is_valid(n))
		{
			break;
		}
	}cout << n << endl;
	return true;
}

bool valid_word(const string& s){
	if(s[0] != 'A'){
		return false;
	}
	if(s.length() > 9 || s.length() < 9){
		return false;
	}
	for(string::size_type i = 1; i < s.size(); i++){
		if(!(isdigit(s[i]))){
			return false;
		}
	}
	return true;
}
bool valid_num(int n){
	if(n > 100 || n < 0){
		return false;
	}
	return true;
}