#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

class MyQueue {

    private:
        // store elements
    int *arr;
        // a pointer to indicate the start position
        int front = -1;            
    public:

        MyQueue(){}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {

            front++;
            arr[front] = x;
            return true;

        }
 
        /** Delete an element from the queue i.e. delete . Return true if the operation is successful. */
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
                return -1;
            }
            return front;

        }

        /** Get the front item from the queue. */
        int front() {

            return data[front];
        
        }

        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return front >= data.size();
        }
        
        void display(){
            for (int i = 0; i < front; i++)
            {
                cout<<arr[front]<<" ";
            }
            cout<<endl;
        }
        
};

int main() {

    MyQueue q;
    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(10);
    q.enQueue(16);
    
    q.deQueue();
    q.display();
    cout<<endl; 

}