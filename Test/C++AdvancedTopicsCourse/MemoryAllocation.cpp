//The new and delete operators are used to allocate and deallocate memory in C++
#include <stdio.h>
#include <iostream>
using namespace std;
class MemoryAllocation
{

int _a=0;
int _b=0;
int _c=0;

public:
    MemoryAllocation(int i=0);
    ~MemoryAllocation();
    int a(){return _a;};
    int b(){return _b;};
    int c(){return _c;};


};


MemoryAllocation::MemoryAllocation(int i): _a(i), _b(i+1),_c(i+2)
{
    cout<<"constructor"<<endl;
}

MemoryAllocation::~MemoryAllocation()
{
    cout <<"destructor"<<endl;
}

int main(){
    //can use nothrow instead of try and catch
    MemoryAllocation * A = new(nothrow) MemoryAllocation();
    if (A == nullptr){
        cout <<"Error allocating memory"<<endl;
        return 1;
    }
    cout<<"a "<<A->a()<<" b "<<A->b()<<" c "<<A->c()<<endl;
    delete A;
    return 0;

}