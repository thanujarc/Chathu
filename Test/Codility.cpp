#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solutions{
    public:
        int frogJump(int, int, int);
        int PermMissingElement(vector<int> &A);
        int tapeEquillibrium(vector<int> &A);
        int FrogRiverOne(int X, vector<int> &A);

};

int Solutions::PermMissingElement(vector<int> &A){
    int missing=1;
    int N=A.size()+1;
    if(N>1){
        std::sort(A.begin(), A.end());
        for(int i=1;i<N;i++){
            if (A[i-1] !=i){
                missing= i;
                break;
            }
             missing= N;
        }
    }
    return missing;
}

int Solutions::tapeEquillibrium(vector<int> &A) {
    int sum=0;
    int diff=0;
    vector<int> sumVec;

    for (auto itr:A){
        sum=sum+itr;
        sumVec.push_back(sum);
    }


    for (auto itr=sumVec.begin();itr<sumVec.end()-1; itr++){
        //printf("%i \n", *itr);
        if ((itr==sumVec.begin()) || (diff>abs(*itr-(sumVec.back()-*itr)))){
            //printf("%i", *itr);
            diff=abs(*itr-(sumVec.back()-*itr));
            //printf("d %i \n", diff);
        }      
    }
    return diff;

    // write your code in C++14 (g++ 6.2.0)
}

int Solutions::frogJump(int X, int Y, int D){
    int jumps=0;
    int distance = Y-X;
    int quotient = distance/D;
    int remainder = distance%D;
   
    if (D>0){
        if (remainder==0){
            jumps = quotient;
        }
        else {
            jumps =  quotient+1;
        }
    }
    return jumps;
}

int Solutions::FrogRiverOne(int X, vector<int> &A) {
    vector<int> positions(X);
    fill(positions.begin(),positions.end(),0);
    int unfilled=X;
    for (unsigned int i=0;i<A.size();i++){
        int position=A[i];

        if( position !=0 && positions[position-1]==0){
            positions[position-1]=1;
           
            unfilled=unfilled-1;
           
        }
        if (unfilled ==0){
            return i;
        }
    }
    return -1;

}

int main(){
    printf("Hi \n");
    Solutions sol;
    printf("frogJump %i \n", sol.frogJump(10,85,30));
    vector<int> A {1,2,3};
    printf("PermMissingElement %i \n", sol.PermMissingElement(A));
    printf("tapeEquillibrium %i \n", sol.tapeEquillibrium(A));
}