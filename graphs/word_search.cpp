class Solution {
public:
    bool dfs(vector<vector<char>> &board,vector<vector<int>>&vis,int i, int j, string word, int idx){
        
        if(idx == word.size() ) return true;
        if(i<0 || i>=board.size() ||j<0 ||j>=board[0].size() ||board[i][j]!=word[idx] )return false;
        
        
        //else visit and find in neighbouring
        
        //changge current char before procedding with dfs calls to avoid taking same cell for repeated char in word
        //so prev vis chas are not checked  
        board[i][j] = '*';
        bool status =  dfs(board,vis,i+1,j,word,idx+1)|| dfs(board,vis,i-1,j,word,idx+1) 
                        || dfs(board,vis,i,j+1,word,idx+1) ||dfs(board,vis,i,j-1,word,idx+1);
        
        //now change it back to prev char; so that in backtrack calls its cell is takien in account
        board[i][j] = word[idx];
        return status;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //find next letters in grid.neighbours and visit once once met match
        if(word =="" )return false;
        //dfs algo or bfs
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){

                   if( board[i][j] == word[0] && dfs(board,vis,i,j,word,0) == true) return true;
                
            }
        }
       return false;
        
    }
};