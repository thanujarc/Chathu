#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

void print(const int & i){
    printf("num: %i \n",i);
}
int main(){
    vector<int> a={1,2,3,4};

    //method 1
    // using bind
    for_each(a.begin(),a.end(),bind(&print,std::placeholders::_1));

    //method 2
    //basic lambda
     for_each(a.begin(),a.end(),[](const int &i){printf("num_lambda: %i \n",i);});

    //method 3
    //reusable lambda
    auto mylambda=[](const int &i){printf("num_lambda 2: %i \n",i);};
    for_each(a.begin(),a.end(),mylambda);

    //method 3 with surrounding scope for lambda
    int k=2;
    auto mylambda2=[&](const int &i){printf("num_lambda 2 :%i*%i= %i \n",i,k,i*k);};
    for_each(a.begin(),a.end(),mylambda2);



}