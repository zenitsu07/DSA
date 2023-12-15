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
    
    TreeNode* build(vector<int>&preorder, int preStart, int preEnd, vector<int>&postorder, int postStart, int postEnd , map<int,int>&mp){
        
        if(preStart>preEnd || postStart>postEnd) return NULL;
        
        //
        TreeNode* root = new TreeNode(preorder[preStart]);
        //get next subtree's num of elms
        
        //for next subtree we get pos of preStart+1th element in postorder mapping
        if(preStart+1<=preEnd){
            int postLeft = mp[preorder[preStart+1]] ;//mapped mp[preorder[1]]  = 2->2
            int numsLeft = postLeft -  postStart;// = 3

            root->left = build(preorder,preStart+1, preStart+numsLeft+1,  postorder, postStart, postStart+numsLeft, mp);
            root->right = build(preorder,preStart+numsLeft+1+1, preEnd, postorder ,postStart+numsLeft+1, postEnd-1 , mp);
        
        }
        return root;
        
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        int preSize = preorder.size();
        int postSize = postorder.size();
        
        for(int i =0 ; i<postSize; i++){
            mp[postorder[i]] = i; 
        }
        
        TreeNode* root  = build(preorder, 0, preSize-1, postorder, 0, postSize-1, mp);
        
        return root;
        
    }

};
