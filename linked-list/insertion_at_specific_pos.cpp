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

//to insert at end x , S-1-> allocate memory for x as temp node ,
// S-2 now make previos node->next = temp
Node *insert(Node *head, int x,int pos){

    Node *temp = new Node(x);
    Node *curr = head;
    int cnt = 1;
    if(pos==1){
        temp->next = head;
        return temp;
    }
    while (curr!=NULL)
    {
        if(cnt == pos-1){
            //then assign new temp that position and temp->next noew refernece to curr
            //store next node refernce t temp next then allocate curr next temp
            temp->next = curr->next;
            curr->next = temp;
        
        }
        if(curr==NULL){
            return head;//no need to go further
        }
        curr= curr->next;
        cnt++;
    }
    return head;
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

    Node *head = new Node(5) ;
    Node *temp1 = new Node(20);
     Node *temp2 = new Node(40);
     Node *temp3 = new Node (50);
          Node *temp4 = new Node (60);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    head->next = temp1;

    head = insert(head,10,7);
    // head = insert(head,20,2);
    // head = insert(head,30,2);
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;

    }

    //Function to get the data of required node of key value;
    int idx = 3;
    Node *idx_element = getAt(head, idx);
    cout<<idx_element->data;
}