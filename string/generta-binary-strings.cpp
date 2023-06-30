void rec(vector<string>&ans,string s, int num,int ind){
        if(ind==num){
            ans.push_back(s);
            return;
        }
        //do not contain consecutive => if s[ind] = '0'=> two options 0 and 1 if s[ind] = '1' => option = s+'0'
        if(s[ind] == '0'){
            rec(ans,s+"0",num,ind+1);
            rec(ans,s+"1",num,ind+1);
        }
        else rec(ans,s+"0",num,ind+1);
        return;
    }

    vector<string> generateBinaryStrings(int num){
        
        vector<string>ans;
        string s = "";
        s = "0";
        rec(ans,s,num,0);//params = ans
        s = "1";
        rec(ans,s,num,0);
        return ans;

    }