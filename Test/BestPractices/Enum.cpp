#include <stdio.h>

//Method 1 - wrong way
 //This method pollutes the scope. Cannot define same enum values in Flowe and Traffic light;
enum TrafficLight{
    red, green, yellow
};
enum Flower{
    r,g,b
};

//Methid 2 - correct way
enum class Animal{
    cat,dog
};
enum class Pet{
    cat, dog
};

int main(){
    //not correct
    TrafficLight t=TrafficLight::green;
    Flower f=r;


    //correct
    Animal a=Animal::cat;
    Pet p=Pet::cat;

}