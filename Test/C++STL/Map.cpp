#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int,string> mymap;
    pair<int, string> p;

     //Adding elements
    p.first=5;
    p.second="hii";
    mymap.insert(p);

    p.first=7;
    p.second="hello";
    mymap.insert(p);

    p.first=2;
    p.second="hello";
    mymap.insert(p);

    for (auto i:mymap){
        cout<<i.first<<" --> "<<i.second.c_str()<<" , ";
    }
    cout<<endl;

    //removing elements
    mymap.erase(7);// removed by key

    for (auto i:mymap){
        cout<<i.first<<" --> "<<i.second.c_str()<<" , ";
    }
    cout<<endl;

    //duplicate keys  with 'insert : doesn't get replaced
    p.first=2;
    p.second="HELLO";
    mymap.insert(p);

    for (auto i:mymap){
        cout<<i.first<<" --> "<<i.second.c_str()<<" , ";
    }
    cout<<endl;

    //Change value for a key : doesn't get replaced
    mymap.at(2)="BBBB";
    for (auto i:mymap){
        cout<<i.first<<" --> "<<i.second.c_str()<<" , ";
    }
    cout<<endl;

    //Get value by key
    cout<<"key =2 "<<mymap[2]<<endl;

    //find a value in a map
    auto itr = mymap.find('hii');

    //if (itr != mymap.end()){
    mymap[itr->first] = "John";
    //}
    for (auto i:mymap){
        cout<<i.first<<" --> "<<i.second.c_str()<<" , ";
    }


}