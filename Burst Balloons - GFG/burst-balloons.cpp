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
        vector<vector<int>>dp(arr.size(), vector<int>(arr.size(),-1));
        
        //start from ind = 1 to n-2
        return rec(arr, 1,n,dp);
        
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