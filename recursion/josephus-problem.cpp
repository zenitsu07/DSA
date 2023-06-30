#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v, int k,vector<int>::iterator it,int& ans ){

    if(v.size()==1) {
        ans = v[0];
        return;
    }

    it = (it+k) %(v.size());
    erase(it);
    //call with smaller input
    solve(v,k,it,ans);

}
//given n kill every kth member in circle fashion
int main(){
    int n;
    int k;
    cin>>n>>k;
    solve(n,k);
    vector<int>v;
    for(int i =0; i<n;i++){
        v.push_back(i+1);
    }
    vector<int>::iterator it ;
    it = v.begin();
    int ans=0 ;
    solve(v,k-1,ind,ans);
    cout<<ans<<endl;
}
