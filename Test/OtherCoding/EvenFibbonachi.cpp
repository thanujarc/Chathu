#include <iostream>
#include<chrono>
using namespace std;
//function for calculating the sum of first n even fibonnachi numbers
int getEvenFibonnachiSum(unsigned int n){
    //Initializing fibonna
    int fibbonachi0=0; 
    int fibbonachi1=1;
    int sum=0;

    for(unsigned int i=0;i<n;i++){
        int fibbonachi3=fibbonachi0+2*fibbonachi1;//next even valued fibonnachi number
        sum =sum +fibbonachi3;
        fibbonachi1=fibbonachi3+fibbonachi0+fibbonachi1; 
        fibbonachi0=fibbonachi3;    
    }

    return sum;
}
int feven(unsigned int n, int fibbonachi0, int fibbonachi1, int sum){
        if(n==0){
            return sum;
        }
        int fibbonachi3=fibbonachi0+2*fibbonachi1;//next even valued fibonnachi number
        sum =sum +fibbonachi3;
        fibbonachi1=fibbonachi3+fibbonachi0+fibbonachi1; 
        fibbonachi0=fibbonachi3; 
        sum=feven(n-1, fibbonachi0,  fibbonachi1, sum);
        return sum;
    
}
int getEvenFibonnachiSum_recursive(unsigned int n){
    //Initializing fibonna
    int fibbonachi0=0; 
    int fibbonachi1=1;
    int sum=0;
    return  feven(n, fibbonachi0,  fibbonachi1, sum);
}

int main(){
    cout<<getEvenFibonnachiSum_recursive(100)<<endl;
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    getEvenFibonnachiSum_recursive(100);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    begin = std::chrono::steady_clock::now();
    getEvenFibonnachiSum(100);
    end = std::chrono::steady_clock::now();

    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}