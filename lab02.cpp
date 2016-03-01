#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

bool is_valid_word(const string& s);
bool is_valid_num(int n);
bool get_word(const string& prompt, string& word, bool (*is_valid)(const string&)){
	string line;
	while(1){
		cout << prompt << endl;
		if(!getline(cin, line)){
			cin.clear();
			break;
		}
		istringstream iss(line);
		if(!(iss >> word)){
			return false;
		}
		if(iss.eof()){
			break;
		}
		if(!(is_valid_word(word))){
			return false;
		}
	}
	return true;
}

bool get_int(const string& prompt, int& n, bool (*is_valid)(int)){
	string line;
	while(1){
		cout << prompt << endl;
		if(!getline(cin, line)){
			cin.clear();
			break;
		}
		istringstream iss(line);
		if(!(iss >> n)){
			return false;
		}
		if(iss.eof()){
			break;
		}
		if(!(is_valid_num(n))){
			return false;
		}
	}
	return true;
}

bool is_valid_word(const string& s){
	if(s[0] != 'A'){
		return false;
	}
	if(s.length() != 9){
		return false;
	}
	for(int i = 1; i < 9; i++){
		if(!isdigit(s[i])){
			return false;
		}
	}
	return true;
}

bool is_valid_num(int n){
	if(n < 0 || n > 100){
		return false;
	}
	return true;
}

int main(){
	string id;
	int score;
	
	while(1){
	get_word("Pleas enter your ID", id, &is_valid_word);
	get_int("Please enter your score", score, &is_valid_num);
	cerr << id << ' ' << score << ' ' << endl;
	}
}
