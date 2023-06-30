
class Solution {
public:
    int res = 0;
     int rec(vector<int>&coins, int amount,int ind,vector<vector<int>>&dp){
        
        
        if(ind==0){
            //if its possible to make store in ans
            if(amount%coins[ind]==0){ 
                
                return 1;
            }
            else return 0;
        }
        
        if(dp[ind][amount]!=-1){ 
            
            return dp[ind][amount];
                       
        }
        
        int notPick = rec(coins,amount,ind-1,dp);
       
        int pick = 0;
        //todo
        //QUESTIONS TYPE -> WHEN WE HAVE INFINTE SUPPLIES OF EACH NUMBER IN ARRAY AND WE ARE TRYING OUT ALL COMBOS TO SOLVE THE PROBLEM
        //THUMB RULE -> FOR F(IND , T) KEEP CALLING THE FUCNTION FOR THE SAME INDEX WITH REDUCING TARGET WHILE PICKING UNTIL CONDITION IS BEIGN SATISFIED
        
        //BASIC CHECK FOR COINS DENOMIATION TO SEE IF ITS NOT GREATER THAN TRGET REQUIRED
        if(coins[ind] <= amount){
            
            pick = rec(coins,amount - coins[ind], ind,dp);
            
        }   
        
        return dp[ind][amount] = pick+notPick;
        
    }

//     int change(int amount, vector<int>& coins) {   if(amount == 0) return 1;
//         // if(amount<=coins[0]) return amount/coins[0];
                                            
//         int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int ans = rec(coins,amount,n-1,dp);
//         return ans;
//     }
              //tabulation
     
// int change(int amount,vector<int> &coins){
    
//         // if(amount<=coins[0]) return amount/coins[0];
//         int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,0));
//         // int ans = rec(coins,amount,n-1,dp);
       
//         for(int amt =0 ; amt<=amount;amt++) {
            
//             dp[0][amt] = (amt%coins[0]==0);
            
//         }
    
//     for(int ind =1; ind <n;ind ++){
        
//         for(int T = 0;T<=amount;T++){
            
//             int notPick = dp[ind-1][T];
//             int pick = 0;

//             if(coins[ind]<=T) pick = dp[ind][T-coins[ind]];
           

//             dp[ind][T] = pick+notPick;

//         }

//     }

//         return dp[n-1][amount];
// }                
    //space optimisation

   int change(int amount,vector<int> &coins){
    
        // if(amount<=coins[0]) return amount/coins[0];
        int n = coins.size();
        vector<int>prev(amount+1,0);
        // int ans = rec(coins,amount,n-1,dp);
       
        for(int amt =0 ; amt<=amount;amt++) {
            
            prev[amt] = (amt%coins[0]==0);
            
        }
    
    for(int ind =1; ind <n;ind ++){
        
        vector<int>curr(amount+1,0);
        
        for(int T = 0;T<=amount;T++){
            
            int notPick = prev[T];
            int pick = 0;

            if(coins[ind]<=T) pick = curr[T-coins[ind]];
           

            curr[T] = pick+notPick;

        }
        prev = curr;
    }

        return prev[amount];
}  

};
    
//SC >>> O(N)
//TC = >>2(^N)
//FOR MEMOIZATION
//TC =O(N*AMOUNT)
//SC = O(N*T)+ O(TARGET)AUXILLARY STACK SPACE OF TARGET 