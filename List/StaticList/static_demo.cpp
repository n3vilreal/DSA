#include<iostream>
#define SIZE 4
using namespace std;
class StaticList{
    private:
        int rear;
        int arr[SIZE];
    public:
        StaticList(){
            rear = -1;
        }
        void insertAtEnd(int data){
            if(rear == SIZE - 1){
                cout<<"Static list is full."<<endl;
                return;
            }
            else{
                rear ++;
                arr[rear] = data;
            }
        }
        void insertAtGivenPosition(int data){
            if(rear == SIZE - 1){
                cout<<"Static list is full."<<endl;
            }
            else{
                int temp = rear;
                int pos;
                cout<<"Enter position to insert at: ";
                cin>>pos;
                while(temp >= pos -1){
                    arr[temp + 1] = arr[temp];
                    temp --;
                }
                rear++;
                arr[pos - 1] = data;
            }
        }
        void deleteFromEnd(){
            if(rear == -1){
                cout<<"Static list is empty."<<endl;
            }
            else{
                cout<<arr[rear]<<" is deleted from the list."<<endl;
                rear--;
            }
        }
        void deleteFromPosition(){
            if(rear == -1){
                cout<<"Static list is empty."<<endl;
            }
            else{
                int pos;
                cout<<"Enter position to delete from: "<<endl;
                cin>>pos;
                int temp = pos - 1;
                cout<<arr[temp]<<" is deleted from the list."<<endl;
                while(temp<rear){
                    arr[temp] = arr[temp + 1];
                    temp++;
                }
                rear--;
            }
        }
        void searchElement(int key){
            int index = 0;
            for(int i = 0; i < SIZE; i++){
                if(key == arr[i]){
                    index = 1;
                    break;
                }
            }
            if(index == 0){
                cout<<"Search not Found."<<endl;
            }
            else{
                cout<<"Search found."<<endl;
            }
        }
        void display(){
            if(rear == -1){
                cout<<"Static list is empty."<<endl;
            }
            else{
                cout<<"List: ";
                for(int i = 0; i <= rear; i++){
                    cout<<arr[i]<<"\t";
                }
                cout<<endl;
            }
        }
};
int main(){
    StaticList li;
    int choice, n, value;
    while(1){
        cout<<endl<<"--- Menu ---"<<endl;
        cout<<"1. Insert at End\n2. Insert at Given Position\n3. Delete from End\n4. Delete from Given Position\n5. Search Element\n6. Display\n7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                li.insertAtEnd(value);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>value;
                li.insertAtGivenPosition(value);
                break;
            case 3:
                li.deleteFromEnd();
                break;
            case 4:
                li.deleteFromPosition();
                break;
            case 5:
                cout<<"Enter value to search: ";
                cin>>value;
                li.searchElement(value);
                break;
            case 6:
                li.display();
                break;
            case 7:
                cout<<"Program Exited"<<endl;
                exit(1);
                break;
            default:
                cout<<"--- Invalid Input ---"<<endl;
                break;
        }
    }
}