int mod = 1000000007;
    int rec(int arr[], int ind, int target, vector<vector<int>>&dp){
        
        if (ind == 0) {
            if(target == 0 && arr[0] == 0) return 2;
            else if(target == 0 || target == arr[0]) return 1;
            else return 0;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        //if not pick then store in dp[ind][target] calling for ind-1 index + 
        int notPick = rec(arr,ind-1,target,dp);//stores 
        int pick = 0;
        
        if(target >= arr[ind]) pick= rec(arr,ind-1,target-arr[ind],dp);
        
        return dp[ind][target] = (pick+notPick)%mod;
        
    }   
    
	int perfectSum(int arr[], int n, int target){
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return rec(arr,n-1,target,dp)%mod;
        
	}
	// tabulation


vector<vector<int>>dp(n,vector<int>(target+1,0));
            //when ind == 0 => if last element = arr[0] <
            //for target 0 if = arr[0]
            //if tar = 0
            for(int i =0; i<n;i++) dp[i][0] = 1;
            if(arr[0]<=target) dp[0][arr[0]] = 1;
            if(target == 0 && arr[0] == 0) dp[0][0] = 2;
          
            
            //for variables -> 1st = indices in recursion from n-1 to -=> tabulation 1 to n-1
            //2nd sum from target to 0 => 1 to target
            for(int  i= 1; i<n;i++){
                for(int t =0; t<=target;t++){
                    
                    int notPick = dp[i-1][t];
                    int pick = 0;
                    if(t>=arr[i]) pick = dp[i-1][t-arr[i]];
                    
                    dp[i][t] = (pick+ notPick)%mod;
                }
            }
            
            return dp[n-1][target];

//space optimisation
    int perfectSum(int arr[], int n, int target){
            
            vector<vector<int>>dp(n,vector<int>(target+1,0));
            vector<int>prev(target+1,0),curr(target+1,0);
            
            prev[0] = curr[0] = 1;
            if(arr[0]<=target) prev[arr[0]] = 1;
            //imp step
            if(arr[0] == 0) prev[0] = 2;//picking element or empty set
          
            
            //for variables -> 1st = indices in recursion from n-1 to -=> tabulation 1 to n-1
            //2nd sum from target to 0 => 1 to target
            for(int  i= 1; i<n;i++){
                
                for(int t =0; t<=target;t++){
                    
                    int notPick = prev[t];
                    int pick = 0;
                    if(t>=arr[i]) pick = prev[t-arr[i]];
                    
                    curr[t] = (pick+ notPick)%mod;
                }
                prev = curr;
            }
            
            return prev[target];
    }