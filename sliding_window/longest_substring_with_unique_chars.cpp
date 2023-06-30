 class Solution{
    public:
    
    int longestUniqueSubsttr(string s){
 
        vector < int > mpp(256, -1);

        int l = 0, r = 0;
        int n = s.size();
        
        int len = 0;
        //use map to keep track of which index the char latest appeard
        while (r < n) {
            //check if s[j]  s[r] != -1 then update i to the right  index of repeating character appearance
        
        if (mpp[s[r]] != -1)//s[right exists] in map
        
            l = max(mpp[s[r]] + 1, l);

        mpp[s[r]] = r;//update the index of the current character in the map

        len = max(len, r - l + 1);//update the value of ans with the length of the current window
        r++;
        
        }
        return len;
    }
};