class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int n = nums.size();
        if(n==2)return true;
        for(int i =1; i<nums.size();i++){
            
           if(nums[i-1] <= nums[i])inc = true;
           else{
               inc = false;
               break;
           }
                
        }
        for(int i =1; i<nums.size();i++){
            
           if(nums[i-1] >= nums[i])dec = true;
           else{
               dec = false;
               break;
           }
                
        }
        
        return inc || dec;
    }
};