#include<iostream>
using namespace std;
void insertionSort(int arr[], int size){
   for( int i = 1; i < size; i++){
        int value = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > value; j--){
            arr[j+1] = arr[j];
        }
        arr[j + 1] = value;
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
    insertionSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}
