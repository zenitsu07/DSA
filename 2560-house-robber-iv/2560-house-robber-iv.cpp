class Solution {
public:
    //recusrion
//     int f(int i, vector<int>& nums, int k, vector<vector<int> > &dp) {
//         if (k == 0)
//             return 0;
//         if (i>=nums.size()) return INT_MAX;
//         if (dp[i][k] != -1) return dp[i][k];

//         int take = max(nums[i], f(i+2, nums, k-1, dp));
//         int not_take = f(i+1, nums, k, dp);
//         return dp[i][k] = min(take, not_take);
//     }
//     int minCapability(vector<int>& nums, int k) {
//         vector<vector<int> > dp(nums.size(), vector<int>(k+1, -1));
//         return f(0, nums, k, dp);
//     }
    //Binary earch intuition 
    // we start by having max element of array and we will ave mid of that and one by one we will use fucntion isPossible which will iiterate the array to look for k elements lower than equal to mid if those =k => mid is possiblke then we will look for range left to mid -1 else we will search shorter left range i.e. mid+1
    
    bool isPossible(int mid, vector<int>&nums, int k,int n ){
         
        int i =0;
        while(i<n){
            if(nums[i]<=mid){
                k--;
                i+=2;
                
            }
            else i++;
            
            if(k==0) return true;
        }
        
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int n= nums.size(); 
        int left = 0,right = *max_element(nums.begin(), nums.end());
        
        while(left< right){
            //median
            int mid = (right + left)/2;
            
            if(isPossible(mid,nums,k,n ) )right = mid   ; 
            else left = mid+1;
            
        }
        
        return right;
        
    }
    
    
};