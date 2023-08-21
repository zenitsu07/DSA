/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //choose index or not choose
    void paths(TreeNode* root, int sum, vector<int>&currentPath, vector<vector<int>>&ans){
        if(!root) return ;
        
        //push current node
        currentPath.push_back(root->val);
        
        //now check if tis leaf node and its sum is required one
        if(sum == root->val && !root->left && !root->right){
            ans.push_back(currentPath);
        }
        
        //traverse adjacent nodes
        paths(root->left, sum - root->val, currentPath, ans);
        paths(root->right, sum - root->val, currentPath, ans);
        
        //at backtrack pop the current element
        currentPath.pop_back();
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>thisC;
        paths(root,targetSum,thisC,ans) ;
        //thisC is used to store the current path if it turns true then push thisC int ans vector
        
        return ans;
        
    }
    
};

// bool thisSum(TreeNode* root,int sum){
       
//         if(!root) return false;//non valid
        
//         //count current value
//         sum = sum - root->val;
//         //checks if root to leaf has sum == given sum or not
//         if(sum==0&& !root->left&& !root->right)return true;
        
//         //try both paths 
//         return thisSum(root->left,sum)|| thisSum(root->right,sum);
        
//     }
    
//     void paths(TreeNode* root, int sum, vector<vector<int>>&ans,vector<int>&thisC){
        
//         if(!root->left && !root->right){
//             thisC.push_back(root->val);
//             ans.push_back(thisC);
//             return;
//         }
//         //if reaches leaf node with required sum push that element and on backtracking push every element on path
        
//         if(thisSum(root->left,sum - root->val) == true){
//             thisC.push_back(root->val);
//             paths(root->left, sum - root->val,ans,thisC);
//             thisC.pop_back();
//         }
        
//         if(thisSum(root->right , sum- root->val) == true){
            
//             thisC.push_back(root->val);
//             paths(root->right, sum - root->val, ans, thisC);
//             thisC.pop_back();
            
//         }
        
//     }