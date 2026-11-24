#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class linkedlist
{
    private:
    Node *head;
    public:
    linkedlist()
    {
        head= NULL;
    }
    void createlist()
    {
        int n ,value;
        cout<<"\n enter number of nodes:";
        cin>>n;
        if(n<=0)
        {
            cout<<"invalid number of nodes.";
            return;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<"enter value"<<i<<":";
            cin>>value;
            insert(value);
        }
        cout<<"\nLinked list created.\n";
    }
    void insert(int value)
    {
        Node *newnode =new Node;
        newnode->data = value;
        newnode->next = NULL;
        if(head==NULL)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newnode;
    }
    void display()

    {
    if(head==NULL)
    {
        cout<<"\nLinkedlist is empty.\n";
        return;
    }
    Node *temp=head;
    cout<<"\nLinkedlist:";
    while(temp!=NULL)\
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    }
};
    int main()
    {
        linkedlist l;
        int value;
        {
            cout<<"enter first element:";
            cin>>value;
             l.createlist();
             l.insert(value);
             cout<<"linked list:";
             l.display();
             return 0;
        }
    }
