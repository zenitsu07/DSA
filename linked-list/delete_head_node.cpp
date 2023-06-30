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
Node *del(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;

}
Node *remove_last(Node *head){
    //searh seocond last node
    if (head == NULL)
        return NULL;
 
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
 
    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = NULL;
 
    return head;
}
int main(){
    Node *head = new Node(10);
     Node *temp1 = new Node(20);
     Node *temp2 = new Node(40);
     Node *temp3 = new Node (50);
          Node *temp4 = new Node (60);

    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;



    head->next = temp1;
     head = del(head);
     while (head!=NULL)
     {
         cout<< head->data<<" ";
         head = head->next;
     }
     

}