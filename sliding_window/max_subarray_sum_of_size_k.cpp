long maximumSumSubarray(int k, vector<int> &nums , int n){
      

        int i=0,j=0;

        int size=0;

        long curr= 0,ans =0;
        while(j<n){

            curr+=nums[j];

            if(j-i+1<k){

                j++;
                
            }
            else{
                ans = max(ans,curr);
                curr-=nums[i];
                i++;
                j++;
            }
        }
        return ans;