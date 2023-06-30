int solve(vector<int>&h, int i,int k,vector<int>&dp){
        if(i==0) return 0; 
        
        int minSteps = INT_MAX;
        int steps = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j = 1; j <= k; j++){
            
            if(i>=j)
                steps = solve(h,i-j,k,dp) + abs(h[i] - h[i-j]);
            minSteps = min(steps,minSteps);
            
        }
        dp[i] = minSteps;
        return  dp[i];
    }
    
    //bottom up
    // int solveUp(vector<int>&h,int n, int i,int k,vector<int>&dp){
     
        
    //     if(i==n) return dp[n-1];
        
    //     int minSteps = INT_MAX;
    //     int steps = INT_MAX;
        
    //     if(dp[i]!=-1) return dp[i];
        
    //     for(int j = 1;j<=k;j++){
            
    //         //i+j max = k 
    //         if(i+j<n){
    //             steps= solveUp(h,n,i+j,k,dp) + abs(h[i]-h[i+j]);
    //         }
    //         minSteps= min(steps,minSteps);
            
    //     }
    //     dp[i] = minSteps;
    //     return dp[i];
        
    // }

    // int minimizeCost(vector<int>& h, int n, int k) {
        
    //     vector<int>dp(n,-1);
    //     // int ans = solve(h,n-1,k,dp);
    //     int ans  = solveUp(h,n,0,k,dp);
    //     return ans;
        
    // }
    int minimizeCost(vector<int>& h, int n, int k) {
        
        vector<int>dp(n,-1);
        dp[0] = 0;
        for(int i =1;i<n;i++){
            
            int steps = INT_MAX;
            int minSteps = INT_MAX;
            
            for(int j= 1;j<=k;j++){
                if(i>=j) steps = dp[i-j]+ abs(h[i] - h[i-j]);
                 minSteps= min(steps,minSteps);//cound minsteps for each iteration or jump dfrom every ith index
            }
           
            dp[i] = minSteps;
        }
        return dp[n-1];
        
    }
    
    //SC = O(n) dp array space
    //can be optimised to O(k) at max