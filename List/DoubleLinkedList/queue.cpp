#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next, *prev;
};
class Queue{
private:
    Node *rear, *front;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value){
        Node *newNode = new Node();
        newNode->data = value;
        if(front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
            newNode->next = NULL;
            newNode->prev= NULL;
        }
        else{
            rear->next = newNode;
            newNode->prev = rear;
            newNode->next = NULL;
            rear = newNode;
        }
    }
    void dequeue(){
        if(front == NULL && rear == NULL){
            cout<<"Queue is empty."<<endl;
        }
        else if(front == rear){
            Node *temp = front;
            cout<<temp->data<<" is deleted."<<endl;
            delete temp;
        }
        else{
            Node *temp = front;
            cout<<front->data<<" is deleted."<<endl;
            front = front->next;
            front->prev = NULL;
        }
    }
    void display(){
        if(front == NULL && rear == NULL){
            cout<<"Queue is empty."<<endl;
        }
        else{
            Node *temp = front;
            cout<<"Queue:";
            while(temp != NULL){
                cout<<"  "<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}