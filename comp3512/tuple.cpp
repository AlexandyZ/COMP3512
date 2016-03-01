#include <tuple>
#include <iostream>
using namespace std;

struct student{

	string id;
	pair<string, string> name;
	int score;
	student(const string &i, const pair<string, string>& n, int s):
	id(i), name(n), score(s){}

};

int main()
{

	tuple<int, char, double> t(1, 'a', 3.14);
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	get<0>(t) = 3;
	cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;

	int n; double d;
	tie(n, ignore, d) = t;
	cout << n << endl;
	cout << d << endl;

	vector<tuple<string, pair<string, string>, int>>
	tuple<string, pair<string, string>, int> t1("a1111111", {"homer"})


}