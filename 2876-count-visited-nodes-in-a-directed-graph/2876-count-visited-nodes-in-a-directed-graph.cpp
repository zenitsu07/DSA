class Solution {
public:
    // For each node which is not visited, calculate it's cycle length and fill the answer for each node that is a part of that cycle. Mark them visited, so we don't traverse on the same cycle again.
    
    void fillCycle(vector<int>&edges, vector<int>&vis, vector<int>&result,int start){
        //for this node visit all cnnected ones in cycle until found a visited node
        int nodes = 0; 
        int x = start;
        while(!vis[x]){
            
            vis[x] = true;
            nodes++;
            x = edges[x];
        }
        
        //after getting total nods connected update all connected nodes connections = result[start]
        result[start] = nodes;
        
        for(x = edges[start]; x!= start; x = edges[x]){
            result[x] = nodes;//= result[start] 
        }
        
    }
   
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        
        //keep vsiiteing directed nodes and count
        
        int n = edges.size();
        vector<int>indeg(n), res(n);
        queue<int>q;
        stack<int>s;
        
        //cal idegrees and push those with indeg 0
        for(int e:edges)
            indeg[e]++;
        
        for(int i =0 ; i<n;i++){
            if(!indeg[i])q.push(i);
        }
        
        vector<int>vis(n,0);
        //traverse the queue
        
        //push all nodes with indegree 0 after decrementing it by one
        
        while(!q.empty()){
            
            int node = q.front();
            s.push(node);//we push nodes in order of they are getting visited from start in  order to have reverse ordered nodes as storing in stack=> 
          
            q.pop();
            vis[node] = 1; 
            if(!--indeg[edges[node]])q.push(edges[node]) ;
            
        }
        
        //visit all nodes of a cycle using fillCycle fucntion
        for(int i =0; i<n;i++)
            if(!vis[i])fillCycle(edges, vis, res,i);        
        
        //now need to calc nodes not part of cycle =>
        //since all cycle ocntined nodes are now visited we visit all nodes in reverse of whivh they were cisited before i.e. 
        //  //i.e. Top node os stack => last node we visited before hitting cycle
        
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            res[temp] = res[edges[temp]]+1;
        }
        
        return res;
    }
};