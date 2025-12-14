#include<iostream>
#define SIZE 5
using namespace std;
class CircularQueue{
private:
    int front, rear;
    int arr[SIZE];
public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int data){
        if((rear + 1 ) % SIZE == front){
            cout<<"Queue is full"<<endl;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear = (rear + 1) % SIZE;
            arr[rear] = data;
        }
    }
    void dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear ){
            cout<<"Delete element: "<<arr[front]<<endl;
            front = -1;
            rear = -1;
        }
        else{
            cout<<"Delete element: "<<arr[front]<<endl;
            front = (front + 1) % SIZE;
        }
    }
    void display(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue: ";
            for(int i = front; i != rear; i = (i + 1) % SIZE){
                cout<<arr[i]<<"\t";
            }
            cout<<arr[rear]<<endl;
        }
    }
};
int main(){
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.display();
    cq.enqueue(6);
    cq.display();
    return 0;
}