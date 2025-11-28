#include<iostream>
using namespace std;
int fibonacci(int);
int main()
{
    int terms;
    cout<<"Enter number of terms: ";
    cin>>terms;
    for(int i = 1; i<=terms; i++)
    {
        cout<<fibonacci(i)<<"\t";
    }
    return 0;
}  
int fibonacci(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}