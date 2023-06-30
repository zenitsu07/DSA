class Solution{
    int find(vector<int>&num){
        unordered_map<int,int>mp;
        for(auto it:num){
            mp[it]++;
        }
        int cnt =0;
        for(auto it:mp){
            
            if(it.second==1) return +-1;
            if(it.second%3==0){
                cnt += it.second/3;
            }
            else if(it.second%3==2){
                cnt += (it.second/3)+ 1;
            }
        }
        return cnt;

        
    }
};