//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

    int rec(vector<int>&arr, int i, int  j, vector<vector<int>>&dp){
        
        if(i>j) return 0; 
        
        int maxi = INT_MIN;
       
       if(dp[i][j]!=-1)return dp[i][j];
       
        for(int ind = i; ind<=j;ind++){
            //for every ind cal its cost with both left and rght subproblems cost
            int cost = arr[i-1]*arr[ind]*arr[j+1] + rec(arr, i, ind-1,dp) + rec(arr, ind+1, j ,dp);
            
            maxi = max(maxi, cost);
        }
        
        return dp[i][j] = maxi;
        
    }

    int maxCoins(int n, vector<int> &arr) {
        
        
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        
        
        //2d dp array
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        //Memoise => initiliase with 0 
        //since wr pushed two elements
        vector<vector<int>>dp(n+2, vector<int>(n+2,0));
        //start from ind = 1 to n-2
        //we go till j = n becasue we have pushed 1 from back and from front = we have size n+2 =? j = n is within bounds
        
        for(int i = n; i>=1; i--){
            for(int j = 1; j<=n;j++ ){
                 
                 if(i>j) continue;//no range ecists
                 
                 int maxi = INT_MIN;
                 for(int ind = i; ind<=j;ind++){
                     int cost = arr[i-1]*arr[ind]*arr[j+1] + dp[i][ind-1]+dp[ind+1][j];
                     
                     maxi =  max(maxi, cost);
                 }
                 
                 dp[i][j] = maxi;
            }
            
        }
        
        return dp[1][n];
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends