class Solution {
public:
    
    
    
    int maxSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        
        for(int i =0; i<n;i++)ans &= nums[i];
         if( ans != 0 ) return 1;
        
        int res = INT_MAX;
        int sub  = 0;
        for(int i = 0; i<n;i++){
            
            
            res &= nums[i];
            if(res == 0){
                sub++;
                //reset res so as to get and score of next subarray
                res = INT_MAX;
            }
            
        }
        
        
        return sub;
        
    }
};