#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

bool valid_word(const string& s);
bool valid_num(int n);
bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&));
bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int));

void display_data(const string& prompt, int& n, bool (*is_valid)(int));
void get_choice(const string& prompt, int& n, bool (*is_valid)(int));
int main(int argc, char* argv[]){
string prompt;
string id;
int score;

	if(argc!=2){
		cerr<<"usage: "<<argv[0]<<"[srcfile]\n";
		return 1;
	}
	fstream in(argv[1], ios_base::in|ios_base::binary);

	if(!in){
		cerr<<"unable to open"<<argv[1]<<endl;
		return 2;
	}

	if(in){
	cout<<"Enter choice"<<endl;
	cout<<"1. Input records"<<endl;
	cout<<"2. Display records"<<endl;
		get_choice("",score,valid_num);
	}

	return 0;
}
void get_choice(const string& prompt, int& n, bool (*is_valid)(int)){
	while(get_valid_int("", n, valid_num)){
		if(score == 1){
			cout<<prompt;
			get_valid_word("Enter ID: ", id, valid_word);
			get_valid_int("Enter score: ", n, valid_num);
		}
		else if(n == 2){
			display_data("Enter number: ", n, valid_num);
		}
		else{
			cout<<"Enter 1 or 2"<<endl;
			}
	}
}

void display_data(const string& prompt, int& n, bool (*is_valid)(int)){
string line;
	while(1){
		cout << prompt;
		if(!getline(cin,line).eof())
		{
			cin.clear();
			break;
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
		if(iss >> n){
			if(n > 0){
				iss.seekg(n,iss.beg);
			}
			if(n < 0){
				for(int i = n; i <= n; i++){
					iss.seekg(i,iss.beg);
				}
			}
			if(n == 0){
				cout << iss << endl;
			}
		}
	}
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
	if(!(isdigit(n))){
		return false;
	}
	return true;
}