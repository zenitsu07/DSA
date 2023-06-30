#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Time -> BigO(1)
struct  Mystack
{
    int *arr;//allocated a pointer named array
    int top;
    int len;
    Mystack(int l){
        len = l;
        arr = new int [len];//allocated pointer to a base memory address with dynamically definign memory locations for specifically total len elements in arr
        //? *new int means "allocate memory for an int, resulting in a pointer to that memory, then dereference the pointer, yielding the (uninitialized) int itself".
        top= -1;
    }
    void push(int n){

        top++;
        arr[top] = n;

    }
    int pop(){

        int ans = arr[top];//store top element in var
        top--;//reduce pointer top from that element to lower one
        return ans; //then return that value of top pointer pointing to
        
    }
    int peek(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isempty(){
        if(top>-1) return false;
        return true;
    }
};


int main(){

    Mystack s(5);
    s.push(3);
    s.push(5);
    s.push(8);
    s.push(15);
    // s.pop();
    while( !s.isempty()){

        cout<< s.peek()<<" ";
        s.pop();

    }
}