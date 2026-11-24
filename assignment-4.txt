#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class tree
{
    node *root;

public:

    tree()
    {
        root = NULL;
    }

    void create(node *&temp)
    {
        int value;

        cout << "Enter node value(-1 for no node):";
        cin >> value;

        if (value == -1)
        {
            temp = NULL;
            return;
        }

        temp = new node;
        temp->data = value;

        cout << "Enter left child of " << value << endl;
        create(temp->left);

        cout << "Enter right child of " << value << endl;
        create(temp->right);
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void postorder(node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void displaypreorder()
    {
        cout << "\npreorder traversal : ";
        preorder(root);
    }

    void displayinorder()
    {
        cout << "\ninorder traversal : ";
        inorder(root);
    }

    void displaypostorder()
    {
        cout << "\npostorder traversal : ";
        postorder(root);
    }

    void createTree()
    {
        cout << "create binary tree\n";
        create(root);
    }
};

int main()
{
    tree t;

    t.createTree();

    t.displaypreorder();
    t.displayinorder();
    t.displaypostorder();

    return 0;
}
