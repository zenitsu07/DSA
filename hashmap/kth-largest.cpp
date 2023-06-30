class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        
// The idea is that we use minHeap to store up to k largest elements so far, where the top of the minHeap is the kth largest element.

        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0 ; i < nums.size();i++){
            
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
            
        }
        return pq.top();
    }
};