class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //11 - 5*6, 12-, 13, 14 ,2,3,24,25,
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans =(nums[n-1]*nums[n-2] ) -  (nums[0]*nums[1]);
        return ans;
    }
};