#include<bits/stdc++.h>

using namespace std;
void sort_merge(int a[],int b[],int m,int n){
    
    int i=0,j=0;
    while (i<m && j<n)
    {
        if(a[i]<=b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else {
            cout<<b[j]<<" ";
            j++;
        }
    }
    if(i==m){
        for (;j <n; j++)
        {
            cout<<b[j]<<" ";
        }
        
    }
    else{
        for (;i <n; i++)
        {
            cout<<a[i]<<" ";
        }
    }

}
int main(){
    int m=3 ,n=3;
    int a[] = {10,20,35};
    int b[] = {5,50,50};
    sort_merge(a,b,m,n);

}