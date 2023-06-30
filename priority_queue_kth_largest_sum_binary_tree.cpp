long long kthLargestLevelSum(TreeNode* root, int k) {
       
        TreeNode* curr = root;
        long long sum =0;
        if(!root) return -1;
        long long ans = root->val;
        queue<TreeNode*>q;
        q.push(root);
        
        priority_queue<long long>pq;
        while(!q.empty()){
            
            int sz = q.size();
            vector<int>level;
            int i =0;
            sum =0;
            for(int i =0; i<sz;i++){
                 curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                level.push_back(curr->val);
                sum+=curr->val;
            }
            pq.push(sum);
        }
        
        if(pq.size()<k) return -1;
        k = k-1;
        while(k--) pq.pop();
        return pq.top();
    }