#include <iostream>
#include<math.h>
using namespace std;
void towerOfHanoi(int,char,char,char);
int main()
{
    int n, steps;
    cout << "Enter number of disks: ";
    cin >> n;
    cout<<"A = source, B = auxiliary, C = destination"<<endl;
    towerOfHanoi(n, 'A', 'B', 'C');
    steps = pow(2,n) - 1;
    cout<<endl<<"Number of steps:"<<steps;
    return 0;
}
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{   
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}
