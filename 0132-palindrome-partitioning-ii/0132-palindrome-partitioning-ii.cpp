class Solution {
public:
    
//     bool isPalindrome(string s, int i, int j){
//         while(i<j){
//             if(s[i]!=s[j]) return false;
            
//             i++;
//             j--;
//         }
        
//         return true;
//     }
    
//     int rec(string s, int i,int n,vector<int>&dp){
//         if(i== n) return 0;
//         if(dp[i]!=-1)return dp[i];
//         int minCost = INT_MAX;
//         //front partition of ith 0 to ith string
//         //i....j
//         for(int j = i; j<n;j++){
            
//             //make partition if that string is palindrome
//             if(isPalindrome(s, i,j)){
//                 int  cost  = 1+ rec(s,  j+1,n,dp);
//                 minCost = min(minCost, cost);
//             }   
            
//         }
        
//         return dp[i] = minCost;
        
//     }
    
//     int minCut(string s) {
//         int n = s.size();
//         // vector<int>dp(n+1,-1);
//         // int dp[n+1];
//         // for(int i =0 ; i<)
//         // return rec(s, 0,n,dp) -1;//start from i = 0 
//         //tabulation
        
//         vector<int>dp(n+1,0);
//         dp[n] = 0;
        
//         for(int i = n-1; i>=0; i--){
            
//             int mini = INT_MAX;
//             for(int j = i; j<n;j++){
//                 if(isPalindrome(s,i,j)){
//                     int cost = 1+ dp[j+1]  ;
//                     mini = min(mini, cost);
//                 }
//             }
//             dp[i] = mini;
            
//         }
     
//         return dp[0]-1;
//     }
    
    
      bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<int> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
				
				Reason : If left substring becomes palindrome then there is no need to partition it further 
				(which in turn reduces the number of recursive calls)
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i] = ans;
    }
    
//     int solve(string s, int i, int j,vector<int>&dp){
        
//         if(i>=j || isPalindrome(s,i,j)) return 0;//if its palindrome no cuts needed
//         int ans =  INT_MAX;

//         if(dp[i]!=-1) return dp[i];
//         //i...j
//         for(int k = i; k<j;k++ ){
//             if(isPalindrome(s,i,k)){
//                 //cakll
//                 int cost =  solve(s,k+1,j,dp)+1;
//                 ans = min(cost, ans);
//             }
//         }

//         return dp[i] = ans;

//     }

    int minCut(string s) {
            int n = s.length();

            /* I've used 1D DP here becoz only one parameter is changing i.e. `i` */

            vector<int> dp (n+1, -1);   

            return solve (s, 0, n-1, dp);
    }
    
};