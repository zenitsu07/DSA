class Solution {
public:
    
    
    
    void setZeroes(vector<vector<int>>& mat) {
        //map all zeroes set all possible 4 sides to 0
        //for all zeroes turn all its neighbourhood to 0
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        
        //push every 0 to queue and visit all its neighbours
        //mark flag1 flag2
        bool rowFlag =false, colFlag = false;
        for(int i =0 ; i<n;i++){
            if(mat[i][0] == 0)rowFlag = true;
        }
        for(int j =0 ; j<m;j++){
            if(mat[0][j] == 0 )colFlag = true;
        }
        
        //now set each row with entry 0 as 0 and evry col containing entry 0 as 0 leaving first row and first col
        for(int i = 1; i<n;i++){
            for(int j = 1; j<m;j++){
                if(mat[i][j] == 0){
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n;i++){
            
            for(int j = 1; j<m;j++){
                
                if(mat[i][0] == 0 || mat[0][j] == 0){
                 
                    mat[i][j] = 0;    
                    
                }
            }
        }
        
        if(rowFlag == true){
            for(int i=0; i<n; i++){
                mat[i][0] = 0;
            }
        }
        if(colFlag == true){
            for(int j=0; j<m; j++){
                mat[0][j] = 0;
            }
        }
        
    }
};