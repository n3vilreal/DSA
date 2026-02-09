// hashing
#define Table_size 10
#include<iostream>
using namespace std;
class Hashtable
{
    int table[Table_size];
    bool occupied[Table_size];

public:
    Hashtable()
    {
        for(int i=0; i<Table_size; i++){
            table[i]=-1;
            occupied[i]=false;
        }
    }
    int hashfunction(int key){
        return key% Table_size;

    }
    void _insert(int key)
{
    int index = hashfunction(key);
    int originalIndex = index;

    while (occupied[index])
    {
        index = (index + 1) % Table_size;

        if (index == originalIndex)
        {
            cout << "Hash table full" << endl;
            return;
        }
    }

    table[index] = key;
    occupied[index] = true;
    cout << "Key: " << key << " inserted at index " << index << endl;
}

    void display()
    {
        cout<<"Hash table: "<<endl;
        for(int i=0; i<Table_size; i++)
        {
            cout<< table[i]<<" ";
        }
    }
};

int main()
{
    Hashtable ht;

    int keys[] = {23,12,45,21,89,34,56,78,90,11};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i=0; i<n; i++){
        ht._insert(keys[i]);
    }
    ht.display();

    return 0;
}