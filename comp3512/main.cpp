#include <iostream>
using namespace std;

Class A {
public:
	virtual ~A() {}
	virtual void f1() { cerr << "A::f1()" << endl; }
	virtual void f2() { cerr << "A::f2()" << endl; }
	virtual void f3(int n = 1) { cerr << "A::f3(" << n << ")" << endl; }
	virtual void f4() { cerr << "A::f4()" << endl; }
	virtual void f5() { cerr << "A::f5()" << endl; }
};

Class B: public A {
public:
	virtual ~B() {}
	virtual void f1() { cerr << "B::f1()" << endl; }
	virtual void f2(int n = 1) { cerr << "B::f2(" << n << ")" << endl; }
	virtual void f3() { cerr << "B::f3()" << endl; }
	virtual void f3(int n) { cerr << "B::f3(" << n << ")" << endl; }
	virtual void f5(int n) { cerr << "B::f5(" << n << ")" << endl; }
};

Class C: public B {
public:
	virtual ~C() {}
	virtual void f2() { cerr << "C::f2()" << endl; }
	virtual void f2(int n = 2) { cerr << "C::f2(" << n << ")" << endl; }
	virtual void f5() { cerr << "C::f5()" << endl; }
};

int main() {
	A a; B b; C c;
	A& rab = b;
	A& rac = c;
	B& rbc = c;
	
	cerr << "1.:  ";
	rab.f1();
	cerr << "2:  ";
	rac.f1();
	cerr << "3:  ";
	rab.f2();
	cerr << "4:  ";
	rbc.f2();
	cerr << "5:  ";
	rab.f3();
	cerr << "6:  ";
	rac.f3();
	cerr << "7:  ";
	rac.f4();
	cerr << "8:  ";
	rbc.f4();
	cerr << "9:  ";
	rbc.f5();
}

