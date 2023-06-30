#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,r;
    cin>>s>>r;
    int cnt= 0;
    int n = r.size();
    int i =0,j=0;
    while(i<s.size() || j<n){

        if(s[i] == r[j]){
            
            cnt++;
            j++;
            
        }
        i++;
    }
    cout<<n-cnt<<endl;
    return 0;
}