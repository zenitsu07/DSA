//taulation
    bool isSubsetSum(vector<int>&arr, int sum){
     
        // c  hoose or not choose an element
        int n = arr.size();
        
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
        for(int i = 0; i<n;i++) dp[i][0] = true;
        
        if(arr[0]<=sum) dp[0][arr[0]]  = true;
        
        for(int ind =1; ind < n; ind++){
            
            for(int tar = 1;tar <= sum; tar++){
                
                bool pick = false;
                bool notPick = dp[ind-1][tar];
            
        
                if(arr[ind] <= tar){
                    pick =  dp[ind-1][tar-arr[ind]];
                }
                dp[ind][tar]  = pick || notPick;
                
            }
        }
        
        return dp[n-1][sum];
        // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        
        
    }

    //recursion
    bool rec(vector<int>arr,vector<vector<int>>&dp,int ind,int sum){
        
        //base case when ind reaches n-1 check if sum==k if yes return true
        if(sum==0) return  true;
        if(ind==0) return arr[0] == sum;
      
      
        if(dp[ind][sum] != -1) return dp[ind][sum];
         
        bool pick = false;
        bool notPick = rec(arr,dp,ind-1,sum);
            
        
        if(arr[ind] <= sum){
            pick = rec(arr,dp,ind-1,sum- arr[ind]);
        }
        
        return dp[ind][sum] = pick || notPick;
    
    }
    //T.C. - O(n*target) target times  initialisatijn => calcuating sum for dp[ind][target] all elments
    //S.c. - O(n)* O(N*target) - dp intialisationa and stack space
    
    bool isSubsetSum(vector<int>&arr, int sum){
     
        // c  hoose or not choose an element
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        
        return rec(arr,dp,n-1,sum);
        // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        
        
    }