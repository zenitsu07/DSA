 #include<bits/stdc++.h>
 using namespace std;
 vector<int> findPeakElement(vector<int>& v) {
        
        int n = v.size();
        int start = 0;
        int end = n-1;  

        vector<int>ans;

        if(n==1) {

            ans.push_back(v[0]); 
            return v;
        
        }
        if(v[0]>v[1]) ans.push_back(v[0]);
        if(v[n-1]>v[n-2]) ans.push_back(v[n-1]);
        
        start = 1;
        end = n-2;
        
        while(start <= end){
            int mid = start+ (end-start)/2;
            
            if(v[mid]>v[mid-1]&& v[mid]>v[mid+1]){ 
                ans.push_back(v[mid]);
                end = mid-1;
                // break;
            }
            else if( v[mid] < v[mid-1]) end = mid - 1;
            else if( v[mid] < v[mid+1]) start = mid + 1;
        }
        return ans;
 }

 int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i =0; i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>peaks;
    peaks = findPeakElement(v);
    for(auto it:peaks){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
 }