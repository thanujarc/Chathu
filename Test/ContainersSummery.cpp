#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

int main(){
    //Vector
    vector<int> my_vector{2,3,4};
    my_vector.push_back(7);//adds to the end
    my_vector.insert(my_vector.begin()+2,7);//moves the elements
    my_vector[1]=6; //replaces the element
    int k=my_vector[2];
    auto itr_vec=find(my_vector.begin(),my_vector.end(), 4); //find if an element exists
    if(itr_vec!=my_vector.end()){
        cout<<"found at "<<*itr_vec <<endl;
    }

    for (auto value:my_vector){
        cout <<value<<endl;
    }

    //List
    list<int> my_list { 12, 5, 10, 9 };
	my_list.push_back(5);
    auto itr=my_list.begin();
    advance(itr,2);  // move by 2
    my_list.erase(itr);
	my_list.insert(itr,7);// adds 7  before the element pointed by it
    int N=8; //move by N
    if (my_list.size() > N)
    {
        list<int>::iterator it = std::next(my_list.begin(), N);
    }


    //map 
    map <string,int> mymap={{"first",1},{"second",2}};
    // Insert
    mymap["Michael"] = 16;
    mymap.insert(std::pair<std::string, int>{"Bill", 25});
    mymap.insert({"Chris", 30});
    pair<string, int> p;
    p.first="hii";p.second=1; mymap.insert(p);
    // Search and change
    mymap["Michael"] = 18;  mymap.at("Chris") = 27;
    //reading values
    int map_val=mymap["Michael"];
    //replacing 
    mymap["Michael"]=8;
    //removing elements
    mymap.erase("Chris");// removed by key
    auto it =mymap.begin();
   // it->first, it->second; //getting key and value
    auto it_map=mymap.find("Michael") ; //find
    if (it_map != mymap.end())
        mymap.erase (it_map);
    

    //set
    set<int> my_set;
    my_set.insert(9);
    my_set.erase(9); //erase by value, not by index
    //check if the insert value is a duplicate
    auto r=my_set.insert(9);//returns a pair.
    // If the second element is false it is a duplicate
    if(!r.second){cout<<"Duplicate"<<endl;}

    //multiset
    multiset<int> my_multiset;





    


}