#include<iostream>
using namespace std;


template<typename T>
void f(T x, T y)
{
    cout<<"template"<<endl;
}
template<typename T>// remark: dif from global function. consistency with genral case required
void f(int x, int y)
{
    cout<<"non-template"<<endl;
}
int main()
{
    f(1,2);
    f('a','b');
  //  f(1,'a');
}