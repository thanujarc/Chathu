//Given an encoded string, return its decoded string.

//The encoding rule is: k[encoded_string], where 
//the encoded_string inside the square brackets is being
// repeated exactly k times. Note that k is guaranteed to be a positive integer.

#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

string repeat(string s,int n){
    string output="";
    for(int i=0;i<n;i++){
        output+=s;
    }
    return output;
}

string decodeString(string s){
    stack<char> stackS;
    string out;

    for(int i=0;i<s.size();i++){
        if(s[i]==']'){
            string temp;
            while(stackS.top()!='['){
                temp.push_back(stackS.top());
                stackS.pop();
            }
            stackS.pop();//remove '['

            //get the repeating number
            int repeatN=0;
            int x=1;
            while(!stackS.empty() && isdigit(stackS.top()) ){
                string topE={stackS.top()};
                repeatN=repeatN+stoi(topE)*x;
                stackS.pop(); //remove number
                x*=10;
            }
          

            reverse(temp.begin(),temp.end());
            string temp_string=repeat(temp,repeatN);//create repeated string

            for(int j=0;j<temp_string.size();j++){ //push temp string back to the stack
                stackS.push(temp_string.at(j));
            }
        }
        else {
           stackS.push(s[i]);
        }
        
    }
    while(!stackS.empty()){
        out=out+stackS.top();
        stackS.pop();
    }
    reverse(out.begin(),out.end());
    return out;
}




int main(){
    string s="3[a2[c]]";
    cout<<s<<endl;
    cout<<decodeString(s)<<endl;
}