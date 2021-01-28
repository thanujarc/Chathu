#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> & a,vector<int> & b){
    int a_size=a.size();
    int b_size=b.size();

    vector<int> result ;

    int i=0;
    int j=0;
    while(i<a_size && j<b_size){
        if(a[i]<b[i]){
            result.push_back(a[i]);
            i++;
        }
        else{
            result.push_back(b[j]);
            j++;
            
        }
    }
    while(i<a_size){
        result.push_back(a[i]);
        i++;
    }

    while(j<b_size){
        result.push_back(b[j]);
        j++;
    }
    return result;
    }


}

int main(){
    vector<int> a{2,4,7};
    vector<int> b{3,5,9,12};
    vector<int> c= Merge(a,b);
    for(int i:c){
        cout<<i<<" ";
    }
}