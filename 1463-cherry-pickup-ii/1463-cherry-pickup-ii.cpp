class Solution {
public:
    
//     int rec(vector<vector<int>>&grid, int row,int c1, int c2){
        
//         if( c1 >= grid[0].size() ||c2 >= grid[0].size() || c1 < 0 || c2<0 ) return 0;
        
//         if(row == grid.size()) return 0;//last row
        
        
//         //count current move
//         int ans = 0;
//         ans += grid[row][c1] + grid[row][c2];
        
//         ///down, left
//         //j-1, j, j +1
        
//         int rowMax = 0; //for next row movwmwnr try all possible situations and take max from recursive calls
         
//          for(int x = c1-1; x <= c1+1; x++){
            
//             for(int y = c2-1; y <= c2+1; y++){
                
//                 if(c1<c2)
//                 rowMax = max(rowMax, rec(grid, row+1, x,y)); 
                
//             }
            
//         }
        
//         ans += rowMax; 
        
//         return ans;
        
//     }
    
    
//     int cherryPickup(vector<vector<int>>& grid) {
        
//         //take max cheerries possible
//         //movements possible => down, down right, down left
//         //if in same cell only 1 take =>  dont let them in same cell
//         //end at bootom row + always downward movement
        
//         int n = grid.size();
//         int m = grid[0].size(); 
        
//         //three params changing //
        
//         return rec(grid, 0, 0,m-1 );
        
        
//     }
    
     int cherryPickup(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

         //3 parmaas for each chagine row c1,c2 change

        vector<vector<vector<int>>> dp(rows+1, vector<vector<int>>(cols+1, vector<int>(cols+1,-1)));

        return helper(grid, 0, 0, cols-1, dp);
         
    }
    
     int helper(vector<vector<int>>& grid, int currRow, int robotACol, int robotBCol,  vector<vector<vector<int>>>&dp) {
        
        if(robotACol < 0 || robotBCol < 0 || robotACol >= grid[0].size()|| robotBCol >= grid[0].size()) return 0;
        
        if(currRow == grid.size()) return 0; // last row
         
        if(dp[currRow][robotACol][robotBCol] != -1)return dp[currRow][robotACol][robotBCol];
        
        int result = 0;
        result += grid[currRow][robotACol];
        result += grid[currRow][robotBCol];
        
        int rmax = 0; // DFS for next row
         
        for(int x=robotACol-1;x<=robotACol+1;x++) {
            for(int y=robotBCol-1;y<=robotBCol+1;y++) {
                if(x < y) {
                    rmax = max(rmax, helper(grid, currRow+1, x, y,dp));
                }
            }
        }
        
        result += rmax; // add maximum result
        return dp[currRow][robotACol][robotBCol]= result;
    }
};