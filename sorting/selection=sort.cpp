#include<bits/stdc++.h>

using namespace std;
void sort_select(int* arr, int n){
    int  min_index; 
    for (int i = 0; i < n-1; i++){

        min_index=i;
        //swap the min element with arr[i] to get it its correct position
        
        for (int j = i+1; j < n; j++){

            if(arr[min_index]>arr[j]){

                min_index = j;
                
            }
        }
        //now  we have min index's position 
        swap(arr[i],arr[min_index]);                      
    }
                                                                                                        
}

int main(){
    int n =6;
    int arr[6] = {3,5,2,10,14,7};
    sort_select(arr,n);
    
    for (int k = 0; k < n; k++)
    {
        cout<<arr[k]<<" ";
    }
}