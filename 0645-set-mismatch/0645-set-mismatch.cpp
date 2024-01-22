class Solution {
public:
    
    vector<int> findErrorNums(vector<int>& nums) {
        //fidn 
        unordered_map<int,int>m;
        
        for(int num:nums){
            
            m[num]++;
            
        }
        int a=0 , b=0;
        int n = nums.size();
        for(int  i = 1; i<=n;i++){
            
            if(m[i] == 0)b = i;
            if(m[i] == 2)a = i;
        
        }
        return {a,b};
    }
    
};