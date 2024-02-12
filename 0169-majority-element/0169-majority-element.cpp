class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
     
        //sort and if any element firs and last occurrence > n/2
        
        int i  =0 , j = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int first  = 0, last = 0;
        while(i<n){
            
            
            first = i; last = i+1;
            while(last<n&& nums[first]==nums[last]){
                last++;
                
            }
            if(last- first >(n/2)) return nums[first];
            i= last ;
        }
        
        return -1;
    }
};