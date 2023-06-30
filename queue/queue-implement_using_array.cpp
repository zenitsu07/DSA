#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class MyQueue {

    private:
        // store elements
        int *data;    //pointer initialsed to location of int type
        // a pointer to indicate the start position
        int front;  
                  
    public:

        MyQueue(){ front = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            front++;
            return true;
        };
        int peek(){
            if (isEmpty()) {
                cout<<"empty queue"<<endl;
            }
            return front;
        }
        /** Get the front item from the queue. */
        int Front() {
            return data[front];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return front >= data.size();
        }
        
};

int main() {

    MyQueue q;
    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(10);
    q.enQueue(16);
    q.front();
    q.pop();
    q.front(); 
    while(!q.isEmpty()){
       
        cout << q.Front() <<" ";
        
        q.deQueue();
    }
    cout<<endl; 

}