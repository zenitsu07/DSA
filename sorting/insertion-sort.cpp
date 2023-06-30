#include<bits/stdc++.h>

using namespace std;
void sort_insertion(int* arr,int n){

    for (int i = 1; i < n ; i++)
    {
        int key = arr[i];
        //increasing sorted array each time with i
        int j = i-1;
        //keep elements move ahead by one position
       
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;
        }
        //now space is created for the key element to be inserted so ,
        arr[j+1] = key;
        
    }
    
}

int main(){
    int n=6;
    int arr[n] = {20,5,40,60,10,30};
    sort_insertion(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
//for case when i = 2 and j = 1 then control dont go inside while loop and set arr[j+1] i.e. = arr[i] = key itself 
// impolies in this case values retains at previous position 