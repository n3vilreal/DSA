#include<iostream>
#define SIZE 5
using namespace std;
class OpResDeque{
private:
    int front, rear;
    int arr[SIZE];
public:
    OpResDeque(){
        front = -1;
        rear = -1;
    }
    void enqueueFromRear(int data){
        if((rear + 1) % SIZE == front){
            cout<<"Queue is full."<<endl;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if(rear == SIZE - 1){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear = (rear + 1) % SIZE;
            arr[rear] = data;
        }
    }
    void enqueueFromFront(int data){
        if((rear + 1) % SIZE == front){
            cout<<"Queue is full."<<endl;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if(front == 0){
            front = SIZE - 1;
            arr[front] = data;
        }
        else{
            front = front - 1;
            arr[front] = data;
        }
    }
    void dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty."<<endl;
        }
        else if(front == rear){
            cout<<arr[front]<<" is deleted."<<endl;
            front = -1;
            rear = -1;
        }
        else{
            cout<<arr[front]<<" is deleted."<<endl;
            front = (front + 1) % SIZE;
        }
    }
    void display(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty."<<endl;
        }
        else{
            cout<<"Queue: ";
            int i = front;
            while(true){
                cout<<arr[i]<<"\t";
                if(rear == i) break;
                i = (i + 1) % SIZE;
            }
        }
    }
};
int main(){
    OpResDeque queue;
    int choice, n, value;
    while(1){
        cout<<endl<<"--- Menu ---"<<endl;
        cout<<"1. Enqueue from Rear\n2. Enqueue from Front\n3. Dequeue from Front\n4. Display\n5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                queue.enqueueFromRear(value);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>value;
                queue.enqueueFromFront(value);
                break;
            case 3:
                queue.dequeue();
                break;
            case 4:
                queue.display();
                break;
            case 5:
                cout<<"Program Exited"<<endl;
                exit(1);
                break;
            default:
                cout<<"--- Invalid Input ---"<<endl;
                break;
        }
    }
}