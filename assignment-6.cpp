#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class BST
{
    Node* root = nullptr;

    Node* insert(Node* node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            cout << "Duplicate Employee ID ignored.\n";

        return node;
    }

    Node* copyTree(Node* node)
    {
        if (!node)
            return nullptr;

        Node* result = new Node(node->data);

        result->left = copyTree(node->left);
        result->right = copyTree(node->right);

        return result;
    }

    void clear(Node* node)
    {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    int height(Node* node) const
    {
        if (!node)
            return -1;

        return 1 + max(height(node->left), height(node->right));
    }

    void leaves(Node* node) const
    {
        if (!node)
            return;

        if (!node->left && !node->right)
        {
            cout << node->data << " ";
            return;
        }

        leaves(node->left);
        leaves(node->right);
    }

    void levelOrder(Node* node) const
    {
        if (!node)
        {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        cout << "\n";
    }

public:

    ~BST()
    {
        clear(root);
    }

    void add(int x)
    {
        root = insert(root, x);
    }

    void display() const
    {
        levelOrder(root);
    }

    void makeCopy(BST& destination) const
    {
        if (&destination == this)
            return;

        destination.clear(destination.root);
        destination.root = copyTree(root);
    }

    void showHeight() const
    {
        cout << "Height of BST: " << height(root) << "\n";
    }

    void showLeaves() const
    {
        if (!root)
        {
            cout << "Tree is empty.\n";
            return;
        }

        cout << "Leaf nodes: ";
        leaves(root);
        cout << "\n";
    }
};

int main()
{
    BST original, copied;
    int choice, n, id;

    do
    {
        cout << "\n===== EMPLOYEE DATABASE BST =====\n"
             << "1. Insert Employee IDs\n"
             << "2. Display Original BST (Level Order)\n"
             << "3. Copy BST\n"
             << "4. Display Copied BST (Level Order)\n"
             << "5. Find Height of BST\n"
             << "6. Display Leaf Nodes\n"
             << "7. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice))
            return 0;

        switch (choice)
        {
        case 1:
            cout << "Enter number of employee IDs: ";
            cin >> n;

            if (n < 0)
            {
                cout << "Invalid count.\n";
                break;
            }

            for (int i = 0; i < n; ++i)
            {
                cout << "Enter employee ID: ";
                cin >> id;

                original.add(id);
            }

            break;

        case 2:
            cout << "Original BST: ";
            original.display();
            break;

        case 3:
            original.makeCopy(copied);
            cout << "BST copied successfully.\n";
            break;

        case 4:
            cout << "Copied BST: ";
            copied.display();
            break;

        case 5:
            original.showHeight();
            break;

        case 6:
            original.showLeaves();
            break;

        case 7:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
