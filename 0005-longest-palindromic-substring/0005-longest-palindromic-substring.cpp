class Solution {
public:
    
    bool check(string s,int i, int j){
        int left = i, right = j-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            else{ left++;right--;}
        }
        return true;
    }
    
    
    string longestPalindrome(string s) {
       
        // for each string try removing from left side and check till last and then frm right side till got palindrome 
        //like i = 0 j = n-1 => if not equal try 
        //try for i ,j try check(substr(i,j-1)) or check(substr(i+1,j))
        int n = s.size();
        // int i = 0, j = n-1;
        if(n==1) return s;
        
//         for(int len =n-1;len>=1;len--){
//             //start pointer
//             int start = 0;
//             for(start = 0; start <= n-len;start++){
                
//                 if(check(s,start,start+len)==true)return s.substr(start,len);
                
//             }
//         }
        
        vector<vector<int>>dp(n,vector<int>(n,false));
        vector<int>ans = {0,0 };
        
        for(int i =0 ; i<n;i++) dp[i][i] = true;
        
        for(int i =0 ; i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true; 
                ans = {i,i+1};
            }
        }
        
        for(int len = 2; len<n;len++ ){
            //vary length over 2 to n
            for(int  i = 0;i < n-len;i++){
                //var j equals last index of condiderign substring of window
                int j = i+ len;
                //if both last elements of window are equal and dp has true value for inner substring being palindrome
                if(s[i] == s[j] && dp[i+1][j-1] ==true){
                    dp[i][j] =true;
                    ans = {i,j};
                }
            }
        }
        int  i = ans[0],j = ans[1];
        return s.substr(i,j+1-i);
    }
};