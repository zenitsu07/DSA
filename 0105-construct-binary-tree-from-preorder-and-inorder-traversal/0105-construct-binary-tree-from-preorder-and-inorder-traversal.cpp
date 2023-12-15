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
    
    TreeNode* build(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd,map<int,int>&mp ){
        
   
        if(preStart>preEnd ||  inStart>inEnd )return NULL;
        
        //find root index in inorder
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        
        //now cal nums
        int numsLeft = inRoot- inStart;
        
        //assign left and right child to root
        root->left = build(preorder, preStart+1, preStart+numsLeft, inorder , inStart, inRoot-1 ,mp);
        root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        
        return root;    
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>mp;
        
        //form inorder hash map
        int inSize = inorder.size();
        int preSize = preorder.size();
        
        for(int i = 0 ; i < inSize; i++){
            
            mp[inorder[i] ] = i;
            
        }
        
        //call recusrve function
        TreeNode* root = build(preorder,0, preSize-1,inorder, 0, inSize-1,mp);
        return root;
        
    }
    
};