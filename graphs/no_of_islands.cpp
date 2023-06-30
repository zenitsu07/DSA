#include<bits/stdc++.h>
using namespace std;
class Solution{
void bfs(int i,int j, vector<vector<char>>grid,vector<vector<int>>&vis){
        
        vis[i][j]=1;
        queue<pair<int,int>>q;//store as (i,j)
        
        //push source grid to queue first
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
                            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int drow = -1;drow <= 1;drow++){
                
                for(int dcol = -1;dcol <=1;dcol++){
                     
                    int nrow = r+drow;
                    int ncol = c+ dcol;
                    
                    if( (nrow >= 0 && nrow < n) && (ncol>=0 && ncol< m) &&  grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                        
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
                
            }
        }
        
    }
    
  public:
    // Function to find the number of islands.
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector <int> (m,0));
        
        int cnt=0;
        
        for(int i =0; i<n;i++){
            for(int j=0 ; j<m;j++){
                
                if(grid[i][j]=='1' && vis[i][j]==0 ){
                    
                    cnt++;
                    bfs(i,j,grid,vis);
                    
                }
            }
        }
        
        
        return cnt;
    }
};