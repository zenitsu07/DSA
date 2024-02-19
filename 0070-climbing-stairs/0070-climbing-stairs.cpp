class Solution {
public:
        int rec( int n, int res, vector<int>&dp){

        if(n<=2)
           return n;
        
        if(dp[n]!=-1)return dp[n];
        int first;
        if(n>1) first = rec(n-1, res+1,dp);
        
        int second;
        if(n>2) second = rec(n-2, res+1,dp);
         res = first+ second;
    dp[n] = res;
            return dp[n];
        
    }
    
    int climbStairs(int n) {
        int res = 0;
        
        vector<int>dp(n+1,-1);
        return rec(n,res,dp);
    }
};