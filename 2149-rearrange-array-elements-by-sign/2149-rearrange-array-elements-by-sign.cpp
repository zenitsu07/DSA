class Solution {
public:
    
    vector<int> rearrangeArray(vector<int>& nums) {
        
        //for every two same signs elements find opposire signed closest int and rotate as it appears at nums[i] from nums[j] where all elements shift to right by 1
        
        //shift the first pos to 0th index and shift every to 
        // int  n =  nums.size();
        
//         // map<int,int>pos,neg;
//         set<int>pos,neg;
        
//         for(int i = 0; i<n;i++){
            
//             if(nums[i]>0)pos.insert(nums[i]);
//             else neg.insert(nums[i]); 
        
//         }
        
//         for( auto it = pos.begin() , i = 0 ; it != pos.end(), i<n;i+=2,it++){
            
//             nums[i] = *it;
           
            
//         }
//         for( auto it = pos.begin(), int i = 1 ; it != neg.end(), i<n;i+=2,it++){
            
//             nums[i] = *it;
           
            
//         }
        
//         return nums;
        
         vector<int> a, b, c;

        // Separate positive and negative integers into two separate arrays
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        // Interleave positive and negative integers while preserving their order
        int count = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count % 2 == 0) {
                int n = a[c1++];
                c.push_back(n);
            } else {
                int n = b[c2++];
                c.push_back(n);
            }
            count++;
        }

        return c;
    }
    
};