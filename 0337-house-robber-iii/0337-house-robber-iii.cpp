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
    
    int sum(TreeNode* root,  int &notRobMax){
        
        if(!root) return 0; 
        // go to root's children and find max of including root and non including root val  
        
        int leftNotRobMax = 0 ,rightNotRobMax = 0;
        int leftMax = sum(root->left, leftNotRobMax);// = 3
        int rightMax  = sum(root->right, rightNotRobMax);// = 3
        
        //now above calucted subtrees max we put in not robbing current i.e.
        notRobMax = leftMax + rightMax;// 3+3 = 6
        int robMax = root->val + leftNotRobMax+ rightNotRobMax; // 3 + 3 +1 = 7
        
        return max(robMax, notRobMax);
        
    }
    
    int rob(TreeNode* root) {
        //from root either rob root then root->left->left or root->left 
        
        //traverse inroder from root to leaf
        int r;
        return sum(root, r);
        
    }
};