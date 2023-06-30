#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        int mx = INT_MAX;
        
        vector<int>graph[N];
        
        for(auto it:edges){
            //it = edges[i] vector edges[i][0].push
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            
        }
        
        vector<int>dist(N,1e9);
        
        //using the bfs a;lgo and dtorign in queue data structure becasue each edge have weight 1 and since al are in sorted order
        //the distance of later node just increase by some distnace so its easier to use bfs to measure them
        
        queue<int>q;//(node);
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();//curr = node pushed to q 
            q.pop();
            
            for(auto it: graph[node]){
            
                if(dist[it]> dist[node]+1){
                    // cout<<node<<" "<<d+1<<endl;
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
            
        }
        
        for(int i =0; i<N;i++){
            
            if(dist[i]==1e9)
                dist[i] = -1;
        }
        return dist;
    }
};