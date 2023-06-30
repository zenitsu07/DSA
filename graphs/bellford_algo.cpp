class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        //iterate v-1 times and relax the edges for n-1 iterations for updated cycle of dist which gives shortest path from src to each node at the end of n-1 th iterations done o edges
        dist[S]  = 0;
        //T = V*E
        //S = V
        
        for(int i=0; i<V-1; i++){
            
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                //put if  dist[u]!= 1e9 to check if ede is reacheable now
                if( dist[u]!= 1e8 && dist[u]+ wt < dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
            
        }
        //As we should have got our shortes distances of nodes form src at n-1th iteration so 
        //do a nth iteration and if any dist[node] gets reduced => tehere ia s negative cycle present which keeps on reducing weights of edges
        for(auto it:edges){ 
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if( dist[u]!= 1e8&& dist[u]+ wt < dist[v]){
               return {-1};
            }
        }
        return dist;
    }
};