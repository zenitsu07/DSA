class Solution {
public:
    
    //Binary earch intuition 
    // we start by having max element of array and we will ave mid of that and one by one we will use fucntion isPossible which will iiterate the array to look for k elements lower than equal to mid if those =k => mid is possiblke then we will look for range left to mid -1 else we will search shorter left range i.e. mid+1
    
    bool isPossible(int mid, vector<int>&nums, int k,int n ){
         
        int i =0;
        while(i<n){
            if(nums[i]<=mid){
                k--;
                i+=2;
                
            }
            else i++;
            
            if(k==0) return true;
        }
        
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int n= nums.size(); 
        int left = 0,right = *max_element(nums.begin(), nums.end());
        
        while(left< right){
            //median
            int mid = (right + left)/2;
            
            if(isPossible(mid,nums,k,n ) )right = mid   ; 
            else left = mid+1;
            
        }
        
        return right;
        
    }
};