#include<iostream>
using namespace std;

struct Node{
    //everythoing is public 
    int data;
    Node *next;//thus such structure is self referential structure
    //constructor
    Node(int x){
        data = x;
        next = NULL;
    }
 

};
int main(){

    Node *head= new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    //all 3 have next = NULL
    //?now link them

    head->next = temp1;
    temp1->next = temp2;
  
        cout<<head->data<<" "<<temp1->data<<" "<<temp2->data<<" "<<temp1->next<<endl;
    
    
}