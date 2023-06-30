#include<iostream>
using namespace std;
//this structure decalres a LList then link it to other nodes
struct Node{

    int data;
    struct Node *next;

    Node(int x){

        data = x;
        next = NULL;

    }

    Node *insert_at_last(Node* head,int x){

        Node *temp ;
        temp->data = x;
        tail->next = NULL;
        return temp;

    }

};

int main(){
    
    Node* head = new Node(10);
    Node* tail = head;
    tail = Node->insert_at_last(head,tail,20);
    
}