#include<bits/stdc++.h>
using namespace std;
   
//   Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        vector<int> ans;
        
		// 1. Make root as the starting node, that is currNode
        TreeNode* currNode = root;

        while (currNode or !st.empty()) {
		// 2. Now add all the left subtree nodes to the stack
            //all left subtree will be added 
            while (currNode) {
                st.push(currNode);
                currNode = currNode->left;
            }   
        // 3. Pick out the top node, put it in answer array
            //once node is stored it gets popped out and its parent node is now at top and move to right
            currNode = st.top();
            st.pop();
            
            ans.push_back(currNode->val);
		// 4. Update currNode as below, this will take care of the right subtree
            currNode = currNode->right;
        }
        return ans;
    }
};
//using two stacks
vector<int> postorderTraverse(TreeNode* root){

    stack <TreeNode*>st1,st2;
    vector<int>postorder;

    if(root==null) return postorder;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* curr = st1.top();
        //now pop the top of s1 and push it to s2
        st1.pop();
        st2.push(curr);
        if(curr->left) {
            st1.push(curr->left);
        }
        if(curr->right){
            st2.push(curr->right);
        }
    
    }
    while(!st2.empty()){
        postorder.push_back(st2.top());
        st2.pop();
    }
    return postorder;

}