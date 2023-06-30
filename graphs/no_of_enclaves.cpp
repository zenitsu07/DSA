class Solution {
  public:
    bool isBorder(int i,int j, int n, int m){
        if(i==0 ||i==n-1 || j==0 || j==m-1) return true;
        return false;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
         int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>move(n,vector<int>(m,0));//this move vector ensures that which cells are moveable with 1 adn 0 as non moveable
            
        //take vis array and mark all 1s visited if they are conncted to any of the border 1s
        //push all border 1s to queue and bfs them to all 1s and visit them
        //lastly count all 1s that are not visited
        
        queue<pair<int,int>>q;
        
        for(int i =0 ; i< n;i++){
            
            for(int j =0; j < m;j++){
                
                if(isBorder(i,j,n,m) && grid[i][j] == 1){
                    // cout<<i<<" "<<j<<endl;
                    q.push({i,j});
                    vis[i][j] = 1;
                    move[i][j] = 1;
                }
                
            }
        }
        
        //dfs all 1s in queue 
        int drow[] = {-1,0,+1,0};
        int dcol[]= {0,-1,0,+1};
            
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            //call dfs
            // cout<<r<<" "<<c<<endl;
            //mark each of queue's members neighbours as visited and moveable land cells
            
            for(int i =0;i<4;i++){
                
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                
                if(nrow >= 0&& nrow < n && ncol>=0 && ncol<m &&grid[nrow][ncol]==1 && vis[nrow][ncol]==0 ){
                    
                    // cout<<nrow<<" "<<ncol<<endl;
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    move[nrow][ncol] = 1;
                  
                }
            }
        
        }
        
        int count = 0;
        //count all the 1s which have move values = 0 as they are isolated from borders
        
        for(int i =0 ; i< n;i++){
            for(int j =0; j<m;j++){
                
                if( grid[i][j] == 1 && move[i][j] == 0){
                    // cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};