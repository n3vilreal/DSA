//Program to choose to push or pop data to stack
#include<iostream>
#define MAX 10
using namespace std;
class Stack
{
private:
    int top=-1;
    int arr[MAX];
public:
    void push(int data)
    {
        if(top==MAX-1)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            top+=1;
            arr[top] = data;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            cout<<arr[top]<<" is deleted"<<endl;
            top-=1;
        }
    }
    void displayStack()
    {   
        cout<<"Stack: ";
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
};
int main()
{   
    Stack s;
    int choice, n, value;
    while(1)
    {
        cout<<"Menu"<<endl;
        cout<<"1: Push"<<endl<<"2: Pop"<<endl<<"3: Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"How many values? (Less than 10): ";
                cin>>n;
                for(int i=1;i<=n;i++)
                {
                    cout<<"Enter value "<<i<<": ";
                    cin>>value;
                    s.push(value);
                }
                s.displayStack();
                cout<<endl;
                break;
            case 2:
                cout<<endl<<"How many values to delete: ";
                cin>>value;
                for(int i=0;i<value;i++)
                {
                    s.pop();
                }
                break;
            case 3:
                cout<<"Exiting Program";
                exit(1);
            default:
                cout<<"Invalid input";
        }
    }
    return 0;
}
