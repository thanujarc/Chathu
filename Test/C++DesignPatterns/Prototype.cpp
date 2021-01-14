#include <iostream>
using namespace std;
//Base class
class Animal{
    protected:
        int _age=0;
        string _type;

    public:
        virtual Animal * clone()=0;
        void setAge(int age){
            _age=age;
        };

        void printAge(){
            cout<<"Age :"<<_age<<endl;
        }

};

class Cow:public Animal{
    protected:
        int _pintsOfMilk;

    private :
        int _legs;
    
    public:
        Cow(){
             _legs=4;
             _type="Cow";
        };
        void setPintsOfMilk(int pints){
            _pintsOfMilk=pints;

        };

        Cow * clone(){
            return new Cow(*this);
        }

};

int main(){
  Cow * cow0=new Cow();
  cow0->setAge(100);

  Cow * cow1=cow0->clone();
  cow1->setAge(50);

  cout<<"Cow0 ";
  cow0->printAge();
  cout<<"Cow1 ";
  cow1->printAge();



}