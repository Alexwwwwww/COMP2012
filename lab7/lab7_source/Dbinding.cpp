#include <iostream>
using namespace std;
class father
{
    private:
    int age=40;
    public:
    
     void say()
    {
        cout << "father" << endl;
    }
     father& operator=(const father &another)
    {
        cout << "father=" << endl;
        return *this;
    }
    void getold(father& another)
    {
        another.age+=age;
    }
    int get_age()
    {
        return age;
    }
};

class grandchild;
class child : public father
{
public:
    void say()
    {
        cout << "child" << endl;
    }
    child& operator=(const father &another)
    {
        cout << "child=" << endl;
        return *this;
    }
};

class grandchild : public child
{
    int height=1;
    public:
    void say()
    {
        cout << "grandchild" << endl;
    }
    grandchild& operator=(const father &another) 
    {
        cout << "grandchild=" << endl;
        return *this;
    }
};

int main()
{
    father *p1father = new grandchild;
    father *p2father = new grandchild;
    *p2father = *p1father;
    p1father->operator=(*p1father);
    p1father->getold(*p2father);
    cout<<p1father->get_age()<<endl;
    cout<<p2father->get_age()<<endl;

    dynamic_cast<grandchild&>(*p1father)->height;

}