#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Interval {
    double start;
    double stop;
};

bool sortStart(Interval I1, Interval I2){
    return I1.start>I2.start;   
}

int arraySort(){
    Interval intArr[]= {{6.89,8},{1,2},{3,4}};
    int n=sizeof(intArr)/sizeof(intArr[0]);
    sort(intArr,intArr+n,sortStart);
    for (int i=0;i<n;i++){
        cout<<intArr[i].start<< " "<<intArr[i].stop<<"\n";
    }
}

int vectorSort(){
    vector<Interval> myVec={{6.89,8},{1,2},{3,4}};
    sort(myVec.begin(),myVec.end(),sortStart);
    for(auto it:myVec){
        cout<<it.start<<" "<<it.stop<<"\n";
    }
    
    return 0;
}

void vectorMinMax(){
  vector<int> mvVec={5,4,5,6,7,8};
  mvVec.insert(mvVec.begin()+3, 1);
  mvVec.erase(mvVec.end()-1);
   int max=mvVec[0];
   int min=mvVec[0];
   for(auto it=mvVec.begin()+1; it != mvVec.end();it++){
       if(*it>max){
           max=*it;
       }
       if (*it<min){
           min=*it;
       }
   }
   cout << max << " " << min;
}

void mapMax(){
    map<string,int> map1;
    map1.insert(make_pair("a",1));
    map1["kk"]=5;
       // cout << i.first << "   " << i.second << endl;        
   // }

}
int main(){
    //vectorMinMax();
    mapMax();
    return 0;
}

