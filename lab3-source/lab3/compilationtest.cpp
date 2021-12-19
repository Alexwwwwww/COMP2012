#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "A's default contor\n"; }
    A(int a) { cout << "A's conversion contor\n"; }
    ˜A() { cout << "A's destor\n"; }
};
class B
{
public:
    B() { cout << "B's default contor\n"; }
    B(const B &b) { cout << "B's copy contor\n"; }
    B(A a) { cout << "B's conversion contor\n"; }
    ˜B() { cout << "B's destor\n"; }
};
class C
{
private:
    A *ap;
    B b1, b2; // Three data members here
public:
    C() : b1(), b2(b1)
    {
        ap = new A;
        cout << "C's default contor\n";
    }
    ˜C()
    {
        cout << "C's destor\n";
        delete ap;
    }
};
class D
{
private:
    A a;
    B b;
    C *cp; // Three data members here
public:
    D() : a(10), cp(new C)
    {
        b = B();
        cout << "D's default contor\n";
    }
    ˜D() { delete cp; }
};
int main()
{
    cout << "--- Construct B object ---\n";
    B obj1(10);
    cout << "--- Construct D object ---\n";
    D obj2;
    cout << "--- Before return ---\n";
    int &a;
    return 0;
}
