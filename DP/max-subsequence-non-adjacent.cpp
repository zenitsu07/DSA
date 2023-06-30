int solve(vector<int>&nums, int i,vector<int>&dp){

    if(i==0) return nums[0];
    if(i<0) return 0;


    if(dp[i] != -1) return dp[i];
    int mxsum = 0;
    //pick and nonpick calls for ind = i
    //if not pick then inilise both with 0
    
    
    int pick = nums[i]+  solve(nums,i-2,dp);

    int notPick = solve(nums,i-1,dp);
    
    dp[i] = max(pick,notPick);
    return dp[i];

}

// int maximumNonAdjacentSum(vector<int> &nums){
    
//     int n = nums.size();
//     int ans;
//     vector<int>dp(n,-1);
    
//     ans =solve(nums,n-1,dp);

//     return ans; 

// }
//tabulation
int maximumNonAdjacentSum(vector<int> &nums) {

  int n = nums.size();
  int ans;
  vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2;i<n;i++){
        int pick = nums[i]+ dp[i-2];
        int notPick = dp[i-1];
        dp[i] = max(pick,notPick);
    }

  return dp[n-1];
}

//both bottom-up and top-down takes extra space of O(n)
//bottomup takes less stack space as recursion is avoided
//for space optimisation

int maximumNonAdjacentSum(vector<int> &nums) {

  int n = nums.size();
  int ans;  
//   vector<int> dp(n, -1);
    int prev2 = nums[0];
    int prev1 = max(nums[0],nums[1]);
   
    for(int i = 2;i<n;i++){
        int pick = nums[i]+ prev2;
        int notPick = prev1;
        int curri = max(pick,notPick);
        
        prev2 = prev1;
        prev1 = curri;

    }

  return prev1;
}