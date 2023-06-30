#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack <int> st2;
    // stack.push(23);
    // stack.push(20);
    // stack.push(26);
    // stack.push(27);
    // stack.push(24);
    // while(!stack.empty()){
    //     cout<< stack.top();
    //     stack.pop();
    // }
    st2.push(23);
    st2.push(20);
    st2.push(26);
    st2.push(27);
    st2.push(24);
    while(!st2.empty()){
        cout<< st2.top();
        st2.pop();
    }
}