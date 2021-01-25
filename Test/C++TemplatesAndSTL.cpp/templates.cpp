#include<iostream>
#include<string>
using namespace std;
template <typename T>
T maxOf(const T & a, const T & b){
    return (a>b?a:b);
}

template<typename lT, typename rT>
auto concatData( const lT & a, const rT & b){
return a+b;
}

int main(){
   //simple template
   cout<<maxOf<int>(1,2)<<endl;


   //template with auto
   auto out=concatData<int, float>(5,6);
   cout<<"Type of output is "<<typeid(out).name()<<endl;
   cout<<"Output is "<<out<<endl;

   string s="aa";
   char * a="bb";
   auto out2=concatData<string, char*>(s,a);
   cout<<"Type of output is "<<typeid(out2).name()<<endl;
   cout<<"Output is "<<out2<<endl;

   //getting the type
   decltype(out2) out3=out2;


}