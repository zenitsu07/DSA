//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        public: int start;
        int end;
        int pos;
        
    };
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static comparator(struct meeting m1,struct meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;// if both meetign send at same time but m1 pos is bigger than m2's index
    }
    
    int maxMeetings(int start[], int end[], int n){
        
        //store each meetings index so after sortign order is not distruebde
        int cnt=0;
        struct meeting meet[n];
        for(int i = 0; i< n; i++){
            
            meet[i].start = start[i]; 
            meet[i].end = end[i];
            meet[i].pos = i+1;
            
        }
        //after stroing call sort
        sort(meet, meet +n, comparator);
        
        int lastm = -1;
        for(int i = 0; i< n; i++){
        
            if(meet[i].start > lastm){
                cnt++;
                lastm = meet[i].end;
            }
        }
        
        return cnt;
        
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