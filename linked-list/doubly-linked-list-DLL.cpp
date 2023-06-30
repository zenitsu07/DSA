#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//O(1)
struct  Node{
    int data;
     Node *next;
     Node *prev;
     //constructor
    Node(int x){
        data = x;
        next = NULL;
        prev= NULL;
    }
    

};
int main(){
    Node *head = NULL;
    Node *temp1 = new Node(10);
    Node *temp2 = new Node(15);
    Node *temp3 = new Node(20);
    //as all node will have prev as NULL
    temp1->prev = head;
    temp1->next = temp2;
    temp2 ->prev = temp1;
    temp2->next = temp3;
    while (head)
    {
        /* code */
    }
    
}