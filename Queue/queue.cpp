#include<iostream>
#define SIZE 5
using namespace std;
class Queue{
private:
    int front, rear;
    int arr[SIZE];
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int data){
        if(rear == SIZE - 1){
            cout<<"Queue is full"<<endl;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }
    void dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            cout<<"Deleted element: "<<arr[front]<<endl;
            front = -1;
            rear = -1;
        }
        else{
            cout<<"Deleted element: "<<arr[front]<<endl;
            front++;
        }
    }
    void display(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue: ";
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(6);
    q.display();
    return 0;
}