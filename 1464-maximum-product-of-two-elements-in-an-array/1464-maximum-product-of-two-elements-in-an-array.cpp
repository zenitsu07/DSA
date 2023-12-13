class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for(int i =0 ; i<n;i++){
            for(int j = 0; j<n;j++){
                if(j==i) continue;
                ans = max(ans, (nums[i]-1)*(nums[j]-1) );
                
            }
        }
        
        return ans;
    }
    
};