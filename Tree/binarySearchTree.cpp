#include<iostream>
using namespace std;
class BST{
private:
    int data;
    BST *left, *right;
public:
    BST(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
    void insert(int value){
        if(value<data){
            if(left == nullptr)
                left = new BST(value);
            else
                left->insert(value);
        }
        else{
            if(right == nullptr)
                right = new BST(value);
            else
                right->insert(value);
        }
    }
    void inorder(){
        if(left != nullptr)
            left->inorder();
        cout<<data<<" ";
        if(right!=nullptr)
            right->inorder();
    }
    void preorder(){
        cout<<data<<" ";
        if(left != nullptr)
            left->preorder();
        if(right!=nullptr)
            right->preorder();
    }
    void postorder(){
        if(left != nullptr)
            left->postorder();
        if(right!=nullptr)
            right->postorder();
        cout<<data<<" ";
    }
    BST *findMin(){
        BST *current = this;
        while(current->left != nullptr)
            current = current->left;
        return current;
    }
    BST *deleteNode(int value){
        //Traversing left
        if(value<data){
            if(left != nullptr)
                left = left->deleteNode(value);
        }
        //Traversing right
        else if(value > data){
            if(right != nullptr)
                right = right->deleteNode(value);
        }
        //Value found
        else{
            // Case 2: Leaf node (no children)
            if(left == nullptr && right == nullptr){
                cout<<this->data<<" is deleted."<<endl;
                delete this;
                return nullptr;
            }
            //Case 2: one child (right only)
            else if(left == nullptr){
                BST *temp = right;
                cout<<this->data<<" is deleted."<<endl;
                delete this;
                return temp;
            }
            //Case 3: one child (left only)
            else if(right == nullptr){
                BST *temp = left;
                cout<<this->data<<" is deleted."<<endl;
                delete this;
                return temp;
            }
            //Case 4: Two children
            else{
                BST *successor = right->findMin();
                data = successor->data;
                right = right->deleteNode(successor->data);
            }
        }
        return this;
    }
};
int main(){
    BST* tree = new BST(10);
    tree->insert(5);
    tree->insert(50);
    tree->insert(2);
    tree->insert(7);
    tree->insert(8);
    tree->insert(30);
    tree->insert(87);
    tree->insert(29);
    tree->insert(43);
    tree->insert(67);
    tree->insert(69);

    cout<<"Inorder: ";
    tree->inorder();
    cout<<endl;

    cout<<"Preorder: ";
    tree->preorder();
    cout<<endl;

    cout<<"Postorder: ";
    tree->postorder();
    cout<<endl;

    // Deleting node with only left subtree
    tree = tree->deleteNode(87);

    // Deleting node with only right subtree
    tree = tree->deleteNode(7);

    // Deleting node with two subtrees
    tree = tree->deleteNode(30);

    // Deleting leaf node
    tree = tree->deleteNode(2);

    cout<<"Inorder: ";
    tree->inorder();
    cout<<endl;

    cout<<"Preorder: ";
    tree->preorder();
    cout<<endl;

    cout<<"Postorder: ";
    tree->postorder();
}




