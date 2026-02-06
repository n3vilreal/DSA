#include<iostream>
using namespace std;
class Node{
public:
    int data, priority;
    Node *next, *prev;
};
class PriorityQueue{
private:
    Node *head, *tail;
public:
    PriorityQueue(){
        head = NULL;
        tail = NULL;
    }
    void enqueue(int d, int p){
        Node *newNode = new Node();
        newNode->data = d;
        newNode->priority = p;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else if(p < head->priority){
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }
        else{
            Node *temp = new Node();
            temp = head;
            while(p > temp->priority && temp->next != NULL){
                temp = temp->next;
            }
            if(temp->next == NULL){
                newNode->next = NULL;
                tail = newNode;
                temp->next = newNode;
                newNode->prev = temp;
            }
            else{
                temp->prev->next = newNode;
                newNode->prev = temp->prev;
                temp->prev = newNode;
                newNode->next = temp;
            }
        }
    }
    void dequeue(){
        if(head == NULL){
            cout<<"Priority Queue is empty."<<endl;
        }
        else if(head == tail){
            Node *deltemp = new Node();
            deltemp = head;
            cout<<deltemp->data<<" is deleted."<<endl;
            delete deltemp;
            head = NULL;
            tail = NULL;
        }
        else{
            
        }
    }
};
