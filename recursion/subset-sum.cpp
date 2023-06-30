//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void subsets(vector<int>&ans, int sum ,vector<int>&nums,int ind,int n){
        
        if(ind == n ){
            ans.push_back(sum);
            return;
        }
        
        
        //call before and afte including each char
       
            
            subsets(ans,sum+nums[ind],nums,ind+1,n);
            
            subsets(ans,sum,nums,ind+1,n);
        
    }
        
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        int sum = 0;
        int  n = arr.size();
        subsets(ans,sum,arr,0,n);
        return ans;   
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends