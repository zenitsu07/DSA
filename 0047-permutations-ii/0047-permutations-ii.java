class Solution {
    
    public void back(List<List<Integer>>ans, int[] nums, List<Integer>path, boolean[] vis){

        //check if its reach end then push to ans
        if(path.size() == nums.length){

            ans.add(new ArrayList<>(path));
            return;

        }

        for(int i =0 ; i< nums.length; i++){

            //  check if path has already visited this element and dont include also if next is duplicate avoid 
                if(vis[i] || (i>0 && nums[i-1] == nums[i] && vis[i-1]))continue;
        
                vis[i] = true;
                path.add(nums[i]);
                back(ans, nums, path, vis);
                vis[i] = false;
                path.remove(path.size() - 1);


            }

    }
    
    
    public List<List<Integer>> permuteUnique(int[] nums) {
         List<List<Integer>>ans = new ArrayList<>();
        boolean[] vis = new boolean[nums.length];

        List<Integer>path = new ArrayList<>();

        Arrays.sort(nums);//sort to detect duplicates and not include them
        back(ans, nums, path, vis);
        
        return ans;
    }
};
