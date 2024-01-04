class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        //map all elements
        unordered_map<int,int>ump;
        
        for(auto x: nums) ump[x]++; 
        
        //for freq == 1return -1;
        int ans = 0;
        
        for(auto it = ump.begin(); it!=ump.end(); it++){
            
            if(it->second == 1)return -1;
            //if 4
            if(it->second%3==0)ans+= it->second/3;
            else if(it->second%3 ==1 )ans+= ( (it->second/3) - 1 )+2;
            else ans+=  (it->second/3) +1;
            
        }
        
        return ans;
        
    }
};