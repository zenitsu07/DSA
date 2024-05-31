class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        //shoiudl be divisible by both k and nums2[j]
        // update every element divisibility with nums2[j]
        
        //then with k
        int n = nums1.size();
        int m = nums2.size();
        
        map<int,int>mp;
        for(int i  = 0; i<m;i++){
            mp[nums2[i]*k]++; 
        }
        
        long long int ans = 0;
        
        for(int i =0 ; i<n;i++){

            //if divisible push in set
            if(nums1[i] % k !=0)continue;
            
            int el = nums1[i];
            
            for(int f = 1;  f*f<=el;f++){
                
                if(el%f != 0) continue;
                
                int f1 = f, f2 = el/f;
                ans+= mp[f1];
                if(f1!=f2) ans+=mp[f2];
                
                
            }
            
        }
        
        return ans;
        
    }
};