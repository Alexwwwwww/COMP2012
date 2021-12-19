#include <iostream>
using namespace std;

class Uperson
{
    private:
    std::string name;
    int age;
    virtual void sayhehe() const
    {
        cout<<"hehe Uperson"<<endl;
    }
    public:
    
    Uperson(string name, int age){
        this->name=name;
        this->age=age;
        cout<<name<<" is of age "<<age<<endl;
    }
    Uperson(){cout<<"uperson conster\n";}
    int get_age()
    {
        return age;
    }
    
};
class Ug: private Uperson
{
    private:
    std::string major;
    public:
    Ug():Uperson("Desmond",18){cout<<"Ug constructor\n"<<" get age "<<age<<endl;}
    // Ug(string name, int age):Uperson(name,age){
    // }
    // // int get_old(){
    // //     return ++age;
    // // }
    void sayhehe() const
    {
        cout<<"hehe UG"<<endl;
    }
    
};

int main()
{
    
   Ug desmond;
    //desmond.get_old();
    //cout<<"desmond"<<endl;
  // Uperson* p=&desmond;
    //p->sayhehe();
}
// #include <iostream> /* File: implicit-conversion-surprise.cpp */

// #include <cstring>

// using namespace std;

 

// class Word {

//   private:

//     int frequency; char* str;

//   public:

//     Word(char c) {

//       frequency = 1; str = new char[2]; str[0] = c; str[1] = '\0';

//       cout << "call implicit char conversion\n";

//     }

//     Word(const char* s) {

//       frequency = 1; str = new char [strlen(s)+1]; strcpy(str, s);

//       cout << "call implicit const char* conversion\n";

//     }

//     ~Word() { cout << "dtor" << endl; }

//     void print() const { cout << str << " : " << frequency << endl; }

// };

 

// void print_word(Word x) { x.print(); }

 

// int main() { print_word("Titanic"); print_word('A'); return 0; }
