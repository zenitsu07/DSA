class Solution {
public:
    string frequencySort(string s) {
        
//         //sort by frequency 
//         //min heap to order frequenices and to get them from min ot max frequencies 
//         int n = s.size();
        
//         map<int,int> mp;
//         priority_queue<int>pq;
        
//         for(int i = 0 ; i <n;i++ )
//             mp[s[i]]++;
        
        
//         for(int i = 0 ; i < n;i++ ){
            
//             pq.push()
            
//         }
        
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;//we take frequency and push characters based on index = frequecy => to sort acoo to freq we traverse from backwards to get higher frequency elements first in order
            char c = it.first;
            bucket[n].append(n, c);//push char c -> n times
        }
        
        //form descending sorted string
        
        for(int i=s.size(); i>0; i--) {
            
            if(!bucket[i].empty())
                res.append(bucket[i]);
            
        }
        
        return res;
    }
};