class Solution {
public:
    int maxProfit(vector<int >& a) {
        
        int mx = 0;
        int mn = a[0];
        for(int i=1;i<a.size();i++){
            
            if(a[i]<mn){
                mn = a[i];
            } else{
                mx = max(mx, a[i]-mn);
            }
        }
        return mx;
    }
};