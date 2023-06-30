#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=7;
     int x = 1;
     
    int arr[n] = {0,0,0,1,1,1,1};
    
            int * low = lower_bound(arr, arr+n,x);
            if(low == arr+n || *low !=x){
                low = 0;
            }
            int *up = upper_bound(arr,arr+n,x);
            cout<<up-low;
    return 0;

}