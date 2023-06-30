
class Solution {
public:

    bool isLeaf(Node* root){
        if(root->left || root->right) return false;
        return true;
    }
    
    void addLeftBoundary(Node* root,vector<int>&res){
        Node* curr = root->left;
        
        while(curr){
            //check if curr is not leaf node push it to temp vector 
            if(!isLeaf(curr)) res.push_back(curr->data);
            //choose left only if exitst else right
            if(curr->left) curr = curr->left;
            else curr = curr->right;
            
        }
        
    }
    void addRightBoundary(Node* root,vector<int>&res){
        
        Node* curr = root->right;
        
        //take a vector 
        vector<int>temp;
        while(curr){
            //check if curr is not leaf node push it to temp vector 
            if(!isLeaf(curr)) temp.push_back(curr->data);
            //choose left only if exitst else right
            if(curr->right) curr = curr->right;
            else curr = curr->left;
            
        }
        
        for(int i = temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    
    void addLeaf(Node* root,vector<int>&res){
        //inorder traversal
        //push if leaf else traverse it children
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        //call for left and right
        if(root->left)addLeaf(root->left,res);
        if(root->right)addLeaf(root->right,res);
    }

    vector <int> boundary(Node *root)
    {
       vector<int>res;
       //add leftboundary using level order for left over right
       //add leaf nodes through inordere traversal
       //add rightBoundary through irght>leaf nodes
       if(!root) return res;
       if(!isLeaf(root)) res.push_back(root->data);
       addLeftBoundary(root,res);
       addLeaf(root,res);
       addRightBoundary(root,res);
       return res;
       

    }
};