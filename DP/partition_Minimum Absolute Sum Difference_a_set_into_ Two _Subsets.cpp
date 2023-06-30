//tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int total = 0;
	for(auto it:arr){
			total += it;
	}
	if(total == 0) return 0;
	// vector<vector<bool>>dp(n,vector<bool>(total+1,false));
	// for(int i =0;i<n;i++) dp[i][0] = true;
	// if(arr[0]<=total) dp[0][arr[0]]  = true;

	// for(int ind = 1;ind<n;ind++){
		
	// 	for(int tar = 1; tar <= total ;tar++){

	// 		bool pick = false;
	// 		if(arr[ind]<=tar) pick = dp[ind-1][tar-arr[ind]];
	// 		bool notPick = dp[ind-1][tar];
	// 		dp[ind][tar] = pick|| notPick;

	// 	}	

	// }

	//space optimisation
	vector<bool>prev(total+1,false),curr(total+1,false);
	prev[0] = curr[0] = true;
	if(arr[0]<=total) prev[arr[0]]  = true;

	for(int ind = 1;ind<n;ind++){
		
		for(int tar = 1; tar <= total ;tar++){

			bool pick = false;
			if(arr[ind]<=tar) pick = prev[tar-arr[ind]];
			bool notPick = prev[tar];
			curr[tar] = pick|| notPick;

		}
		prev = curr;	

	}

	//common code
	//possible is vector to check if s2 with sum = total - i can be created where i is 
	vector<bool>possible(total+1,false);
	//store those as true whose target is achieval=ble using row dp[n-1]
	int ans = 10000;
	int diff;
	for(int i =1; i<=total;i++){
		//dp[n-1][i] tells that ith target is achievable 
		possible[total - i] =  prev[i];
		// possible [12-0] = true poss[12-2] = poss[10] = true
		if(possible[total-i] == true) {
			int diff = abs( (total - i) - i );
			ans = min(ans,diff);
		}
	}
	return ans;

}