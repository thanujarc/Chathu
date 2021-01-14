#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
//base class
class Animal{
    string _name;
    string _type;
    string _sound;

    //Make constructor private so that animal objects cannot be created directly
    Animal(){}

    protected:
    //Accessible from derived classes
    Animal(const string& name,const string& type, const string& sound):_name(name),_type(type),_sound(sound){}

    public:
    const string& getName () const{return _name;}
    const string& getType() const{return _type;}
    //If you are overiding a function in the derived class, put virtual 
    //in front of the base class method, otherwise when a Dog pointer is assigned to 
    //an Animal object it will not look for the overloaded function in the Dog class.
    virtual const string& getSound () const{return _sound;}
    virtual ~Animal(){}


};
//base class
class Fur{
    string _quality;
    Fur();
    protected :
        Fur(const string &q):_quality(q){}
    public:
        const string & getQuality() const{return _quality;};
};

//Dog inherits from Animal
class Dog: public Animal, public Fur{
private:
    int _walked;
    string val;
public:
    Dog( string name,  string quality):Animal(name,"Dog","Woof"),_walked(0),Fur(quality){};
    const string& getSound();
};
const string& Dog::getSound(){
    val="hi "+Animal::getSound();
    return val;
}

int main(){

    Dog d("Teddy", "good");
    printf("Dog Details: %s,  %s,  %s,  fur quality %s \n ",d.getType().c_str(),
    d.getSound().c_str(),d.getName().c_str(), d.getQuality().c_str());
    //cout<<d.getType()<<" "<<d.getSound()<<endl;

    Animal *a=&d;
    printf("Animal Details: %s,  %s,  %s  \n ",a->getType().c_str(),a->getSound().c_str(),
    a->getName().c_str());
    


}

