#include<iostream>
using namespace std;
class Node{
public:
    int data, priority;
    Node *next;
};
class PriorityQueue{
private:
    Node *head;
public:
    PriorityQueue(){
        head = NULL;
    }
    void enqueue(int d, int p){
        Node *newNode = new Node();
        newNode->data = d;
        newNode->priority = p;
        if(head == NULL || p < head->priority){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL && temp->next->priority <= p){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void dequeue(){
        if(head == NULL){
            cout<<"Priority queue is empty."<<endl;
        }
        else{
            Node *temp = head;
            head = head->next;
            cout<<temp->data<<" is deleted from the queue."<<endl;
            delete temp;
        }
    }
    void display(){
        if(head == NULL){
            cout<<"Priority queue is empty."<<endl;
        }
        else{
            Node *temp = head;
            cout<<"Priority Queue: ";
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    PriorityQueue p;
    p.enqueue(20,2);
    p.enqueue(10,1);
    p.enqueue(70,7);
    p.enqueue(60,6);
    p.enqueue(90,9);
    p.display();
    p.dequeue();
    p.dequeue();
    p.display();
    return 0;
}