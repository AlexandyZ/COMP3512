struct A{
    int n_;
    //A() = default;
    A(int n): n_(n) {}
}

struct B{
    A a_;
    B(const A& a): a_(a) {}
    //B(const A& a) { a_ = a; }  // compiler calls default ctor of A
}

int main(){
    B b(1);
}