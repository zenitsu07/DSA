#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct  Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
//?wne passed a pointer then its copy is made for that function call So 
//fucntion dont affect value of head pointer 
void print_list(Node *head){

    //better approach->gefnerate a node named current and current = head then start traversing
    while (head !=NULL)
    {
        /* code */
        cout<< head->data<<" ";
        head= head->next;//give headnext other node's address usinf next
    //?firstnode->next contains secondnode's address usng nexts
    }
    return ;
}
int main(){

   Node *head = new Node(10);
   head-> next = new Node(15);
   head->next->next = new Node(20);
   head->next->next->next = new Node(25);
   print_list(head);
   //now pass head pounter to a function to treaverse all nodes in list

}


//? The malloc() function takes a single parameter, which is the size of the requested memory area in bytes. It returns a pointer to the allocated memory.