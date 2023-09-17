class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
        //use vector to store nges of elements of nums1 in nums2;
        
        vector<int>ans;
        stack<int>st;
        unordered_map<int,int>ump;
        st.push(nums2[0]);
        int n= nums2.size();
        
        for(int i =0; i<n;i++){
            //push in stack and map the 
            int elm = nums2[i];
            while(!st.empty() && elm>st.top()){
                ump[st.top()] = elm;
                st.pop();
            }
            
            st.push(elm);
            
        }
        
        //for this mapping we have all elements nge 
        //if mapping doesnt exist in stack => value = -1
        for(int i =0 ; i< nums1.size();i++){
            if(ump.find(nums1[i])!= ump.end()){
                int nge = ump[nums1[i]];
                ans.push_back(nge);
            }
            else ans.push_back(-1);
        }
        return ans;
        
    }
    
};