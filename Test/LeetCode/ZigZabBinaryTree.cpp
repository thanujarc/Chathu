#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        
        vector<vector<int>> output;
        if(root==nullptr){
           return output;  
        }
        queue<TreeNode*> nodes1;
        queue<TreeNode*> nodes2;
        nodes1.push(root);
        vector<int> temp;
        bool reverseVec=false;
        while(!nodes1.empty()){
            //printQueue(nodes);
            TreeNode* node=nodes1.front();
            nodes1.pop();
           
            if(node!=nullptr){
                temp.push_back(node->val); 
                if(node->left)
                    nodes2.push(node->left);
                if(node->right)
                    nodes2.push(node->right)  ;
                
                if(nodes1.empty()){
                    if(reverseVec){
                        reverse(temp.begin(),temp.end());       
                    } 
                    reverseVec=!reverseVec;
                    output.push_back(temp);
                    temp.clear();
                    nodes1=move(nodes2);//move 
                }
            }                             
        }

        return output;
        
    }
};
int main(){
    cout<<"no input";
}
