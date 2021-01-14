#include<iostream>
using namespace std;

template <typename T>

int get_size_in_bits(const T & a){
    return sizeof(a)*8;
}

int main(){
    cout<<"int size (bits) : "<<get_size_in_bits(7)<<endl;
    cout<<"char size(bits) : "<<get_size_in_bits('g')<<endl;
    cout<<"float size(bits) : "<<get_size_in_bits(23.1f)<<endl;
    cout<<"double size(bits) : "<<get_size_in_bits(23.1)<<endl;

    return 0;
}


