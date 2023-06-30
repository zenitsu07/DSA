#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//O(1)
struct  Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }

};
//changes inside insert function are not reflected in the head of main function unless its returned to main

Node *insert(Node *head, int x){

//assign values of current head to current pointer and replace head->data with  x and head->next with referencing tp current node's address     
    Node *temp = new Node(x);
    //or temp = (Node *)malloc(sizeof(Node));
    temp ->next = head;
    return temp;

}
Node *getAt(Node *head,int idx){

    Node *temp = head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }
    return temp;

}
//NOTE returning a node to main functon so as to ake temp a new head of LL;
int main(){

    Node *head = NULL;
    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    
}