class Solution {
public:
    bool winnerOfGame(string col) {
        
        //A or B color
        //alice = > remove if both A => AAA
        //Bob B remove = >BBB
        //not from edge only color = middle of 3 char pattern
        //alice get B or Bob get A => other win
        //stack
        //furst 3 then first 3 again indert 2 and check for 3rd 
        //if turn = even =>alice else bob
        int turn =0; 
        
        int n = col.size();
        if(n<=2)return false;
        
        int alice = 0, bob = 0;
        
        for(int i = 1; i < n- 1; i++){
            if(col[i-1] =='A'&&col[i] =='A'&&col[i+1] =='A' )alice++;
            if(col[i-1] =='B'&&col[i] =='B'&&col[i+1] =='B' )bob++;
        }
        
        
        return alice>bob;
    }
};