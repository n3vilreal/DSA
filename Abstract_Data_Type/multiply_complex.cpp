//Multiplication of Complex number using ADT
#include<iostream>
using namespace std;
class Complex{
private:
    int a;
    int b;
public:
    Complex(int m, int n){
        a = m;
        b = n;
    }
    Complex(){
        a = 0;
        b = 0;
    }
    void multiply(Complex c1, Complex c2)
    {
        a = c1.a*c2.a - c1.b*c2.b;
        b = c1.a*c2.b + c2.a*c1.b;
        cout<<"Multiplication: ";
    }
    void display(){
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};
int main()
{
    Complex C1(1,3), C2(2,2),C;
    C1.display();
    C2.display();
    C.multiply(C1,C2);
    C.display();
    return 0;
}