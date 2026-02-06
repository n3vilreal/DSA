#include<iostream>
using namespace std;
void bubbleSort(int arr[], int size){
   bool isSorted = false;
   while(!isSorted){
        isSorted = true;
        for(int i = 0; i< size; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSorted = false;
            }
        }
        size--;
   }
}
void printArray(int arr[], int n){
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = {62, 25, 12, 11, 90, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Orignal Array: ";
    printArray(arr, n);
    bubbleSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}