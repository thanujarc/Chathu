//Given an array of integers, return a new array such that each element
// at index i of the new array is the product of all the numbers in
// the original array except the one at i.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> input{1, 2, 3, 4, 5};
    vector<int> output;
    int sum=1;
    for(size_t i=0;i<input.size();i++){
        output.push_back(sum);
        sum=sum*input[i];
    }
    for(auto i:input){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:output){
        cout<<i<<" ";
    }
    cout<<endl;
    sum=1;
    for(size_t i=1;i<input.size();i++){
        sum=sum*input[input.size()-i];
        output[input.size()-i-1]=output[input.size()-i-1]*sum;   
    }

    for(auto i:output){
        cout<<i<<" ";
    }
}