class Solution {
public:
    int trap(vector<int>&h ) {
     
        
        int i = 0, j= h.size() - 1;
        int lmax = 0, rmax = 0, res = 0;
        
        while(i<=j){
            if(h[i] <= h[j]){
                if(h[i]>=lmax){
                    lmax = h[i];
                }
                else{
                    res+= lmax - h[i];
                }
                i++;
            }
            else{
                
                if(h[j]>=rmax){
                    
                    rmax = h[j];
                    
                }else
                    res += rmax - h[j];
                j--;
            }
        }
        
        return res;
    }
};