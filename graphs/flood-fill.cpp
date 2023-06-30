class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        //color = cell[i][j]
        queue<pair<int,int>>q;
        
        int clr;
        if(image[sr][sc]==color) return image;
        
        if(image[sr][sc] != color){
                    //push indices to queue and time as 0
                    q.push({sr,sc});
                    clr = image[sr][sc];
                    image[sr][sc] = color;
                 
        }
        
        //push that pxel as starting if starting not matching color pixel
        //iterate all its neighbouusr and mark them visted and give them color = color if cell !=0
         int drow[] = {-1,0,+1,0};
        int dcol[]= {0,-1,0,+1};
        //replace the pixel color only if its matching to stating pixel's color i,e, variable clr
        
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int i =0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                
                if(nrow >= 0&& nrow < n && ncol>=0 && ncol<m &&image[nrow][ncol]==clr ){
                    cout<<nrow<<" "<<ncol<<endl;
                    q.push({nrow,ncol});
                    //now visit it and replace it with color
                    image[nrow][ncol] = color;
                  
                }
            }
        }
        return image;
        }
};