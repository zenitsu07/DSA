class Solution {
    
    public void backtrack(int[] candidates,int target,List<List<Integer>> ans, List<Integer> curr,int ind) {
        
        //base if 0th index push the current combination of elements
        if (target == 0) {
            ans.add(new ArrayList(curr));
        } else if (target < 0 || ind >= candidates.length) {
            return;
        } else {
            
            
            curr.add(candidates[ind]);
            backtrack(candidates, target - candidates[ind], ans, curr, ind);
            curr.remove(curr.size() -1); 
            backtrack(candidates, target, ans, curr, ind+1);
            
        }
        
        
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        List<List<Integer>>result = new ArrayList<>();
        List<Integer>curr = new ArrayList<>();
        backtrack(candidates,target, result, curr ,0 );
        return result;
        
    }
}