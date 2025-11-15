//Addition of Rational number using ADT
#include<iostream>
using namespace std;
class Rational{
private:
    int num;
    int deno;
public:
    Rational(int a, int b){
        num = a;
        deno = b;
        if(deno == 0)
        {
            cout<<"The input number is irrational."<<endl;
            exit(1);
        }
    }
    Rational(){
        num = 0;
        deno = 0;
    }
    void add(Rational a, Rational b)
    {
        if(a.deno == b.deno){
            num = a.num + b.num;
            deno = a.deno;
        }
        else{
            num = a.num * b.deno + b.num * a.deno;
            deno = a.deno * b.deno;
        }
        cout<<"Addition: "<<endl;
    }
    void reduce()
    {
        int cf;
        for(int i=1;i<=num;i++)
        {
            if(num%i==0 && deno%i==0){
                cf = i;
            }
        }
        num/=cf;
        deno/=cf;
    }
    void display(){
        cout<<num<<"/"<<deno<<endl;
    }
};
int main()
{
    Rational r1(1,3), r2(2,2),r;
    r1.display();
    r2.display();
    r.add(r1,r2);
    r.reduce();
    r.display();
    return 0;
}
