#include<stdio.h>
#include<iostream>
#include <memory>
using namespace std;

class A{
    int _val=0;
    public:
     A(int val):_val(val){printf("Called constructor of %i \n",_val);};
     ~A(){printf("Called destructor of %i \n",_val);};  
     void print() const {printf ("%i \n", _val);};
};

void printData(unique_ptr<A> & ptr){
    printf("Printing inside the function : ");
    ptr->print();
}

void deleter(const A* obj){
    if(obj){// if object is not null
        printf("Custom deleting object:  ");
        obj->print();
        delete obj ;
    }
}

void uniquePointerExample(){
    //create a unique pointer
    unique_ptr<A> ptr1(new A(5));
    ptr1->print();

    //create a unique pointer with make_unique, from c++ 17 onwards
    auto ptr2 =make_unique<A>(4);
    ptr2->print();

    //reset method can be used to destroy an object or replace it with a new one
    ptr1.reset(new A(3));
    ptr1->print();

    //can move a pointer using 'move'
    auto ptr3 =move(ptr1);
    ptr3->print();

    //'release' releases the smat pointer from the object, it does not delete 
    //the object (not calling the destructor). simply releases the obejct from managed memory.
    ptr3.release();

    //Unique pointers can only be passed to functions by reference, not by value.
    printData(ptr2);

    printf ("End of scope \n");

}

void sharedPointerExample(){
    //create a shared pointer
    shared_ptr<A> ptr1(new A(1));
    ptr1->print();

    //create a shared pointer with make_unique, from c++ 17 onwards
    auto ptr2 = make_shared<A>(2);
    ptr2->print();

    //copying the pointer
    auto ptr3=ptr2;
    ptr3->print();

    //you can specify cuntom deleter function, 
    //in case you need to clean up some other dependent resources.
    shared_ptr<A> ptr4(new A(4),deleter);
    ptr4.reset();

    printf("End of scope \n");

}

int main(){
    //uniquePointerExample();
    sharedPointerExample();


}

