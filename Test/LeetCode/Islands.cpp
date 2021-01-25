#include<map>
#include<vector>
#include<unordered_map>
#include<set>
#include<iostream>
using namespace std;
class Solution {
public:
    int static numIslands(vector<vector<char>>& grid) {
        int islandID=0;
        unordered_map<int,int> islands;
        int m=grid.size();
        int n= grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){

                    islandID=checkSurrounding(grid, islands, i, j, islandID);                                                                    
                }
            }
            
        }
        return findNumIslands( islands);
        
    }
    
    void static changeIslands(int val_old,int val_new, unordered_map<int,int> & islands){
        for(auto it=islands.begin();it!=islands.end();it++){
            if(it->second == val_old){
                it->second=val_new;
            }
        }
    }
    
    int static findNumIslands(unordered_map<int,int> islands){
        set<int> islandIds;
        for(auto it=islands.begin();it!=islands.end();it++){          
            islandIds.insert(it->second);
        }
        return islandIds.size();
    }
    
    int static checkSurrounding(vector<vector<char>>& grid, unordered_map<int,int> & islands, int i, int j, int islandID){
        int m=grid.size();
        int n= grid[0].size();
        int island;
        int key=i*n+j;
        int key_up=(i-1)*n+j;
        int key_left=i*n+j-1;

        
        auto itr_up=islands.find(key_up);
        auto itr_left=islands.find(key_left);

        if(itr_up!=islands.end() && i!=0){ //check for islands up
            //key is found , means not a new island
               
               // check if this one is connected to another island from the left
              if(itr_left!=islands.end() && j!=0){
                  //if that island has a lower island index
                  if(itr_left->second<itr_up->second){
                      //change all in up-island to left-island
                      island=itr_left->second;
                      changeIslands(itr_up->second, itr_left->second, islands);
                      
                  }
                  else{
                      //if that island to the left has a higher island index
                      island=itr_up->second;    
                      changeIslands(itr_left->second, itr_up->second, islands);
                    }
              }
            else{// no islands to the left
                island=itr_up->second;
            }
                
        }
        else if(itr_left!=islands.end() && j!=0){ //check for islands to the left, in this case there are no island to the up
                island=itr_left->second;
        }
       else{ //new island
           islandID++;
           island=islandID;                                  
       }                       
        pair<int,int> p(key,island);
        islands.insert(p);  
        
        return islandID;
       
        
    }
    
 
};

int main(){
    vector<vector<char>> grid{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    cout<< Solution::numIslands(grid) <<endl;
}