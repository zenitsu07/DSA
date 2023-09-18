class Solution {
public:
//     int[] memo;
// public int rob(int[] nums) {
//     memo = new int[nums.length + 1];
//     Arrays.fill(memo, -1);
//     return rob(nums, nums.length - 1);
// }

// private int rob(int[] nums, int i) {
//     if (i < 0) {
//         return 0;
//     }
//     if (memo[i] >= 0){
//         return memo[i];
//     }
//     int result = Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
//     memo[i] = result;
//     return result;
    
// int rob(int[] nums) {
//     if (nums.length == 0) return 0;
//     int prev1 = 0;
//     int prev2 = 0;
//     for (int num : nums) {
//         int tmp = prev1;
//         prev1 = max(prev2 + num, prev1);
//         prev2 = tmp;
//     }
//     return prev1;
//     }
    
// };
//     int t[101];
//     int solve(vector<int>&nums, int i){
//         //Base condition
//         if(i<0) return 0;
        
//         if(t[i] >= 0) return t[i];
        
//         //Choice 
        
//         int result = max( solve(nums,i-2)+nums[i], solve(nums,i-1));
//         return t[i] = result;
//     }
    
//     int rob(vector<int>& nums) {
        
//         int n = nums.size();
        
//         memset(t,-1,n+1);
//         return solve(nums,n-1);
        
//     }
    
//striver solution
    int rob(vector<int>& nums){

        int n = nums.size();
        //there are only one param index which can be i-1 and i
        vector<int>dp(n);
        dp[0] = nums[0];//initialise i.e. rob0bing 0th house loot = nums[0]
        
        if(n==1)return nums[0];
        
        dp[1] = max(nums[1],nums[0]);//or 1st house we have option as rob first and max rob 0th
        
        for(int i = 2;i<n;i++){
            
            int pick = nums[i] + dp[i-2];
            //if not robbing current house then loot = loot till previous i-1th house e.g. not robbing 2nd house => loot = dp[1]//until 1 st house 
            int notPick = dp[i-1]; 
            
            dp[i] = max(pick, notPick);
            
        }
        
        return dp[n-1];
        
    }
};
    