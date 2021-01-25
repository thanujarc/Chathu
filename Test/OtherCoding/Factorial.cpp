#include<iostream>
#include <vector>
using namespace std;

const int base=4;

class A{
    public:
        int k;
};
void fibonnachi(int levels, vector<int> & result){
    if(levels==base){
        result.push_back(levels);
    }
    else if(levels==base+1){
        fibonnachi(levels-1, result);
        result.push_back(levels);
        
    }
    else{       
        fibonnachi(levels-1, result);
        result.push_back(result[levels-1-base]+result[levels-2-base]);
    }
}

int factorial(int n){
    if(n>1){
        return n*factorial(n-1);
    }
    else
    {
        return 1;
    } 
}
int main(){
    //factorial
    cout<<factorial(3)<<endl;
    vector<int> result;

    //fibonnachi
    fibonnachi(9, result);
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;

    //array of arbitrary trype
    int * a=new int[3]; //array of int type
    a[0]=2;
    a[1]=3;
    a[2]=4;
    for(int i=0;i<3;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    A * b=new A[3]; //array of A type
    b[0].k=1;
    b[1].k=2;
    b[2].k=3;
    for(int i=0;i<3;i++){
        cout<<b[i].k<<" ";
    }

    delete[] a;
    delete[] b;
    



}
