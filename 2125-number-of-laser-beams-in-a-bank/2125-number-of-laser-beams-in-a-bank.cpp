class Solution { 
    
    public:
    
    int numberOfBeams(vector<string>& bank) {
        
        // No secutrity in the ith row i.e. in between r1 and r2
        // Between two lasers on same row there is security => through that jth rows of ith row containing r1 and r2
        vector<int>v;
        vector<int>count;
        int n = bank.size();
        int m = bank[0].size();
        //for every ith row between two lasers mark them isited so 
        //once found an empty above cell to a laser below rowed
        
        for(auto elm: bank){
            
            string s = elm;
            int cnt = 0;
            for(int i = 0; i<m;i++){
                if(elm[i] == '1')cnt++;
            }
            
            if(cnt>0) v.push_back(cnt);
            
            
        }
        
        int res = 0;
        for(int i = 1; i < v.size();i++){
            
            res+= v[i]*v[i-1];
            
        }
        
        return res;
        
    }
    
};