class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        if( nums.size() < 1) return result;
        
        
        return {first_occurrence(nums, target), last_occurrence(nums, target)};
        
    }
    
    int first_occurrence(vector<int>&nums, int target){
        
        int l = 0, h = nums.size()-1;
        int mid=0;
        
        while(l<=h){
            
            mid = (l+h)/2;
            
            if(nums[mid] == target) {
                if(mid-1>=0 && nums[mid] == nums[mid-1]){
                    h = mid-1;
                }
                else return mid;
            }
            if(mid+1 >= nums.size()) break;
            
            //if el lesser than target increase l
            
            else if( nums[mid]<target ){
                l = mid+1;
            }
            //if greater than
            else h = mid-1;
        }
        
        return -1;
    } 
    
    int last_occurrence(vector<int>&nums, int target){  
        
        int l = 0, h = nums.size()-1;
        int mid = 0;
        
        while(l<=h){
            
            mid = (l+h)/2;
            
            if(nums[mid] == target) {
                
                if( mid+1 <= nums.size()-1 && nums[mid] == nums[mid+1]){
                    
                    l = mid+1;
                    
                }
                
                else return mid;
            }
            else if(nums[mid]<target){
                if( mid+1 <= (nums.size()-1) )
                l = mid+1;
                else break;
            }
            
            else h = mid-1;
        }
        
        return -1;
        
    }
};