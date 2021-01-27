#include<vector>
#include<map>
#include<iostream>
#include <string.h> 
#include <time.h> 
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total_cost=0;
        multimap<int,int> cost_diff;
        
        for(int i=0;i<costs.size();i++){
            cost_diff.insert({costs[i][0]-costs[i][1],i});
        }
        int j=0;
         for(auto diff : cost_diff){  
             cout<<diff.first<<" ";
             if(j<costs.size()/2){
                 //city 1
                total_cost=total_cost+costs[diff.second][0];            
             }
             else{
                 //city 2
                total_cost=total_cost+costs[diff.second][1] ;
             }
             j++;
         }
              
        return total_cost;            
    }
};


   
char* get_date() 
{ 
    char *  buf=new char[80]; 
    time_t  now = time(0); 
    strcpy(buf, ctime(&now)); 
    return buf; 
} 
  
int main(int argc, char *argv[]) 
{ 
    char *date = get_date(); 
    printf("date=%s\n", date); 
    delete[] date;
    return 0; 
}