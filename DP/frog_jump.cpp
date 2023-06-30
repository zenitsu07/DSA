int solve(vector<int> &h,int i,vector<int>&dp){
    
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int left = solve(h,i-1,dp);
    left += abs(h[i]- h[i-1]);
    int right = INT_MAX;
    if(i>1) right = solve(h,i-2,dp) + abs(h[i]- h[i-2]);
    dp [i] = min(left,right);
    return dp[i];
}
int frogJump(int n, vector<int> &h)
{
    // make recursoion calls fr 2 choice of stairs 
    vector<int>dp(n,-1);
    int ans = solve(h,n-1,dp);
    return ans;
   
}
  
  //tabulation approach->bottom-down
int frogJump(int n, vector<int> &h)
{
    
    //to make bottom-down approach start from 0th index and move up storing every ans in dp[i] 
    //while using dp[o] i.e. initilaised to dp[0] = 0  adn used for first and second steps

    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i =1;i<n;i++){
        //fs stores min steps taken to reach from 0th to ith index when moved from i-1 to i
        int fs = dp[i-1]+ abs(h[i]- h[i-1]);
        int ss=INT_MAX;
        //ss stores min steps taken to reach from 0th to ith index when moved from i-2 to i
        if(i>1) ss = dp[i-2]+ abs(h[i]- h[i-2]);

        dp[i] = min(fs,ss);//dp[i] stores min steps taken from 0th step to reach ith ste using both possible ways
    }

    return dp[n-1];
   
}
  //removing dp arrray
//tabulation approach->bottom-down
int frogJump(int n, vector<int> &h)
{
    
    //to make bottom-down approach start from 0th index and move up storing every ans in dp[i] 
    //while using dp[o] i.e. initilaised to dp[0] = 0  adn used for first and second steps

    int prev = 0;
    int prev2 = 0;
    for(int i =1;i<n;i++){
        //fs stores min steps taken to reach from 0th to ith index when moved from i-1 to i
        int fs = prev+ abs(h[i]- h[i-1]);
        int ss=INT_MAX;
        //ss stores min steps taken to reach from 0th to ith index when moved from i-2 to i
        if(i>1) ss = prev2+ abs(h[i]- h[i-2]);

        int curi = min(fs,ss);//dp[i] stores min steps taken from 0th step to reach ith ste using both possible ways
        prev2 = prev;
        prev = curi;
    }

    return prev;
   
}