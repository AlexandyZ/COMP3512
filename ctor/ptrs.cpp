#include <iostream>
#include <functional>
using namespace std;

struct B{
    int n_;
    B(int n = 0): n_(n) {}
    void inc(int m = 0) { n_ += m; }
    virtual void print() const { cout << "B::print()" << endl; }
    virtual void print(ostream& os) const { os << "B::print(ostream&)" << std::endl; }
};

struct D: public B{
    D(int n = 0): B(n) {}
    virtual void print() const { cout << "D::print()" << endl; }  //if method is virtual, it has polymophic
    virtual void print(ostream& os) const { os << "D::print(ostream&)" << std::endl; }
};

int main(){
    auto inc = &B::inc;  //
    B b;
    (b.*inc)(3);
    cout << b.n_ << endl;
    
    void (B::*print)() const = &B::print; //print is a pointer of function of B 
                                          //that takes no argument and no return
    (b.*print)();  // B print
    
    D d;
    (d.*print)();  // D print
    
    B& r = b;
    (r.*print)();  // B print
    
    B *p = new D;
    (p->*print)();  // D print
    
    auto f = mem_fn(print);  //convert from method call to function call
    f(b);  // B print
    f(d);  // D print
    f(p);  // D print
    
    auto i = mem_fn(&B::inc);
    i(b, 3);
    cout << b.n_ << endl; // 6
    auto pr0 = mem_fn<void() const>(&B::print);
    pr0(b);  //B print
}