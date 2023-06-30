int maxsubarray(vector<int>& v){
    int n= v.size;
     int mx =  INT_MIN;//for constantly updating to max of each subarray
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=v[i];
            mx = max(mx,curr);
            if(curr<0){
                curr = 0;
            }
        }
        return mx;

}