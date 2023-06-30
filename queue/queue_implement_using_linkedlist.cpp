#include<iostream>
using namespace std;

struct Node {
public:
    int data;
    Node *next;
    //default constructor
    Node (int d){
        data = d;
        next = NULL;
    }

};

// stack properties->
// 1- removing and inserting from same end 
// 2- Access only to top e  lement
// In linked list we have head pointer pointing to 1st node , So head will point to top of stack
// Becouse removing from tail of LL will be more difficult 

struct Mystack{
    
    Node *head;
    int len;//size
    MyStack(){
        head = NULL; len = 0;
    }
    void push(int x){

        Node *temp = new Node(x);
        temp -> next = head;
        head = temp;
        len++;
    }
    int pop(){

        //delete head pointed node and point to  next node As next Node would be below Node in Stack 
        if(head == NULL){
            cout<<"queueis empty"<<endl;
        }
        //remove first node
        head = head->next;

    }

};

int main(){

   Mystack M;
   M.push(10);
   

}

//Now ceating struct to implement create stack operation with top pointing to NULL inititally
