#include<iostream>
using namespace std;
void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}
