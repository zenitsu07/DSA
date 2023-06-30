#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// time -> aveg time bigO(1)
//? worst case = bigO(N) due to push and pop functions of vector class
struct  Mystack
{
    vector<int> vec;
    int len;
    int top;
    
    Mystack(int l){
        len = l;
        vector <int> v2(len);
        vec = v2;
        cout<<vec.size();
    }

     void push(int n){

        vec.push_back(n);

    }
    //frot gifves fiest element AND BACK LAST ELEMENT
    int pop(){
        int ans = vec.back();
         vec.pop_back();
    }
    int peek(){
        return vec.back();
    }
    int size(){
        return vec.size();
    }
    bool isempty(){
        return vec.size();
    }
};

int main(){

    Mystack s(5);
    s.push(3);
    s.push(5);
    s.push(8);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    // string st = s.isempty();
    // cout<<st<<endl;
    cout<<s.pop()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    // s.push(40);
    // s.push(50);
    cout<<s.size()<<endl<<s.peek()<<endl;

}