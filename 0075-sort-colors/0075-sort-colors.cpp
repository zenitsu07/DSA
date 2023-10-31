class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int z =0, o = 0, t = 0;
        for(auto num:nums){
            if(num == 0) z++;
            else if(num == 1)o++;
            else t++;
        }
        int i =0;
        for( i =0; i<z;i++){
            nums[i] = 0;
        }
        while(i<z+o){
            nums[i] = 1;
            i++;
        }
        while(i<z+t+o){
            nums[i] = 2;
            i++;
        }
        
    }
};