class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>> >g(n);
        //store as at uth index  = (node connected, time)
        
        //undirected geraph push both ways
        for(auto it: roads){
            
            g[it[0]].push_back({ it[1],it[2] });
            g[it[1]].push_back({it[0],it[2]});
            //g[0][6] = 7
            
        }
        
        //now keep a time array recording shortest time from 0th
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        //{store as = {time, (node)}
        vector<int>time(n,1e9);
        //update time to reach node as you reach it
        vector<int>ways(n,0);
        //count ways to reach each node then the answer  = ways[n-1]
        ways[0] = 1;
        time[0] = 0;
        pq.push({0,0});
        //reach all adjacency of nods un queue
        //update time by modulo 109 + 7
        
        int mod = (int)(1e9 + 7);    
        
        while(!pq.empty()){
            
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //for each adjNode of node update ways[adjNode.first] = ways[node]
            for(auto adjNode:g[node]){
                
                int temp = adjNode.first;
                int curr_t = adjNode.second;
                
                
                //update shortest time to reach and once reached n-1 intersecttion store its shortest time and later on compare to count ways
                
                //check if time[temp] != 1e9 if true => increase no of ways to ways[node]+ 1
                
                
                if( time[adjNode.first] > t+ curr_t){
                        
                    time[adjNode.first] = t+ curr_t;
                    pq.push({ t+ curr_t, adjNode.first});
                    
                    ways[adjNode.first] = ways[node];
                    // cout<<ways[adjNode.first]<<" ";
                        
                }
                else if(time[adjNode.first] == t+curr_t){
                    ways[adjNode.first] = (ways[adjNode.first] + ways[node])%mod;
                }
                
                //once encountered break out of loop and run different loop for queue elements to count way     
            }  
        }
        
        return ways[n-1]%mod;
    }
};