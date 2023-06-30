int sum = 0;
        int n = V;
        vector<int>vis(n,0);
        vector<vector<pair<int,int>>>graph(n);
        
    
        for(int i= 0; i<n;i++){
            
            int u = adj[i][0];
            int v = adj[i][1];
            int w = adj[i][2];
            graph[u].push({v,w});
            graph[v].push({u,w});
            
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        //store as (wt,{node,parent}) => pair<int,pair<int,int>>
        
        vector<pair<int,int>>mst;//form = (u,v) store edges here to calculate their weights 
        
        //push edge 0, -1 in queue with weught 0 initially
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            int node = pq.top().second.first;
            int wt = pq.top().first;
            int parent = pq.top().second.second;
            pq.pop();
            //now if parent =1 => its first node
            if(parent=-1) continue;
            
            //else check for vis[node] if not vis then pus in mst
            
            if(!vis[node]){
                mst.push_back({node,parent});
                vis[node] = 1;
                sum += wt;
                
            }
            
            for(auto it: graph[node]){
                
                int curr_wt = it.second;
                int adjNode = it.first;
                
                  pq.push({curr_wt,{adjNode,node}});
                
            }
        }
        return sum;
        