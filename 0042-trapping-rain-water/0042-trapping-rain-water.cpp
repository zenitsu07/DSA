class Solution {
public:
    
    //Its follow up question of Container with most water
    
    //intuition inseated of finding max area holding container we have to find units stored by every container
    
    int trap(vector<int>& height){
        
        //store those indices which have 0 height and if container has i and j with that any suh index then store all units of space with height min hi, hj
        
        int n = height.size();
        
        //Optimal solution
        
        int i = 0,j = n-1, units = 0;
        int lmax = 0,rmax = 0,res = 0;
        //start form 1st and 2nd last index and update the left and right max 
        
        while(j >= i){
            
           if(height[i] <= height[j]){
               
               if(height[i] >= lmax){
                   lmax = height[i];
               }
               else res+= lmax - height[i];
               
               i++;
               
           }else{

                if(height[j]>=rmax){
                    rmax = height[j];
                }else res+= rmax - height[j];
               
               j--;
           }
            
        }
        return res;
        
    }
    
};

 //Better approach than iterating loop 2n times to find max left and max right of indixes
//use prefix and suffix to get maxleft and maxright of current index
//         vector<int>prefix(n),suffix(n);
//         int units = 0;
//         int left = 0,right = 0;
//         for(int i =0 ; i<n;i++){
            
//             prefix[i] = max(left,height[i]);
//             left = max(left,height[i]);
            
//         }
//         for(int  j =n-1; j>=0; j--){
            
//             suffix[j] = max(right,height[j]);
//             right = max(right, height[j]);
            
//         }
        
//         for(int i =0; i<n;i++){
//             units+= min(prefix[i], suffix[i]) - height[i];
//         }
        
//         return units;
//         //Time = O(N) == O(3n) but expra space O(2n) not best
        
        