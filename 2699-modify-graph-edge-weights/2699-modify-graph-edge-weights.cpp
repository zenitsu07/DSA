class Solution {
 public:
//     long large = 1e9;
//     long INF = 1e16;
    
//     vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        
//         vector<vector<pair<int,int>>>graph(n);
//         //contains only postivie weight edges
//         for(auto it: edges){
            
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
//             if(wt==-1)continue;
//             graph[u].push_back({v,wt});
//             graph[v].push_back({u,wt});
            
//         }
        
//         //for this graph for every edge first assign postitive weight for negative edges then iterate and cLCULATE THEdifference of target required
//         queue<int>q;
//         q.push(src);
//         vector<long>dist(n,INF);
//         //push src and find hsortes path
//         dist[src] = 0; 
        
//         while(!q.empty()){
            
//             int node = q.front();
//             q.pop();
//             for(auto edge : graph[node]){
                
//                 int adj = edge.first;
//                 int wt  = edge.second;  
                
//                 if(dist[adj] > dist[node] + wt ){
//                     dist[adj] = dist[node] +wt; 
//                     q.push(adj);
//                 }
                
                
//             }
            
//         }
//         if(dist[dest]<target) {
//             return vector<vector<int>>();
//         }
//         //dest has shortest dist from any node to dest 
//         if(dist[dest] == target) {
//             //achieved it => fil with arge and return edges as necgatives dint matter
//             for(auto edge: edges){
//                 if(edge[2] == -1)edge[2] = large;
//             }
            
//             return edges;
//         }
        
//         //go for adding negative edges one by one
//         for(int i = 0; i<edges.size();i++){

//             int u = edges[i][0];
//             int v = edges[i][1];
//             int wt = edges[i][2];

//             if(wt == -1){

//                 edges[i][2] = 1;
//                 //add and run dijstra including thsi edge

//                 graph[u].push_back({v,1});
//                 graph[v].push_back({u,1});

//                 //after including run dijstra
//                 queue<int>q2;
//                 q2.push(src);
//                 vector<long>dist2(n,INF);
//                 //push src and find hsortes path
//                 dist2[src] = 0;
//                 while(!q2.empty()){

//                     int node = q2.front();
//                     q2.pop();

//                     for(auto edge : graph[node]){

//                         int nxt = edge.first;
//                         int adjW  = edge.second;  

//                         if(dist2[nxt] > dist2[node] + adjW ){
//                             dist2[nxt] = dist2[node] + adjW; 
//                             q2.push(nxt);
//                         }


//                     }

//                 }
//                 //check dist dest and apprach
//                 if(dist2[dest] <= target){

//                     //update current edge with difference remaining to reach target
//                     //update alll other negative eges with lrge and return else do again
//                     int diff = target - dist2[dest];
//                     edges[i][2] += diff;

//                     //now update others with large and return
//                     for(int j = i+1; j<edges.size();j++){
//                         if(edges[j][2] == -1 )edges[j][2] = large;
//                     }
//                     return edges;

//                 }
        

//             }//if ends

            
            
//         }
        
//         return vector<vector<int>>();
        
//     }
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        vector<vector<pair<int,int>>> adj(n);

        //excluding edges with weight = -1
        for(auto e: edges){
            if(e[2]!=-1){
                adj[e[0]].push_back({e[1],e[2]});
                adj[e[1]].push_back({e[0],e[2]});
            }
        }

        //Dijkstra for shortest path
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,source});
        vector<int> dis(n,1e9);
        dis[source]=0;
        while(!q.empty()){
            int curr_dis=q.top().first;
            int u=q.top().second;
            q.pop();
            if(u==destination){
                break;
            }
            for(auto nbr : adj[u]){
                int v=nbr.first;
                int wt=nbr.second;
                if(curr_dis+wt<dis[v]){
                    dis[v]=curr_dis+wt;
                    q.push({dis[v],v});
                }
            }
        }

        //if shortest path < target , then return empty array
        if(dis[destination]<target){
            return {};
        }

        //if shortest path is equal to target
        if(dis[destination]==target){
            for(auto &e : edges){
                if(e[2]==-1){
                    e[2]=1e9;
                }
            }
            return edges;
        }


        // Now changing weight of each edge with weight -1 to 1 one by one and trying to get shortest path
        for(int i=0 ; i<edges.size() ; i++){
            auto &e=edges[i];
            if(e[2]==-1){

                //change weight to 1
                e[2]=1;
                adj[e[1]].push_back({e[0],1});
                adj[e[0]].push_back({e[1],1});
                while(!q.empty()){
                    q.pop();
                }

                //Dijkstra 
                q.push({0,source});
                vector<int> dis(n,1e9);
                dis[source]=0;
                while(!q.empty()){
                    int curr_dis=q.top().first;
                    int u=q.top().second;
                    q.pop();
                    if(u==destination){
                        break;
                    }
                    for(auto nbr : adj[u]){
                        int v=nbr.first;
                        int wt=nbr.second;
                        if(curr_dis+wt<dis[v]){
                            dis[v]=curr_dis+wt;
                            q.push({dis[v],v});
                        }
                    }
                }

                //adding appropriate weight to get target
                if(dis[destination]<=target){
                    e[2]+=target-dis[destination];

                    //rest edges with weight=-1 set to 1e9
                    for(int j=i+1 ; j<edges.size() ; j++){
                        if(edges[j][2]==-1){
                            edges[j][2]=1e9;
                        }
                    }
                    return edges;
                }
            }
        }

        return {};
    }
    
};