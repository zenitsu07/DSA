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
    
    TreeNode* build(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd , map<int,int>&mp){
        
        if(inStart>inEnd || postStart>postEnd) return NULL;
        
        //
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int numsleft = inRoot - inStart; 
        
        root->left = build(inorder, inStart, inRoot-1, postorder,postStart, postStart+numsleft-1 , mp);
        root->right = build(inorder, inRoot+1, inEnd, postorder , postStart+numsleft, postEnd-1, mp);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        int inSize = inorder.size();
        int postSize = postorder.size();
        
        for(int i =0 ; i<inSize; i++){
            mp[inorder[i]] = i; 
        }
        
        TreeNode* root  = build(inorder, 0, inSize-1, postorder, 0, postSize-1, mp);
        
        return root;
        
    }
};