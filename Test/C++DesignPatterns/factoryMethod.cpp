#include <iostream>
#include <string.h>
using namespace std;


enum class CofeeTypes{
    espresso, cappacino
};

class Coffee{
    
protected:
    char _type[15];
    Coffee(){}; //constructor is protected so that Coffee objects cannot be made directly

public:
    char* getType(){
        return _type;
    };

};

class Espresso : public Coffee{
    
     public:
        Espresso(){
            strcpy(_type,"Espresso");
        };
};

class Cappacino : public Coffee{
    public :
       Cappacino(){
           strcpy(_type,"Cappacino");  
       };
};

class CoffeeFactory{
    public:
        CoffeeFactory(){};
        Coffee * getCoffee(CofeeTypes coffeeType){
            switch (coffeeType){
                case CofeeTypes::espresso:
                    return new Espresso;
                case CofeeTypes::cappacino:
                    return new Cappacino;

            };
                
        };
};

int main(){
    CoffeeFactory factory;
    Coffee* coffee1 = factory.getCoffee(CofeeTypes::cappacino);
    cout << "This coffree is "<<coffee1->getType()<< endl;

    Coffee* coffee2=factory.getCoffee(CofeeTypes::espresso);
    cout<<"This coffee is"<<coffee2->getType()<<endl;

     delete coffee1;
     delete coffee2;


}