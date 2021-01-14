#include <stdio.h>
#include <string>
using namespace std;

//part of revrese the strings probem
template<typename T>
T reverseString(T last){
    return last;
}

//revrese the strings
template<typename T, typename ... Args>
T reverseString(T first, Args ... args){
     return (reverseString(args ...)+ " "+first);
};


//add numbers

template <typename T>
T addNumbers(T num){
    return num;
}
template<typename T, typename ... Args>
T addNumbers(T first, Args ... args){
     return (addNumbers(args ...)+first);
}




int main(){

    //reverse strings problem
    string s1="aa";
    string s2="bb";
    string s3="cc";

    string ss=reverseString(s1,s2,s3);
    printf("Out : %s",ss.c_str());
    
    //add numbers problem
    printf("Total is : %i", addNumbers(1,2,3,4));


    
}
