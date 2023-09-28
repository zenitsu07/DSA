class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0;
        for(int i =0; i<nums.size();i++){
            //for odd stick i and 
            if(nums[i]%2==0) even++;
        }
        if(even == 0)return nums;
        int n = nums.size();
        int  i= 0,j=n-1;
        while(i<j ){
            if(nums[i]%2==1){
                while(nums[j]%2!=0 && j>i)j--;
                if(nums[j]%2==0) swap(nums[i],nums[j]);
            }
            i++;
        }
        return nums;
    }
};