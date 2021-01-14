#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
   //Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
    vector<int> twoSum(vector<int>& numbers, int target)
    {
    //Runtime: 8 ms, faster than 91.01% of C++ online submissions for Two Sum.
     // Memory Usage: 9.3 MB, less than 62.09% of C++ online submissions for Two Sum.
	unordered_map<int, int> hash; //Number, Index
        
	for (int i = 0; i < numbers.size(); i++) 
        {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) 
			return  {hash[numberToFind] ,i };

		hash[numbers[i]] = i;
	}
	return {};
    }
//Given a string s, find the length of the longest substring without repeating characters.
 int lengthOfLongestSubstring1(string s) {
        string longestSubstring="";
        int length;
        string tempSubstring="";
        for(unsigned int i=0;i<s.length();i++){
            size_t r=tempSubstring.rfind(s.at(i));
            
            if(r==string::npos){
                //cout<<s.at(i)<<endl;
                tempSubstring=tempSubstring+s.at(i);
                
            }
            else{
                if(longestSubstring.length()<tempSubstring.length()){
                     longestSubstring=tempSubstring;
                     
                }
                tempSubstring=tempSubstring.substr(r+1,tempSubstring.size()-r)+s.at(i);  
                //cout<<tempSubstring<<endl;
                   
            }
        }
        if(longestSubstring.length()<tempSubstring.length()){
                     longestSubstring=tempSubstring;
        }
        
        return longestSubstring.length();
    }

    int lengthOfLongestSubstring(string s) {
        string longestSubstring="";
        unordered_map <char,int> smap;
        int n=s.length();
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){
           
            auto itr=smap.find(s.at(j));
            if(itr!= smap.end()){
                //the character is found in the map
                
                i==max(itr->second,i);

            }
                ans=max(ans,j-i+1);
                //new index of the characte
                smap[s.at(j)]=j+1;
        }
        
        return ans;
        
        
    }
	   static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        
        int medianIndex1=ceil(float(m+n)/2);
        
        cout<<medianIndex1<<endl;
       
        
        int m_i=0;
        int n_i=0;
        
        int median1=nums1[0];
        int median2=nums1[0];
        
        float answer;
        
        cout<<"init"<<median1<<endl;
        
        for (int i=0;i<medianIndex1+1;i++){
             median2=median1;
            cout<<m_i<<" "<<n_i<<endl;
            if(nums1[m_i]<nums2[n_i]){
                   
                    if(m_i<m-1){
                         median1=nums1[m_i];
                        m_i=m_i+1;
                    }
                else{
                    median1=nums2[n_i];
                    n_i=n_i+1;
                 }
                
            }
            else{
                
                if(n_i<n-1){
                    median1=nums2[n_i];
                    n_i=n_i+1;
                   
                }
                else{
                    median1=nums1[m_i];
                    m_i=m_i+1;
                   
                 }
                
                
            } 
         
        }
        
        //m+n is even
        if ((m+n)%2 ==0){
            answer=float(median1+median2)/2;
        }
        else{
            answer = median1;
        }
    
        return answer;
  
    }
        
};

int main(){
	vector<int> a={1,3,5,8};
	vector<int> b={2,2};
    Solution::findMedianSortedArrays(a,b);

}