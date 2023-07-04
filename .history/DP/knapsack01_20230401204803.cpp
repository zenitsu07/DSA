
int rec(vector<int>wt,vector<int>val,  int W,int ind,vector<vector<int>>&dp){
	
	if(ind == 0 ){
		//if last index weight stil l can be inserted then return that value else 0
		if(wt[0]<=W){
			return val[0];
		}
		return 0;
	}

	if(dp[ind][W]!=-1) return dp[ind][W];

	int notPick = rec(wt,val,W,ind-1,dp);
	int pick = 0;
	if(wt[ind]<=W) pick = val[ind] + rec(wt,val,W-wt[ind], ind-1,dp);

	int ans = max(notPick,pick);
	
	return dp[ind][W] = ans;

}

int knapsack(vector<int> w, vector<int> val, int n, int maxW) {
	
	//for 1 2 4 5 = w[] and 5 4 8 6 = val[]
	//choose 1 and 4 => 5+8 = 13
	//stores value of each item entered in set ,two options pick aor not pick ,these two options only when maxW>=w[i]

	//here variables are 1 - ind 2- weight
	vector<vector<int>>dp(n,vector<int>(maxW+1,-1));//intialised with dp[n][maxW+1]
	if(maxW == 0) return 0;
	return rec(w,val,maxW,n-1,dp);

}


int knapsack(vector<int> wt, vector<int> val, int n, int maxW) 
{
	// vector<vector<int>>dp(n,vector<int>(maxW+1,0));
	// if(maxW== 0) return 0;
	
	// //for every W >= wt[0] return val[0]
	// for(int W = wt[0]; W<=maxW;W++) dp[0][W] = val[0];

	// for(int i = 1; i<n;i++){
	// 	for(int t = 1; t<=maxW;t++){

	// 		int notPick = dp[i-1][t];
	// 		int pick =0;
	// 		if(wt[i]<=t) pick = val[i]+ dp[i-1][t-wt[i]];

	// 		dp[i][t] = max(pick,notPick); 
	// 	}
	// }
	// return dp[n-1][maxW];
	
	//space opmisation

	vector<int>curr(maxW+1,0),prev(maxW+1,0);
	if(maxW== 0) return 0;
	
	//for every W >= wt[0] return val[0]
	for(int W = wt[0]; W <= maxW; W++) prev[W] = curr[W] = val[0];

	for(int i = 1; i<n;i++){

		for(int t = 1; t<=maxW;t++){

			int notPick = prev[t];
			int pick =0;
			if(wt[i]<=t) pick = val[i]+ prev[t-wt[i]];

			curr[t] = max(pick,notPick); 
		}
		prev = curr;

	}

	return prev[maxW];
	
	//flow for recursion ind = n-1 to 0 => tabulation 1 to n and wt 1 to W
}