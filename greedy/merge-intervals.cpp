 #include <bits/stdc++.h>
using namespace std;

 class Solution{
    public:
        vector<vector<int>> merge(vector<vector<int>>& in) {
            
            //logic merge them if end[i-1]>= start[i] and push vector  if else
            
            int s = in.size();
            
            sort(in.begin(),in.end());
        
            vector<vector<int>> ans;
            
            vector<int>temp;
            temp = in[0]; 
            //now after sroting take an temp vector which have last interval and compare each onterval with it and
            //if its mergeable ,erge it else push into ans
            for(auto it: in){
                if(it[0] <= temp[1]){
                    if(it[1] > temp[1]){
                        temp[1] = it[1];
                    }
                }
                else{
                    ans.push_back(temp);
                    temp = it;//now temp has current interval which is not pushed yet
                }
            }
            //inLast temp will have last inteval 
            ans.push_back(temp);
            return ans;
            
        }
        //Time comp = Nlogn for sorting and O(N) for linear travaesal of intervals
        //TC = O(NlogN) + O(N)
};