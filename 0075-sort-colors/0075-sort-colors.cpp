class Solution {
public:
    void sortColors(vector<int>& A) {
        if( A.size()<2) return;
       int low = 0; 
       int high = A.size()-1;
       for(int i = low; i<=high;) {
           if(A[i]==0) {
              // swap A[i] and A[low] and i,low both ++
              int temp = A[i];
              A[i] = A[low];
              A[low]=temp;
              i++;low++;
           }else if(A[i]==2) {
               //swap A[i] and A[high] and high--;
              int temp = A[i];
              A[i] = A[high];
              A[high]=temp;
              high--;
           }else {
               i++;
           }
       }
        
    }
};