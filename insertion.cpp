#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// //NOTE returning a node to main functon so as to ake temp a new head of LL;
// int main(){
// int a[] = {1,2,1,0,5};
// int n = 5;
// vector<int> jump(n);
//         int i = n-1;
//         jump[i] = 0;
//         i = i-1;
//         for(i;i>=0;i--){
//             if(a[i]==0){
//                 jump[i] = INT_MAX;
//                 continue;
//             }
//             if(i+a[i]>=n-1){
//                 jump[i] = 1;
//             }
//             else{
//                 int mn = jump[i+1];
//                 for(int j=i+2;j<=i+a[i];j++){
//                     mn = min(mn,jump[j]);
//                 }
//                 jump[i] = mn + 1;
//             }
//         }
//         for(auto it: jump){
//             cout<<it<<" ";
//         }
//         return 0;
// }
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main(){
    int nums[] = {4,5,7};\iunt n 
        int cnt = 0;
        int ind = 0;
    for(int i =0; i< nums.size() ; i++){
            //if not prime then cn++
            if(isPrime(nums[i])){
            ind = i;
            cout<<ind<<" ";
            break;
            }
            
        }
        cout<<endl;
        if(ind%2==0) cout<< 'A';
        else cout<<'B';
    return 0;

}