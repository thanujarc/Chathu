#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<unordered_set>
using namespace std;
void bestCandyCrush(string& s,
                    string& crushedMask,
                    int crushedCounter,
                    string& bestResult,
                    unordered_set<string>& evaluated)
{
    // if the mask was already evaluated, we already have the best
    // result for this recursive path
    if (evaluated.find(crushedMask) != evaluated.end())
        return;
    
    int n = s.length();
    
    // if the mask was not evaluated, check if we improved the result
    if (n - crushedCounter < bestResult.length())
    {
        bestResult = "";
        
        for (int i = 0; i < n; ++i)
        {
            if (crushedMask[i] == '.')
                bestResult += s[i]; //bbbacc
        }
    }
    
    char prev = 0;
    vector<int> lastMoves;
    
    // try to find some more candies to crush
    for (int i = 0; i < n; ++i)
    {
        for (; i < n; ++i)
        {
            if (crushedMask[i] == 'c')
                continue;
            
            if (s[i] == prev)
                lastMoves.push_back(i);
            else
                break;
        }
        
        // did it find a consecutive group > 3 elements?
        if (lastMoves.size() >= 3)
        {
            // remove the new crushed group
            for (int& move: lastMoves)
                crushedMask[move] = 'c'; //cccccc...
            
            // recursion with the new changes
            bestCandyCrush(s,
                           crushedMask,
                           crushedCounter + lastMoves.size(),
                           bestResult,
                           evaluated);
            
            // backtrack
            for (int& move: lastMoves)
                crushedMask[move] = '.';
        }
        
        prev = s[i]; //a 
        lastMoves.clear();
        lastMoves.push_back(i);//1
    }
    
    evaluated.insert(crushedMask);
}


int main() {
    
    //string s = "baaabbbabbccccdbaaabbbabbdccccdaaabbbbaaabbbabbccccdbaaadbbbabbccccdaaabbb";
    string s = "aaabbbacd";
    string crushedMask(s.length(), '.');
    string bestResult = s;
    
    unordered_set<string> evaluated;
    
    bestCandyCrush(s, crushedMask, 0, bestResult, evaluated);
    
    std::cout << "Res: " << bestResult << endl;
}