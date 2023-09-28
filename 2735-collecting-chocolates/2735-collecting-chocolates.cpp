class Solution {
public:
    
    private:
    void rightShifting(vector<int> &nums) {
        int last = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >=0 ; i--) {
            nums[i+1] = nums[i];
        }
        nums[0] = last;
    }
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> cost(n, LONG_MAX);
        long long mini = LONG_MAX;
        for(int i = 0; i < n; i++) {
            rightShifting(nums);
            long long totalCost = (long long)(x) * (long long)(i);
            for(int j = 0; j < n; j++) {
                cost[j] = min(cost[j],(long long)nums[j]);
                totalCost+=cost[j];
            }
            mini = min(mini, totalCost);
        }
        return mini;
        
    }
    
//     long long minCost(vector<int>& nums, int x) {
//         //greedy appraoch
//         //perform max operations possible with nums[n-1 ] -> nums[0] if less cost for circular
//         //for each cost+=x
        
//         int n = nums.size();
//         long long before = 0, after = 0;
//         for(auto elm : nums) before+=elm;
        
//         //calc after
//         //perform ops
        
//         //for simulatenous peform operations 
//         //use stack to store next smaller element
//         //for smaller incoming elem 
        
//         stack<long long>st;
//         unordered_map<long long , long long>nse;
//         //index of curr, index of nse
//         for(int i =0;i<n;i++ )nse[i] = -1;
//         st.push(0);
        
//         for(int i = 1; i<n;i++){
            
//             int elm = nums[i];//element comapraison
                
//             //udpdate ump;
//             //hold the current nge and look for next
//             if(nums[st.top()] > elm+x){
//                 //updaete and remove
//                 nse[st.top()] = i;//map nse index
//                 st.pop();
//             }
            
//             st.push(i);
        
            
//         }
        
//         //now we have not ampped elements
//         //iterate those whose nse[i] >-1
//         for(int i =0 ; i< n-1;i++){
            
//             //for all elements less try updating every  
//             if(nums[st.top()]>nums[i]+x){
//                 //updaete and remove
//                 nse[st.top()] = i;//map nse index
//                 // st.pop();
//             }
            
//         }
//         //remaining get -1 as mapped
//         //acc to nse mapped change them 
//         int ops = 0; 
//         for(int i =0 ; i< n; i++){
//             //for mapped update cost with mapped elm + x
//             int diff =0;
//             if(nse[i] >-1) diff = nse[i] - i;
//             if(diff <0 && nse[i] !=-1)diff = abs(diff)+1;//goind circular for that nearest index
//             ops = max(ops,diff);
            
            
//             if(nse[i]>-1){
//                 after += nums[nse[i]] ;
//             }
//             else after+= nums[i];
//         }
        
//         after+= (ops*x);
        
//         return min(before,after);
        
//     }
};