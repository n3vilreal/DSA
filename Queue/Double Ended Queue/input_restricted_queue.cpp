#include<iostream>
#define SIZE 4
using namespace std;
class IpResDeque{
    private:
        int rear;
        int front;
        int arr[SIZE];
    public:
        IpResDeque(){
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
        void deleteFromFront(){
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
        void deleteFromRear(){
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
            if(front == -1){
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<"Queue: ";
                int i = front;
                while(true){
                    cout<<arr[i]<<"\t";
                    if(i == rear) break;
                    i = (i + 1) % SIZE;
            }
            }
            cout<<endl;
        }
};
int main(){
    IpResDeque queue;
    int choice, n, value;
    while(1){
        cout<<endl<<"--- Menu ---"<<endl;
        cout<<"1. Enqueue\n2. Delete from Front\n3. Delete from Rear\n4. Display\n5. Exit"<<endl;
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
                queue.deleteFromFront();
                break;
            case 3:
                queue.deleteFromRear();
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