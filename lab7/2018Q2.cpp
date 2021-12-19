#include<iostream>
using namespace std;

class uperson
{
    private:
    int age;
    public:
    string name;
    uperson()
    {
        cout<<"default ctor, uperson"<<endl;
    }
    ~uperson()
    {
        cout<<"dtor, uperson"<<endl;
    }
};
class student: private uperson
{
    private:
    double CGA;
    public:
    student()
    {
        cout<<"defalt ctor, student"<<endl;
    }
    ~student()
    {
        cout<<"dtor, student"<<endl;
    }
};
class UGstudent: public student // uperson constructor and destructor all become private and cannot be used by derived class
{
    public:
    UGstudent()
    {
        cout<<"default ctor, UG student"<<endl;
    }
    ~UGstudent()
    {
        cout<<"dtor, UG student"<<endl;
    }
};
int main()
{
    UGstudent a;
    student p=a;
}