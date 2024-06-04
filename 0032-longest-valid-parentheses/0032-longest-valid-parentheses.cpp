class Solution {
public:
    
    int longestValidParentheses(string s) {
        
        //store substring in stack
        stack<int>st;
        int n = s.size();    
        st.push(-1);
        int ans = 0;
        
        for(int i =0 ; i<n;i++){
                
            if(s[i] == '('){
                st.push(i);//store current index and update maxLend once found closed braces with length between indices 
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);//if its empty take current index as start of new substring
                }
                else{
                    ans = max(ans, i - st.top());
                }
            }
            
        }
        
        return ans;        
        
        
    }
    
    
    
};