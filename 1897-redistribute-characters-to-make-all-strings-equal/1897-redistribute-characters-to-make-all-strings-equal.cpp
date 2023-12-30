class Solution {
public:
    
    bool makeEqual(vector<string>& words){
        
        //count all chars frequency and if one has extra of req
        
        map<char,int>dict;
        int n = words.size();
        
        if(n == 1)return true;
        
        //take all chars and check if all chars have freq = n
        
        for(int i =0; i<n;i++){
            
            for(int j = 0; j<words[i].size(); j++ ){
                dict[words[i][j]]++;
            }
            
        }
        
        for(auto it = dict.begin(); it!=dict.end(); it++){
            cout<<it->second<<endl;
           if(it->second %n >0)return false;
        }
            
        return true;
        
        
    }
    
};