#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define USE_VECTOR
//#define USE_LIST

class Guest{
    private:
        string _name;

    public:
        Guest(string name):_name(name){};
    
        string getName() const 
        {
           return _name;
        };

};

#ifdef USE_VECTOR
    typedef vector <Guest > mycontainer;
#elif
    typedef list <Guest > mycontainer; 
#endif

void printList(mycontainer * guestlist){
    auto it=guestlist->begin();
    while (it!=guestlist->end()){
        //Guest * temp = it;
        
        cout<<it->getName().c_str()<<endl;
        it++;
    }
}
int main(){
    mycontainer * guestlist=new mycontainer();
    Guest  g1("aa");
    Guest  g2("bb");
    guestlist->push_back(g1);
    guestlist->push_back(g2);
    printList(guestlist);
}

