class Solution {
public:
        int minCostClimbingStairs(vector<int>& cost) {
            
            int n=cost.size();
            //cost[i] = min of i-1 i-2th cost + current index cost ->so now cost[i] contains total cost taken for climning stairs no ith
            
            int dp[n];
            dp[0] = cost[0];
            dp[1] = cost[1];
            for(int i = 2; i<n;i++){
                
                //current cost  = min of rev and second prev + current stair jump cost
                
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
                
            }
            //reaching a step => ou can take 1 or 2 more steps
            //so return min steps taken to reach last or second last index
            return min(dp[n-1],dp[n-2]);
            //its check for picking min out of last and second last element's cost
    
    }
};