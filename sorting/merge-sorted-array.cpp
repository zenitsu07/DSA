#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) +{}
}

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

       //sort from behind the array
       //?fastest approach 

        int i=m-1, j=n-1,temp = m+n -1;

        while(j>=0){
            
            //i till 0  
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[temp] = nums1[i];
                temp--; i--;
            }
            else{
                nums1[temp] = nums2[j];
                temp --;j--;
            }
        }

    }
};
void merge_lists(ListNode* l1,Listnode* l2){
    
}

int main(){
    // int m=3 ,n=3;
    // vector<int> a = {10,20,35};
    // vector<int> b = {5,50,50};
    // Solution s;

    // Solution::merge(a,b,m,n);
    // for (int i = 0; i < m+n; i++)
    // {   
    //     /* code */cout<<a[i]<<" ";
    // }
    vecot<int> lists;
    int n = 3;
    
    for(int i = 0;i<n;i++){
        
        for(int j =0;j< )

    }

    

}