class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int j =0,i=0;
        int ans = 0;
        
        while(j<nums.size()){
            
            if(nums[j] == 1){
               
               j++;
            }
            else{
                ans = max(ans,j-i);//once encounterred 0 update and to previous window
                i = j+1;//i will now be start of new window vix is by right of current j index
                j = i;
            }
            
        }
        return max(ans,j-i);
    }
};