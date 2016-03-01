#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double n;
	int count, sum, avg;

	while(cin>>n)
	{
	count++;
	sum = sum + n;
	cout << setw(5) << showpos << fixed << setfill('0') << fixed << setprecision(2) << setw(6) << n << endl;
	}
	cout << "----------------" << endl;
	avg = sum/count;
	cout << "avg" << " " << showpos << avg << internal << fixed << setprecision(2) << endl;
}
