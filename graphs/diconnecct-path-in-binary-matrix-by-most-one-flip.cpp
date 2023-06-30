bool dfs(vector<vector<int> >& grid,int i, int j, int n, int m)
    {
        if(i==n-1&&j==m-1)
            return true;
    
        //as we traverse make all grid cells  = 0 so as we cant traverse the same path again and again
        
        grid[i][j]=0;
        
        int dc[2] = {0,1};
        int dr[2] = {1,0};
        
        for(int k=0;k<2;k++)
        {
            int newX = i + dr[k];
            int newY = j + dc[k];
            
            //check validation o of newX and newY and if grid value = 1 for it then call dfs and if it return treu  = > there exists a path
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
            {
                if (dfs(grid, newX, newY, n, m))
                {
                    return true;
                }
                    
            }
        }
        return false;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //1st dfs call for checcing if there is atleast one path or not
        
        if(dfs(grid,0,0,n,m)==false)
        {
            return true;
        }
    
        //if there is atleast one path ,then our dfs call would have made each cell on the path  = 0 so the path catn be traverse again 
        //now 2nd dfs call will return true only if there exists another independent path
        if(dfs(grid,0,0,n,m)==false)
        {
            return true;
        }
        return false;
        
    } 