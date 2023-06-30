#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *link;

};
int main(){

    struct node *head = NULL;
    //to allocate memory in head pointer and address of node in its link component
    head = (struct node *)malloc(sizeof(struct node));//malloc returns a pointer and its typecasted to struct node pointer type
    // malloc()->This function is used to assign a specified amount of memory for an array to be created. It also returns a pointer to the space allocated in memory using this function.
    //?its address store hoga head pointer ke pass
    head->data = 40;
    head->link = NULL;
    //conpy head to new pointer 
    struct node *current = NULL;
    current = head;//current can  be used to point to each node
    //creating 2nd node
    current = (struct node *)malloc(sizeof(struct node));//address to place next node
    current->data = 70;
    current->link = NULL;
    //updating previous node's link
    head->link->link = current;


    cout<< &(head->link)<<endl;//head->link means link part of first node whic contains address of second nodes'sdata
    cout<<"HEAD->link->link gives:" <<head->link->link<<"address of 2nd node "<<endl;
    //3link subsequence will give null 
    // using head u can access each node's address

    for (int i = 0; i < 3; i++)
    {
        current = (struct node *)malloc(sizeof(struct node));
        current->data = 90;
        current->link = NULL;
        head->link->link = current;
    }
    
    //head-> link always points to address of node's data 

}


//? The malloc() function takes a single parameter, which is the size of the requested memory area in bytes. It returns a pointer to the allocated memory.