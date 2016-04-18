using namespace std;
//B contains A, C inheritance from B
struct A{
    A(){ cerr << "A()" << endl; }
    A(const A& src) { cerr << "A(const A&)" << endl; }
    A& operator=(const A& src){
        cerr << "A::operator=" << endl;
        return *this;
    } 
    ~A() { cerr << "~A()" << endl; }
};

struct B{
    B(){ cerr << "B()" << endl; }
    B(const B& src): a_(src.a_) { cerr << "B(const B&)" << endl; }
    B& operator=(const B& src){
        a_ = src.a_;
        cerr << "B::operator=" << endl;
        return *this;
    } 
    ~B() { cerr << "~B()" << endl;
    
    A a_;
};

struct C: public B{
    C(): B() { cerr << "C()" << endl; }
    C(const C& src): B(src) { cerr << "C(const C&)" << endl; }
    C& operator=(const C& src){
        B::operator=(src);
        cerr << "C::operator=" << endl;
        return *this;
    } 
    ~C() { cerr << "~C()" << endl;  
};

// anything not is initialized in the member initializer list 
//is automatically initialized by the default ctor

int main(){
    A a1;                 //default ctor
    A a2[3];              //default ctor 3 times
    A a3(a1);             //copy ctor 
    A a4 = a1;            //copy ctor
    a1 = a4;              //copy assignment
    A *p1 = new A;        //default ctor
    A *p2 = new A(a4);    //copy ctor
    delete p1;            //dtor
    delete p2;            //dtor
    
    C c1;
    cerr << "****" << endl;
    C c2(c1);
    cerr << "****" << endl;
    C c3 = c2;
    cerr << "****" << endl;
    c3 = c1;
    cerr << "****" << endl;

    B b1;
    B b2(b1);
    b1 = b2;
}