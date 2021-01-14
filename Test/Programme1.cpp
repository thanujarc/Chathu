#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    cout << "Hello world \n";
    vector<string> msg{"a","b"};

    for (string& word:msg)
    {
        cout<< word <<"\n";
        word ="changed";
    }

        for (string& word:msg)
    {
        cout<< word <<"\n";
    }


    return 0 ;

}