class Solution {
public:
    void subsets(vector<vector<int>>&ans, vector<int>&level ,vector<int>&nums,int ind){
        
        ans.push_back(level); 
        
        //call before and afte including each char
        for(int i= ind;i<nums.size();i++){
            if(i>ind && nums[i] == nums[i-1])
                 continue;//if duplicate then we continue
    
            level.push_back(nums[i]);
            subsets(ans,level,nums,i+1);
            level.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //call for each possible subsets so 
        vector<vector<int>>ans;
        vector<int>level;
        //sort nums vector so duplicates are adjacent
        sort(nums.begin(),nums.end()) ;
        subsets(ans,level,nums,0);
        return ans;
    }
};
//subsets function for includign dublicate subsets also
//     void subsets2(vector<vector<int>>&ans, vector<int>level ,vector<int>&nums,int ind){
//         if(ind==nums.size()){
//         ans.push_back(level); return;
//         }
//         //call before and afte including each char
        
//         subsets(ans,level,nums,ind+1);
//         level.push_back(nums[ind]);
        
//         subsets(ans,level,nums,ind+1);
        
        
        
//     }