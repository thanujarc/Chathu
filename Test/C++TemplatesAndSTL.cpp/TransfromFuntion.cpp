//The transform function is used to run bulk transformations on elements in a container.
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

template <typename T>
//writing atemplate class with a fucntor
class accum{
    private :
        T x;
    public:
        accum(T a):x(a){};
        //functor
        T operator()(T a) {return a+x;}//operator overlaod for the function call operator
};

size_t getsize(string s ){
    return s.size();
}

int addTwo(int a, int b){
    return a+b;
}

//Converting strings to Titlecase with a functor
class TitleCase{
    bool _lastIsSpace;
    public:
        TitleCase():_lastIsSpace(true){};
        char operator()(const char a){
            if(a==' '){
                _lastIsSpace=true;
                return a;
            }
            else{
                
                if(_lastIsSpace){
                    _lastIsSpace=false;
                    return toupper(a);
                }
                else{    
                    _lastIsSpace=false;
                    return a;
                }
            }
            
        };
};

int main(){
    accum<int> obj(7); //initialie with int 7
    cout<<obj(5)<<endl;// using functor add 5 to 7

    vector<int> adder={1,2,3,4,5};
    for(auto itr=adder.begin();itr<adder.end();++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;

    vector<int> out(adder.size());
    //use transform function to perform add operation
    transform(adder.begin(),adder.end(),out.begin(),obj);
    for(auto itr=out.begin();itr<out.end();++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;

    //you can use a lambda function in place of a functor
    int init=4;
    auto lambdafunc=[init](int d) {return d+init;};
    //use transform function to perform add operation
    transform(adder.begin(),adder.end(),out.begin(),lambdafunc);
    for(auto itr=out.begin();itr<out.end();++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;


    //you can use a normal function as well
    vector<string> ss={"aa","vvvv","cat"};
    vector<int> sizes_ss(ss.size());
    transform(ss.begin(),ss.end(),sizes_ss.begin(), getsize);
    for(auto itr=sizes_ss.begin();itr<sizes_ss.end();++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;

    //string manupulation
    string k="this is my code";
    string out_k(k.size(),'.');
    TitleCase titleCase;
    transform(k.begin(),k.end(),out_k.begin(), titleCase);
    cout<<out_k<<endl;

    //transform function can handle 2 sources
    transform(adder.begin(),adder.end(),adder.begin(),out.begin(), addTwo);
    for(auto itr=out.begin();itr<out.end();++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;
    


}