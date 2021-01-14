#include <stdio.h>
#include <string>
#include<iostream>
using namespace std;

class A{
    int _value;
    string _name;
public:
    A();// constructor
    A(int ,string &);// constructor
    A(const A &) ;//copy constructor
    ~A();//destructor
    void set_v(const int) ;
    int get_v () const ;
    int get_v ();
    void print () const;
    //string conversion operator overloading
    operator:: std::string() const;
};
A::A():_value(0), _name("unknown"){
    printf(" default constructor \n");
}
A::A(int i, string & name):_value(i), _name(name){
    printf(" constructor with params \n");
}
A::A(const A & rhs){
    printf(" copy constructor \n");
    _value=rhs._value;
    _name="copy of "+rhs._name;

}
A::~A(){
    printf(" destructor of %s \n",_name.c_str() );
}

void A::set_v(const int a){
    _value=a;
}
int A::get_v(){
    printf("mutable get_v \n");
    return _value;
}

int A::get_v() const {
    printf("const get_v \n");
    return _value;
}
void A::print() const{
     printf("Pointer %p Name %s , value %i \n", this, _name.c_str(), _value);
}

A::operator std::string() const{
    //tell what to do when this object is converted to a string
    return std::to_string(_value);
}

int main(){
A a1;
a1.print();
a1.set_v(10);
printf("value %i \n",a1.get_v());
const A a2=a1;
printf("value %i \n",a2.get_v());
a2.print();
string s= "Object is ";
s+=a1;
cout<<"Printing " << s<<endl;

return 0;

}
