class Solution {
public:
    // bool isMonotonic(vector<int>& nums) {
//         bool inc = true, dec = true;
//         int n = nums.size();
//         if(n==2)return true;
//         for(int i =1; i<nums.size();i++){
            
//            if(nums[i-1] <= nums[i])inc = true;
//            else{
//                inc = false;
//                break;
//            }
                
//         }
//         for(int i =1; i<nums.size();i++){
            
//            if(nums[i-1] >= nums[i])dec = true;
//            else{
//                dec = false;
//                break;
//            }
                
//         }
        
//         return inc || dec;
//   }
    
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        bool isIncreasing = false, isDecreasing = false;
        
        for(int i = 0; i < n-1; i++) {
            
            if(nums[i] < nums[i+1])
                isIncreasing = true;
            else if(nums[i] > nums[i+1])
                isDecreasing = true;
            if(isIncreasing & isDecreasing) return false;
            
        }
        
        return true;
    }
    
};