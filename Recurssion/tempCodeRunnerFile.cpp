#include<iostream>
using namespace std;
int factorial(int);
int main()
{
    int num, fact;
    cout<<"Enter a number: ";
    cin>>num;
    fact = factorial(num);
    cout<<num<<"! = "<<fact;
    return 0;
}  
int factorial(int a)
{
    if(a == 0 || a == 1)
    {
        return 1;
    }
    else
    {
        return factorial(a-1)*a;
    }
}