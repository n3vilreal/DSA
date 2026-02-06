#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    for(int j = low + 1; j <= high; j++){
        if(arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i-1]);
    return i - 1;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n-1);
    cout<<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}
