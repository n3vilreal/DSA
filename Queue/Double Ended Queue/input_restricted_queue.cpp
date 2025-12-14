#include<iostream>
#define SIZE 4
using namespace std;
class IpResQueue{
    private:
        int rear;
        int front;
        int arr[SIZE];
    public:
        IpResQueue(){
            front = -1;
            rear = -1;
        }
        void enqueue(int data){
            if((rear+1)%SIZE == front){
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
        void popFromFront(){
            if(front == -1 && rear == -1){
                cout<<"Queue is empty"<<endl;
            }
            else if(front == rear ){
                cout<<arr[front]<<" is deleted from the Queue."<<endl;
                front = -1;
                rear = -1;
            }
            else{
                cout<<arr[front]<<" is deleted from the Queue."<<endl;
                front = (front + 1) % SIZE;
            }
        }
        void popFromRear(){
            if(front == -1 && rear == -1){
                cout<<"Queue is empty"<<endl;
            }
            else if(front == rear){
                cout<<arr[rear]<<" is deleted from the Queue."<<endl;
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                cout<<arr[rear]<<" is deleted from the Queue."<<endl;
                rear = SIZE - 1;
            }
            else{
                cout<<arr[rear]<<" is deleted from the Queue."<<endl;
                rear -= 1;
            }
        }
        void display(){

            cout<<arr[0]<<endl;
            cout<<"Queue: ";
            for(int i = 0; i < SIZE; i++){
                cout<<arr[i]<<"\t";
            }
        }
};
int main(){
    IpResQueue queue;
    int choice, n, value;
    while(1){
        cout<<"Menu"<<endl;
        cout<<"1. enqueue\n2. Pop from Front\n3. Pop from Rear\n4. Display\n5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value ";
                cin>>value;
                queue.enqueue(value);
                cout<<endl;
                break;
            case 2:
                queue.popFromFront();
                break;
            case 3:
                queue.popFromRear();
                break;
            case 4:
                queue.display();
                break;
            case 5:
                exit(1);
                break;
            default:
                cout<<"--- Invalid Input ---"<<endl;
                break;
        }
    }
    return 0;
}