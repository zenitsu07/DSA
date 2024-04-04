class Solution {
public:
    
   
    
    int maxDepth(string s) {
        
        int depth = 0;
        int max_d = 0;
        
        for(char ch: s){
            if(ch == '('){
                depth++;
                if(depth > max_d ) max_d = depth;
            }
            else if(ch == ')'){
                depth--;
            }
        }
        
        
        return max_d;
    }

};