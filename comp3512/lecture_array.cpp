#include <iostream>
#include <array>
#include <utility>

using namespace std;
template <typename T, size_t N>

void print(array<T,N> &a);
void triple(int *a, size_t n);

int main(){
	array <int, 3> a; //random values
	array <int, 3> b {1,2,3};

	print(a);
	print(b);
	a = b;
	print(a);

	triple(a.data(), a.size());
	print(a);
	b[0] = 2;
	print(b);
	cout << (a < b) <<endl;
}
template <typename T, size_t N>
void print(array<T,N> &a){
	size_t i;
	for(i = 0; i < N; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
void triple(int *a, size_t n){
	size_t i;
	for(i = 0; i < n; i++){
		a[i] *= 3;
	}
}