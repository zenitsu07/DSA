class Solution {
    
    public List<List<Integer>> subsets(int[] nums) {
  
        List<List<Integer>>result = new ArrayList<>();
        List<Integer>curr = new ArrayList<>();
        backtrack(result, curr, nums, 0);
        return result;
        
    }
    
    private void backtrack(List<List<Integer>>result, List<Integer>curr, int[] nums, int ind){
        
        if(ind>=nums.length){
            result.add(new ArrayList<>(curr));//push a new arraylist of current 
            return ;
        }
        
        
        curr.add(nums[ind]);
        backtrack(result,curr, nums, ind+1);//after adding call rec for next element
        curr.remove(curr.size() -1); //backtarck by removing last element in current subset config
        backtrack(result, curr, nums,ind+1);
        
    }
    
}