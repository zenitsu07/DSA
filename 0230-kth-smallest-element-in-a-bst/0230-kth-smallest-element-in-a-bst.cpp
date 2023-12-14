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
    
    TreeNode* helper(TreeNode* root, int k, int& count){
        
        if(!root) return NULL;
        
        //go to left
        TreeNode* l = helper(root->left, k,count);
        //if exists => its the result
        if(l)return l;
        //count current node as smaller 8
        count++;
        
        if(count == k)return root;
        
        return helper(root->right, k, count);
        
    }
        
    
    int kthSmallest(TreeNode* root, int k) {
     
        //perfor inorder traversal for count
        int count = 0;
        
        TreeNode* res = helper(root,k,count);
            
        if(res) return res->val;
        else return -1;
        
    }
};