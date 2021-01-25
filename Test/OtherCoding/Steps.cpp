#include<iostream>
#include<array>
#include<map>
#include <vector>
using namespace std;
//NOT WORKING
//There's a staircase with N steps, and you can climb 1 or 2 steps at a time.
// Given N, write a function that returns the number of unique ways you can climb the staircase. 
//The order of the steps matters.
array<int,2> steps{1,2};
//map<int,>
//Brute force
//try all combinations for all positions that make 1
//arr=[1,2]
int getRemainder(int rem,int j){
    return (rem-j);
}


void bruteForce_GetCombinations(int N){
    bool complete=false;
    map<int,int> combinations; 
    vector<vector<int>> final_result; 
    vector<int> rem;
    fill(rem.begin(),rem.end(),N);

        //for(size_t i=0;i<sizeof(steps)/steps[0];i++){ //put 1 or 2 in positions if remainder is >0
            for(unsigned int i=0;i<N;i++){  //1s
                for(unsigned int j=0;j<N-i;j++){  //2s
                    if(i*1+j*2==N){
                        pair<int,int> p(i,j);
                        combinations.insert(p);
                        //allCombinations(i, j);

                    
                    }
                }
        }
}



void permuter(vector<int> sequence, int pos, vector<vector<int>> & output){
        if(pos==sequence.size()){
             output.push_back(sequence); 
        }
        else{
            for(int i=pos;i<=sequence.size();i++){
                //if(sequence[i]!=sequence[pos]){
                    //swap
                    int temp=sequence[i];
                    sequence[i]=sequence[pos];
                    sequence[pos]=temp;
                    permuter( sequence, i+1,output);     
                    //swap back
                    sequence[pos]=sequence[i];
                    sequence[i]=temp;
                    
                //}
            }
        }
        
}
void allCombinations(int ones, int twos){
    //vector<int> v{1,2,2};
    int tot_places=ones+twos;
    vector<int> initial(ones+twos);
    fill(initial.begin(),initial.begin()+ones,1);
    fill(initial.begin()+ones,initial.begin()+ones+twos,2);
    vector<vector<int>> output;
    //output.push_back(initial);
    
    permuter(initial, 0, output);

    for(int i=0;i<output.size();i++){
        for (int j=0;j<(ones+twos);j++){
            cout<<output[i][j];
        }
        cout<<endl;
    }
    


}


int main(){
allCombinations(2, 1);

}
