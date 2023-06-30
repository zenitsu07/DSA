#include <bits/stdc++.h> 

int rec(vector<int>&weight,vector<int>&profit,int w, int ind,vector<vector<int>>&dp){
    
    if(ind == 0){
        // if(weight[0]<=w) return weight[0];//when only 1 denomination
        //for unlimited
         return profit[0]*(w/weight[0]);
    }

    if(dp[ind][w] !=-1 ) return dp[ind][w];
        int notPick = rec(weight,profit,w,ind-1,dp);

        int pick = INT_MIN;
        if(weight[ind] <= w) pick = profit[ind] + rec(weight,profit,w-weight[ind],ind,dp);
    
        int ans = max(pick,notPick);
        return dp[ind][w] =ans;
}

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     // Write Your Code Here.
//     //its classic knapsack but with unlimited denominations -> similiar to min coins problem 
//     //here find max profit we can make with these numbers but with a limit
//     if(w == 0) return 0;
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     return rec(weight,profit,w,n-1,dp);


// }
//tabulation
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     vector<vector<int>>dp(n,vector<int>(w+1,0));

//     for(int T = 0;T<=w;T++){
//         dp[0][T] = profit[0]*(T/weight[0]);
//     }

//     for(int ind  = 1;ind <n;ind++){
//         for(int T = 0; T<=w;T++){
            
//             int notPick = dp[ind-1][T];

//             int pick = INT_MIN;
//             if(weight[ind] <= T) pick = profit[ind] + dp[ind][T-weight[ind]];
     
//             dp[ind][T] = max(pick,notPick);
//         }
//     }
//     return dp[n-1][w];

// }
//space optimised
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int>prev(w+1,0);

    for(int T = 0;T<=w;T++){
        prev[T] = profit[0]*(T/weight[0]);
    }

    for(int ind  = 1;ind <n;ind++){
        vector<int>curr(w+1,0);
        for(int T = 0; T<=w;T++){
            
            int notPick = prev[T];

            int pick = INT_MIN;
            if(weight[ind] <= T) pick = profit[ind] + curr[T-weight[ind]];
     
            curr[T] = max(pick,notPick);
        }
        prev = curr;
    }
    return prev[w];

}
