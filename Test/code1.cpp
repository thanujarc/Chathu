#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
using namespace std;

int solutionBinaryGap(int N)
{
    //binary gap
    int zerosCount = 0;
    int maxZrosCount = 0;
    while (N > 0)
    {
        if (N % 2 == 0)
        {
            zerosCount = zerosCount + 1;
        }
        else
        {
            if (maxZrosCount < zerosCount)
            {
                maxZrosCount = zerosCount;
            }
            zerosCount = 0;
        }
        N = N / 2;
    }
    cout << "maxZrosCount" << maxZrosCount << "\n";
    return maxZrosCount;
}

vector<int> arrayRotate(vector<int> arrayIn, int k)
{
    int size = arrayIn.size();
    vector<int> arrayOut;

    for (int i = 0; i < size; i++)
    {
        int rotateIndex;
        if (i + k >= size)
        {
            rotateIndex = i + k - size;
        }
        else
        {
            rotateIndex = i + k;
        }
        arrayOut.push_back(arrayIn[rotateIndex]);
    }

    for (auto obj : arrayOut)
    {
        cout << obj << " ";
    }

    cout << "\n";

    for (auto obj : arrayIn)
    {
        cout << obj << " ";
    }

    return arrayOut;
}

vector<int> arrayRotate2(vector<int> &A, int K)
{
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B;
    int L=0;
    if(!A.empty())
        L=K%A.size();
    cout<< L<<"\n";
    if (L!=0){
        B.insert(B.end(),A.end()-L,A.end());
        B.insert(B.end(),A.begin(),A.end()-L);
        
    }
    else{
        B.insert(B.end(),A.begin(),A.end());
    }
        

    for (auto obj : A)
    {
        cout << obj << " ";
    }
    cout << "\n";
    for (auto obj : B)
    {
        cout << obj << " ";
    }
    return B;
}

int solutionOdd(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int odd=0;
    map<int,int> count;
    for(auto B:A){
        count[B]=count[B]+1;
    }

    for(auto B:count){
        if (B.second%2!=0){
            odd = B.first;
        }
    }
    return odd;
}

int solutionFrog(int X, int Y, int D) {
    int distance = Y-X;
    float jumps=(float)distance/(float)D;
    int jumps_rounded=ceil(jumps);
    cout << jumps_rounded;
    return jumps_rounded;
}

int solutionTape(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sums;
    sums.push_back(A[0]);
    for (int i=1;i<A.size();i++){
        sums.push_back(A[i]+sums[i-1]);
    }
    int minDiff=abs(sums[0]-(sums[A.size()-1]-sums[0]));
    for (int i=1;i<A.size()-1;i++){
        int diff=abs(sums[i]-(sums[A.size()-1]-sums[i]));
        if (minDiff>diff){
            minDiff=diff;
        }
    }
    return minDiff;
}


vector<int> solutionCounter(int N, vector<int> &A){
    vector<int> counters(N);
    fill(counters.begin(),counters.end(),0);
    for(auto index:A){
        if (index<=N){
            counters[index-1]=counters[index-1]+1;
        }
        else{
            int max=counters[0];
            for(auto counter : counters){
                if (max<counter){
                    max=counter;
                }
            }
            fill(counters.begin(),counters.end(),max);
        }

    }
    return counters;
}

class Stats{
    vector<int> A;
    public:
        Stats(vector<int> Ain);
        float mean();
        float standardDeviation();
        ~Stats();


};
Stats::Stats(vector<int> Ain){
    A=Ain;
}
    
float Stats:: mean(){
    int sum = accumulate(A.begin(), A.end(), 0);
    float mean =(float)sum/(float)A.size();
}

float Stats::standardDeviation(){
    float meanval= mean();
    float variance=0;
    for (auto a : A){
        variance =variance+(a-meanval)*(a-meanval);
    }
    float sdev= sqrt(variance)/(A.size()-1);
    return sdev;
}

Stats:: ~Stats(){
}



int main()
{
    vector<int> arrayIn = {3, 4, 4, 6, 1, 4, 4};
    //arrayRotate2(arrayIn, 1);

   //cout<< solutionOdd(arrayIn);
   //solutionFrog(1,1000000000, 2) ;
   //cout << solutionTape(arrayIn);
   vector<int> out = solutionCounter(1,arrayIn);
   for(auto a:out){
       cout<< a<< " ";

   }

    return 0;
}