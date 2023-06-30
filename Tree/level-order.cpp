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
    vector<int> level;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* >q;
        vector<vector<int>>ans;

        if(!root)return ans;
        TreeNode* curr = root;

        q.push(root);
        int i = 0;
        while(!q.empty()){

            int size =  q.size();

            vector<int>level;
            i = 0;

            while(i<size()){
                curr = q.front();// = 3
                q.pop();

                if(curr->left) q.push(curr->left);//push 9
                if(curr->right) q.push(curr->right);//push 20

                level.push_back(curr->val);//level = 3 ans since size = 1 breaks
                i++;
            }
            ans.push_back(level);//level = {3}, {9,20}

        }
        return ans;
    }
};