//The Collatz Conjecture states that you start with a number, 
//and if that number is even you divide it by 2; if the number 
//is odd, you multiply it by 3 and add 1. You then apply the appropriate 
//sum to this result depending on whether it is odd or even, and continue 
//until eventually you end up with 1.

#include<iostream>
#include<vector>
using namespace std;



void collatz(int k,vector<int> & out){
    out.push_back(k);
    if(k==1 || k==0){
        return;
    }
    if(k%2==0){//number even
        k=k/2;
    }
    else{
        k=k*3+1;
    }
    collatz(k, out);
}

int main(){
    int num=10;
    vector<int> out;
    collatz(num,out);
    for(auto i:out){
        cout<<i<<endl;
    }

    
}