#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;
};
class Stack{
private:
    Node *bottom;
    Node *top;
public:
    Stack(){
        top = NULL;
        bottom = NULL;
    }
    void push(int value){
        Node *newNode = new Node();
        newNode->data = value;
        if(top == NULL){
            newNode->prev = NULL;
            newNode->next = NULL;
            bottom = newNode;
            top = newNode;
        }
        else{
            top->next = newNode;
            newNode->prev = top;
            newNode->next = NULL;
            top = newNode;
        }
        
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
        }
        else if(top->prev == NULL && top->next == NULL){
            Node *temp = top;
            top = NULL;
            bottom = NULL;
            cout<<temp->data<<" is popped from the stack."<<endl;
            delete temp;
        }
        else{
            Node *temp = top;
            top = top->prev;
            top->next = NULL;
            cout<<temp->data<<" is popped from the stack."<<endl;
            delete temp;
        }
    }
    void display(){
        Node *temp = top;
        cout<<"Stack:";
        while(temp != NULL){
            cout<<"  "<<temp->data;
            temp = temp -> prev;
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    s.push(12);
    s.push(43);
    s.push(87);
    s.push(64);
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}