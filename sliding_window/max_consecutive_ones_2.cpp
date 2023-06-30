class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start =0,end=0;
        int ans = 0;
        int c_zero =0;
        
        //intuition 
        //Use sliding window to cover consecutive ones and 0's until zeroes<=k
        
        //increment the c_zero variable when encountered 0 and run a while loop if its > k 
        //incremet the start variable to adjust the window and if start index == 0 then decreses the count of zero for same
        
        while(end<nums.size()){
            
            if(nums[end] == 0) c_zero++;
            
            while(c_zero>k){
                if(nums[start] == 0){
                    c_zero --;
                }
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
           
        }
        
        return ans;
    }
};