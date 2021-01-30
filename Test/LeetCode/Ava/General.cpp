#include <iostream>
#include<chrono>
#include<vector>
using namespace std;
//Question 1
//Write a program in a language of your choice to calculate the sum of the first 100 even-valued
//Fibonacci numbers
int getEvenFibonnachiSum(unsigned int n){
    //Initializing variables
    int fibbonachi_0=0; //0th Fibonacci value is 0
    int fibbonachi_1=1; //1st Fibonacci value is 1
    int sum=0;

    for(unsigned int i=0;i<n;i++){
        int fibbonachi_3=fibbonachi_0+2*fibbonachi_1;//Get next even valued Fibonacci number
        sum =sum +fibbonachi_3;
        fibbonachi_1=fibbonachi_3+fibbonachi_0+fibbonachi_1; 
        fibbonachi_0=fibbonachi_3;    
    }

    return sum;
}

//Ouestion 2
//Write a function in a language of your choice which, when passed two sorted arrays of integers
//returns an array of any numbers which appear in both. No value should appear in the returned
//array more than once.
vector<int> mergeArrays(vector<int> & A, vector<int> B){
    vector<int> output;
    if(A.empty() || B.empty()){
        return output;
    }

    size_t posA=0;
    size_t posB=0;

    while(posA<A.size() && posB<B.size()){
        
        if(A[posA]==B[posB]){ //Check if the value in these positions are equal
            //Add the value if the output array is empty or preveious 
            //element is not equal to the matched element.
            if(output.size()==0||A[posA]!=output[output.size()-1]){
               output.push_back(A[posA]);
            }                   
            posA++;//Move to the next ement in array A
            posB++;//Move to the next ement in array B.
        }
        else if (A[posA]>B[posB]){
            posB++; //Move to the next ement in array B.
        }
        else{
            posA++; //Move to the next ement in array A.
        }
    } 
    return output;
}

//Quetion 3
//Write a function in a language of your choice which, when passed a positive integer returns
//true if the decimal representation of that integer contains no odd digits and otherwise returns
//false.
bool hasOddDigits(unsigned int x){
    const int base=10;
    const int oddDiv=2;
    bool answer=true;
    while(x>0){
        int digit=x%base;
        if(digit%oddDiv!=0){
            answer=false;
            break;
        }
        x=x/10;
    }
    return answer;
}

//Question 4
//Write a function in a language of your choice which, when passed a decimal digit X, returns the
//value of X+XX+XXX+XXXX. E.g. if the supplied digit is 3 it should return 3702
//(3+33+333+3333).
int getRepeatSum(int x){
    const int base=10;
    int sum =0;
    if(x/base != 0){//checking if x is a digit
        return sum;
    }
    const unsigned int repeat=4;

    for(unsigned int i=1;i<=repeat;i++){
        //eg: 3+33+333+3333
        //   =3*(1+11+111+1111)
        //   =3*1234
        sum=sum*base+i;
    }
    sum=sum*x;//in case of repeat=4, 1234*x
}


int main(){
    //Question 1
    int N=100;//number of even fibbonachichi numbers.
    cout<<getEvenFibonnachiSum(N)<<endl;

    //Question 2 
    vector<int> A{4,4,6,6,8,11};
    vector<int> B{1,2,4,7,8,8,9,11};
    vector<int> C;
    C=mergeArrays(A,B);
    for(auto a:C){
        cout<<a<<" ";
    }
    cout<<endl;

    //Quention 3
    int digit=8778;
    cout<<hasOddDigits(digit)<<endl;

    //Question 4
    int repeatNum=9;
    cout<<getRepeatSum(repeatNum)<<endl;

}