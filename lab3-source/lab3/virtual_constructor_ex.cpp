#include<iostream>
using namespace std;

class Base
{
    public:
        Base() {cout<<"base constructor\n";}
        ~Base() {cout<<"base's destructor\n";}
};
class Derived : public Base
{
    public:
        Derived() {cout<<"constructor of the derived class\n";}
        ~Derived() {cout<<"Derived's destructor\n";}
};
int main()
{
    Base *p = new Derived;
    delete p;
}