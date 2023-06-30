#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Time -> BigO(1)
struct StackNode(){
    Node* size;
    StackNode* next;
    int data;
    
    StackNode(int x){
        data = x;
        next = NULL;
    }
}
struct  Mystack
{
    
    StackNode* top;
    int size;
    Mystack(){
        top= NULL;
        size=0;
    }
    void push(int n){
        size++;
        StackNode* temp = new StackNode(n);
        if(top==NULL) top = temp;
        //inserting in a stack means insertin gat teh top but using linked list through head pointer beginning o list works as top of the stack, SO insert at beginning of list

        else{
            temp ->next = top;
            top = temp;
        }
    }
    //pop from beginning ie.. top of stack
    int pop(){
        if(top==NULL) return -1;
        StackNode* temp;
        temp = top;
        int val = top->data;
        top = top->next;
        delete(temp);
        size--;
        return data;
    }
    
    int Size(){
        return size

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
        cout<<S.size();

    }
}