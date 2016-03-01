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

void input_data(fstream& fs);
void display_data(fstream& fs);

int main(int argc, char* argv[])
{
	int choice;
	string prompt;

	if(argc!=2){
		cerr<<"usage: "<<argv[0]<<"[srcfile]\n";
		return 1;
	}
	fstream in(argv[1], ios_base::in|ios_base::binary);

	if(!in){
		cerr<<"unable to open"<<argv[1]<<endl;
		return 2;
	}

	while(get_valid_int(prompt,choice,get_valid_int(choice))){
		if(choice == 1){

		}
		else if(choice == 2){

		}
		else{
			cout<<"please enter valid number"<<endl;
		}
	}
	return 0;
}
void input_data(fstream& fs)
{

}

void display_data(fstream& fs)
{
	int n;
	char word[15];

	
	while(get_valid_int){
		if(!getline(cin,fs).eof())
		{
			cin.clear();
			break;
		}
		if(!(fs >> n))
		{
			break;
		}
		if(!is_valid(n))
		{
			break;
		}
		if(fs >> n){
			if(n > 0){
				fs.seekg(n,fs.beg);
			}
			if(n < 0){
				for(int i = n; i <= n; i++){
					fs.seekg(i,fs.beg);
				}
			}
			if(n == 0){
				cout << fs << endl;
			}
		}
	}
}

bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&))
{
	string line;
	while(1){
		cout << prompt;
		if(getline(cin,line).eof())
		{
			cin.clear();
			break;
		}
		istringstream iss(line);
		if(!(iss >> word))
		{
			return false;
		}
		if(!(is_valid(word))){
			return false;
		}
	}cout << word << endl;
	return true;
}

bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int))
{
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
bool valid_word(const string& s)
{
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
bool valid_num(int n)
{
	if(n > 100 || n < 0){
		return false;
	}
	return true;
}