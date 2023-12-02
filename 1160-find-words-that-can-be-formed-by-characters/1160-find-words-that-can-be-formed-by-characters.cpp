class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //good if it its a subsequence of chars string
        unordered_map<int,int>ump;
        int n = words.size();
        
        for(int i =0 ; i<chars.size(); i++){
            
            ump[chars[i]]++;
            
        }
        int res =0 ;
        
        for(int i =0 ; i<n; i++){
            
            unordered_map<int,int>list;
            for(int j = 0 ; j < words[i].size();j++){
                
                list[words[i][j]]++; //count every char freq in words[i] stirng then compare each
                
            }
            
            bool flag = true;
            
            for(int j = 0 ; j < words[i].size();j++){
                
                if(list[words[i][j]] > ump[words[i][j]])flag = false; //count every char freq in words[i] stirng then compare each
                
            }
            if(flag == true)res+=words[i].size();
            
        }
        
        return res;
    }
};