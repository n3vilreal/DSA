#include<iostream>
using namespace std;
class Node{
private:
    int data;
    Node *next, *head;
public:
    Node(){
        head = NULL;
    }
    void insertAtBeg(int data){
        Node *newnode = new Node();
        newnode -> data = data;
        if(head == NULL){
            newnode -> next = NULL;
            head = newnode;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }
    void insertAtEnd(int data){
        Node *newnode = new Node();
        newnode -> data = data;
        if(head == NULL){
            newnode -> next = NULL;
            head = newnode;
        }
        else{
            Node *temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newnode;
            newnode -> next = NULL;
        }
    }
    void insertAtPos(int data){
        Node *newnode = new Node();
        newnode -> data = data;
        int pos;
        cout<<"Enter the position: ";
        cin>>pos;
        if(pos == 1){
            if(head == NULL){
            newnode -> next = NULL;
            head = newnode;
            }
            else{
                newnode -> next = head;
                head = newnode;
            }
        }
        else{
            Node *temp = head;
            int i = 1;
            while(i < pos-1){
                temp = temp -> next;
                i++;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }

    }
    void deleteAtBeg(){
        if(head == NULL){
            cout<<"Linked list is empty."<<endl;
        }
        else{
            Node *temp = head;
            head = head -> next;
            cout<<temp->data<<" is deleted from the list."<<endl;
            delete temp;
        }
    }
    void deleteAtEnd(){
        if(head == NULL){
            cout<<"Linked list is empty."<<endl;
        }
        else{
            Node *temp = head;
            Node *prevnode;
            while(temp -> next != NULL){
                prevnode = temp;
                temp = temp -> next;
            }
            prevnode -> next = NULL;
            cout<<temp->data<<" is deleted."<<endl;
            delete temp;
        }
    }
    void deleteAtPos(){
        int pos;
        cout<<"Enter the position: ";
        cin>>pos;
        Node *temp = head;
        if(pos == 1){
            if(head == NULL){
            cout<<"Linked list is empty."<<endl;
            }
            else{
                Node *temp = head;
                head = head -> next;
                cout<<temp->data<<" is deleted from the list."<<endl;
                delete temp;
            }
        }
        else{
            int i = 1;
            while(i < pos-1){
                temp = temp -> next;
                i++;
            }
        }
        Node *nextnode = temp -> next;
        cout<<nextnode->data<<" is deleted from the list."<<endl;
        temp -> next = nextnode -> next;
        delete nextnode;
    }
    void searchElement(){

    }
    void display(){
        if(head == NULL){
            cout<<"List is empty."<<endl;
        }
        else{
            Node *temp = head;
            cout<<"Linked list: ";
            while(temp != NULL){
                cout<<temp->data<<"\t";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }
};
int main(){
    Node n;
    n.insertAtBeg(5);
    n.insertAtEnd(10);
    n.insertAtPos(20);
    n.display();
    n.deleteAtBeg();
    n.display();
    n.deleteAtPos();
    n.display();
    n.deleteAtEnd();
    n.display();
    return 0;
}