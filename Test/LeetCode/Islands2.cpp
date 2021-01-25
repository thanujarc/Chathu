#include<map>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int static numIslands(vector<vector<char>>& grid) {
        int numIslands=0;
        int m=grid.size();
        int n= grid[0].size();
  
        int count = 0; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                    if(grid[i][j]=='1'){
                        checkNeighbours(i,j, grid);
                        numIslands++; 
                    }
            }
        }


        return numIslands;

        
    }

    

    void static checkNeighbours(int i,int j, vector<vector<char>>& grid){
        queue<int> neighbours;
        int m=grid.size();
        int n= grid[0].size();
        grid[i][j]='0';
        neighbours.push(i*n+j);
        
        //check neighbours and change connected land in to water
        //up neighbour
        while(!neighbours.empty()){
            
            int coord=neighbours.front();
            neighbours.pop();
            i=coord/n;
            j=coord%n;
            
            
            //down
            int r=i+1;
            int c=j;
            pushNeighbours(r,c,neighbours, grid );
                
            //up
            r=i-1;
            c=j;
            pushNeighbours(r,c,neighbours, grid );
                
                
            //right
            r=i;
            c=j+1;
            pushNeighbours(r,c,neighbours, grid );
                
            //left
            r=i;
            c=j-1;
            pushNeighbours(r,c,neighbours, grid );
            
        }
    }

    void static pushNeighbours(int r, int c,queue<int> & neighbours, vector<vector<char>>& grid ){
        int m=grid.size();
        int n= grid[0].size();
        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1'){
                neighbours.push(r*n+c);
                grid[r][c]='0';
            }
    }
    
 
};

int main(){
    vector<vector<char>> grid{{'1','1','1'},{'0','0','0'},{'1','1','1'}};
    cout<< Solution::numIslands(grid) <<endl;
}