class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int>maxh;
        
        while(l<=r){
            
            maxh.push(arr[l]);
            if(maxh.size()>k){
                maxh.pop();
            }
            l++;
            
        }
        return maxh.top();
        
    }
};