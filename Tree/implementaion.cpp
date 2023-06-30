#include<bits/stdc++.h>
using namespace std;
//using stack
struct TreeNode
{
    char data;
    Node* left;
    Node* right;
};
//In C language use (struct Node* root)
void Preorder(Node *root){

    if(root==NULL) return;

    cout<<root->data<<" ";
    
    Preorder(root->left);
    Preorder(root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    stack<TreeNode*> stack;
    if (root == NULL)
        return preorder;
    stack.push(root);
    while(!stack.empty()) {
        TreeNode* curr = stack.top();
        stack.pop();
        preorder.push_back(curr->data);
        if (curr->right != NULL)
            stack.push(curr->right);
        if (curr->left != NULL)
            stack.push(curr->left);
    }
    return preorder;
}
int main(){
    Node *root;
    root->data = 'F';


    Preorder(root);
}