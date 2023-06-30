class Solution {
  public:
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,pair<int, int> dest) {
          
        //calulcate shortest dist from 0,0
        int n = grid.size();
        int m = grid[0].size();  
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        //check if source ceels and dest cells are 1
        if(grid[src.first][src.second] == 0|| grid[dest.first][dest.second] == 0) return -1;
        
        //store pair as {dist[i][j], grid[i][j]}
        
        priority_queue< pair<int,pair<int,int > >,vector < pair<int,pair<int,int >> >, greater< pair<int,pair<int,int > >>> q; //min heap
        
        //push source and then traverse all its adj and push those after updating their dist from source
        dist[src.first][src.second] = 0;
        
        q.push( { dist[src.first][src.second] , {src.first, src.second} } );
        
        
                                            
        while(!q.empty()){
            
            int dis = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            
            q.pop();
            
            //check 4 neighbours
            int drow[] = {0,-1,0,1};
            int dcol[] = {1,0,-1,0};
            
            for(int i =0; i<4;i++){
                
                //visit all adjacent while checking validity
                    
                int nrow = r + drow[i];      
                int ncol = c+ dcol[i];
                  
                if(nrow >=0 && nrow <n && ncol>=0 && ncol< m && grid[ nrow ][ ncol ] == 1 ){
                    
                    //visit them and update dist
                    if(dis+1 < dist[ nrow ][ ncol ]){
                         
                        dist[nrow][ncol] = dis+1;
                        q.push({ dist[nrow][ ncol ], { nrow , ncol }});
                        
                    }
                    
                }
                
            }
            
        }
        

        if(dist[dest.first][dest.second] == 1e9) return -1;
        
        return dist[dest.first][dest.second ];
    }
};