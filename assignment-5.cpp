#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int rollNo;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        Node *newnode = new Node;
        newnode->rollNo = value;
        newnode->left = NULL;
        newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
            return;
        }

        Node *temp = root;
        Node *parent = NULL;

        while (temp != NULL)
        {
            parent = temp;

            if (value < temp->rollNo)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (value < parent->rollNo)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    void inorder()
    {
        if (root == NULL)
        {
            cout << "\nBST is empty.\n";
            return;
        }

        stack<Node*> s;
        Node *temp = root;

        cout << "\nInorder: ";

        while (temp != NULL || !s.empty())
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            cout << temp->rollNo << " ";

            temp = temp->right;
        }

        cout << endl;
    }

    void preorder()
    {
        if (root == NULL)
        {
            cout << "\nBST is empty.\n";
            return;
        }

        stack<Node*> s;
        s.push(root);

        cout << "\nPreorder: ";

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();

            cout << temp->rollNo << " ";

            if (temp->right != NULL)
                s.push(temp->right);

            if (temp->left != NULL)
                s.push(temp->left);
        }

        cout << endl;
    }
};

int main()
{
    BST tree;
    int n, value;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter roll numbers:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    tree.inorder();
    tree.preorder();

    return 0;
}
