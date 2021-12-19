#include<iostream>
using namespace std;

class A
{
    private:
        int x;
    public:
        A(){x=1;}
        A(const A& a){x=a.x;}
};

int main()
{

}