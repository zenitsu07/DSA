class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int mx = 0;
        int mn = a[0];
        int ans=0;
        int n = a.size();
        int flag = 0;
        
        for(int i=1;i<n; i++){
            
            if(mn>a[i]){
                mn = a[i];
            }
                 else{    
                  
                     mx = max(mx, a[i] - mn);
                 }
                     
            if (i<(n-1)&& a[i]>a[i+1]){
                
                flag++;
                ans +=mx;//answer updates value of max profit for minimum value 
                mn= a[i+1];//mn is updated to buy new stock
                mx = 0;//mx is now 0 to look for new profiut for new mn                                 //update max profit// 5-1 = 4 as 5>3
                
            }
          
        } 
        if(flag>0)
            return ans+mx;
        else return mx;
    }
};