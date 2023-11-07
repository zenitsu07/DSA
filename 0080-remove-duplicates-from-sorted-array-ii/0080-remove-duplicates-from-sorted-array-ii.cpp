class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //unique elements appear =  most twice only
        //allow for one duplicate of an element but replace third duplicate
        int n = nums.size();
        
        int i = 0;
        
        //use i to get to an element  != nums[i-2] => we can use this element to swap the ith element => 3rd occurrence of nums[i] value
        
        for(auto elm : nums){
            if(i == 0|| i== 1 || nums[i-2] != elm ){
                nums[i] = elm;//swaps 3rd occurrence to current unique element
                i++; 
            }
        }
        return i;
    }
};

// for(int j = 2; j<n;j++){
//             if(nums[j] == nums[j-2] && nums[j] == nums[j-1]){
//                 //count as duplicate and once found later uniqueu element swap it with that element
//                 cnt++;
//             }
//             else{
                
//                 swap(nums[j-cnt], nums[j]);//swap(nums[4], nums[5])
//                 if(nums[j] == nums[j-2] && nums[j] == nums[j-1]){
//                     //count as duplicate and once found later uniqueu element swap it with that element
//                     //now if satifies => swap is not useful swap end points 
//                     swap(nums[j - cnt], nums[j+cnt]);
//                     cnt++;
//                 }
                
//             }
            
//         }
        