#include<iostream>
using namespace std;
class Natural{
private:
    int value;
public:
    Natural(){
        value = 0;
    }
    void set_value(int n){
        value = n;
    }
    void add_natural(Natural n){
        value += n.value;
    }
    int get_value(){
        return value;
    }
};
int main()
{
    Natural n[2];
    n[0].set_value(3);
    n[1].set_value(4);
    n[0].add_natural(n[1]);
    cout<<"Sum: "<<n[0].get_value();
    return 0;
}