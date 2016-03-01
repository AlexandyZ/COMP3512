#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string line;
	while(getline(cin, line)){
        istringstream iss(line);
		string w1, w2;
		if(!(iss >> w1 >> w2)){
			break;
		}
		isstringstream iss1(w1);
		int a; char b; int c; char d;
		iss1 >> a >> b >> c >> d;
		string t;
		isstringstream iss2(w2);
		if(b == '.'){
			double dou;
			iss2 >> dou;
			
		}else{
			int in;
			iss2 >> in;
			if(b == 'd')
				t = "dec";
			if(b == 'o')
				t = "oct";
			if(b == 'x')
				t = "hex";
			if(b == 'X')
				t = "uppercase << hex";
			cout << right << t << setw(a) << in << endl;
		}
	}
}