class Solution {
    
    //NeetCode
    public void swap(int[] nums ,int a, int b){
        
        int temp  =  nums[a];
       nums[a] = nums[b];
        nums[b] = temp;
    }
    
    public void backtrack(int[] nums, List<List<Integer>> ans, int begin ){
 
     if (begin  == nums.length) {
         //construct new arralist and push all elements of current permutation
            List<Integer> list = new ArrayList();
            for (int i = 0; i < nums.length; i++) list.add(nums[i]);
            ans.add(list);
            return;
         
        }

        for (int i = begin; i < nums.length; i++) {
            
            swap(nums, begin, i);
            backtrack(nums, ans, begin + 1);
            swap(nums, begin, i);
        
        }
        
    }
    
    public List<List<Integer>> permute(int[] nums) {
        
        //call barcktrack fhunctiona and for index
        //iterate ove from begin to nth one and perform awap with each once and call again
        
        //sort the array to avoid duplicated
        
        List<List<Integer>>ans = new ArrayList<>();
        
        backtrack(nums, ans,0);
        
        return ans;
        
    }
}