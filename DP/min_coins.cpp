//todo
//QUESTIONS TYPE -> WHEN WE HAVE INFINTE SUPPLIES OF EACH NUMBER IN ARRAY AND WE ARE TRYING OUT ALL COMBOS TO SOLVE THE PROBLEM
//THUMB RULE -> FOR F(IND , T) KEEP CALLING THE FUCNTION FOR THE SAME INDEX WITH REDUCING TARGET WHILE PICKING UNTIL CONDITION IS BEIGN SATISFIED

class Solution {
public:
    //pick a combo of values to minimise the coins number with value = coins vector until value = amount
    
    int rec(vector<int>&coins, int amount,int ind,vector<vector<int>>&dp){
        
        
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[0];
            else return 1e9;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int notPick = rec(coins,amount,ind-1,dp);
       
        int pick = INT_MAX;
        //todo
        //QUESTIONS TYPE -> WHEN WE HAVE INFINTE SUPPLIES OF EACH NUMBER IN ARRAY AND WE ARE TRYING OUT ALL COMBOS TO SOLVE THE PROBLEM
        //THUMB RULE -> FOR F(IND , T) KEEP CALLING THE FUCNTION FOR THE SAME INDEX WITH REDUCING TARGET WHILE PICKING UNTIL CONDITION IS BEIGN SATISFIED
        
        //BASIC CHECK FOR COINS DENOMIATION TO SEE IF ITS NOT GREATER THAN TRGET REQUIRED
        if(coins[ind] <= amount){
            
            pick = 1+ rec(coins,amount - coins[ind], ind,dp);
            
        }   
        
        int ans = min(pick,notPick);
        // if(pick >= 1e9 ||notPick >= 1e9) return -1;
        // if(ans == 1e9) return -1;
        return dp[ind][amount] = ans;
        
    }
    
//     int coinChange(vector<int>& coins, int amount){
        
//         if(amount == 0) return 0;
//         // if(amount<=coins[0]) return amount/coins[0];
//         int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int ans = rec(coins,amount,n-1,dp);
//            return ans >=1e9 ?-1:ans;
        
//     }
    
     //tabulation
     
int coinChange(vector<int> &coins, int amount)
{
    // Write your code here.
    if(amount == 0) return 0;
        // if(amount<=coins[0]) return amount/coins[0];
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans = rec(coins,amount,n-1,dp);
        dp[0][0] = 0;
        for(int amt =0 ; amt<=amount;amt++) {
            if(amt%coins[0] == 0) dp[0][amt] = amt/coins[0];
            else dp[0][amt] = 1e9;
        }

    for(int ind =1; ind <n;ind ++){
        
        for(int amt = 1;amt<=amount;amt++){
            
            int notPick = dp[ind-1][amt];
            int pick = INT_MAX;

            if(coins[ind]<=amt) pick = 1+ dp[ind][amt-coins[ind]];
           

            dp[ind][amt] = min(pick,notPick);

        }

    }

        return dp[n-1][amount] >=1e9 ?-1:dp[n-1][amount];
}
    
};