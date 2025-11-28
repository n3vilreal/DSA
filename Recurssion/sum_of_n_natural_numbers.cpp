#include<iostream>
using namespace std;
int sumNatural(int);
int main()
{
    int num, sum;
    cout<<"Enter a number: ";
    cin>>num;
    sum = sumNatural(num);
    cout<<"Sum of first "<<num<<" natural numbers = "<<sum;
    return 0;
}  
int sumNatural(int a)
{
    if(a == 1)
    {
        return 1;
    }
    else
    {
        return sumNatural(a-1)+a;
    }
}