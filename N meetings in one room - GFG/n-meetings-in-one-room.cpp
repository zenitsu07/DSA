//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct meeting{
    public:
    int start;
    int end;
    int pos;
};

class Solution{
    
    public:
    
    bool static comp(meeting &m1, meeting &m2){
        
        if(m1.end<m2.end)return true;
        else if(m1.end>m2.end)return false;
        else if(m1.pos<m2.pos)return true;
        return false;
        
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        
        // sort acco to start time
        //chooose then 
        //construct a meeting struct
        
        struct meeting meet[n];
        
        for(int i = 0 ;i< n;i++){
            
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;//index of meeting
            
        }
        
        sort(meet,meet+n, comp);
        
        int res = 0;
        int lastT = 0;
        for(int i =0 ; i<n;i++){
            
            if(meet[i].start>lastT){
                res++;
                lastT = meet[i].end;
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends