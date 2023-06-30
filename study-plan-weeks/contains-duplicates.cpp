#include<iostream>
using namespace std;

//? sorting approach 99% faster time complexity (12ms)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size(); i++){
//             if(nums[i]==nums[i-1]){
//                 return true;
                
//             }
//         }
//         return false;
//     }
// };

//?approach 2 Unordered map
class Solution{
    public : 
    bool containsDuplicate(vector<int>& nums){
        //constructing map with first-> index and second-> as values
            unordered_map<int,int>m;
            for(int i=0; i<nums.size(); i++){
                m[nums[i]]++;   
            }
            //iterate m using i and i.second have values to look out
            for(auto i:m)if(i.second>1) return true;

            return false;
        }
}

int main(){
    int n;
    cin>>n;

    int nums[];
    for(auto i =0; i<n; i++){
        cin>>nums[i];

    }
    Solution s;
    s.containsDuplicate(nums);

}