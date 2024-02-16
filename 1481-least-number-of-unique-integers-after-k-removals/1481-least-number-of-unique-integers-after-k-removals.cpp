class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        //toatl unqieu elements count and duplicate count
        //for k remove k unique ones
        
        int unique = 0;
        
        map<int,int>mp;
        
        for(auto it: arr)
           mp[it]++;
        
        vector<int>freq;
        
        for(auto& pair:mp){
            
            freq.push_back(pair.second);
            
        }
        
        sort(freq.begin(), freq.end());
        
        int count = 0;
        
        for(int i = 0 ; i<freq.size(); i++ ){
             
            if(k>= freq[i]){
                k -= freq[i];
                count++;
            }
            else{
                break;
            }
            
        }
        
        return freq.size() - count;
        
    }
};