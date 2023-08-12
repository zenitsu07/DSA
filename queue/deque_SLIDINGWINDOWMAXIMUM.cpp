class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        //deque is structure taken because we ahve access to both front and back operations on deque
        // we will store int decressing fashion. i.e. we will have max element at front by popping evrything from back which is less than curr element 
        // if front has max but if its out of bound then pop it 
        deque<int>dq;
        vector<int>ans;
        
        for(int i =0;  i<n;i++){
            
            //boundary condition
            if(!dq.empty() && dq.front() == i-k)dq.pop_front();
            
            //pop from aback all lesser elemnts than curr
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            
            dq.push_back(i);//store the current index once its set to be pushed in right index according to folowing decresing order
            //push front elements as window's max
            if(i>=k-1)ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};
