#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    // write your code here
    if(idx==n-1) return arr[idx];
    int mx = max(arr, idx+1, n);//trying to compares the 0th with 1st element 
    //now compare after recursive call
    if(arr[idx]>mx) return arr[idx];
    else return mx;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
