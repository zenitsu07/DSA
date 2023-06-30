class Solution {
  public:
    void topoSort(int node, vector<pair<int,int>>graph[], int vis[], stack<int> &st){
        //visit each src adjacent node and 
        
        vis[node] = 1; 
        
        for(auto it: graph[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v,graph,vis,st);
            }
        }
        st.push(node);
        
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //edges = {src,dest,weight}
        vector< pair< int, int>>graph[N];
        
        //noo of edges = M
        for(int i = 0; i<M;i++){
            //it = edges[i] vector edges[i][0].push
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v,wt});
         //store adjacent node at 0th index with pair as {adj,wieght of edge
            
        }
        //find topo sort
        
        int vis[N] = {0};
        stack<int>st;
        for(int i=0; i<N;i++){
            if(!vis[i]){
                topoSort(i,graph,vis,st);
            }
        }
        
        //after toposort now nodes will be topo sorted order and now in stak at top will be source node 
        //now to find shortest path 
        
        //INTUITUION = MOVE ACCORDING TO REACHABILITY SO THAT WE KNOW WHEN WE ARE THAT ITH NODE ALL ITS PREVIOUS NODE HAVE BEEN REACHED OUT
        //and thus sorted the time omplecity to lesser  as = O(N+M) afterqward now
        //BETTER THAN DIJSTRA ALGO
        //now calculate distance
        
        
        vector<int>dist(N);
        for(int i=0; i<N;i++) dist[i] = 1e9;
        dist[0] = 0;//if source !=0 => dist[src] = 0
        //now while removing stack elements update values of dist fromsource node to find shortest path
        
        while(!st.empty()){
            
            int node = st.top();
            
            st.pop();
        
            for(auto it:graph[node]){
                
                int adj= it.first;//adj = linkled node
                int wt = it.second;
                //compare distances with nodes and select shortest 
                
                if(dist[node]+wt< dist[adj])
                    dist[adj] = dist[node]+ wt;//dist[adj] = dist of adj node from 0, dist[ node]  = dist of current node from 0 and wt = weight of edge
                
            }
            
        }
        
        for(int i =0; i<N;i++){
            
            if(dist[i]==1e9)
                dist[i] = -1;
        }
        return dist;
    }
};