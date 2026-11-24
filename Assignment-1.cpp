#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class Stack
{
    string books[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push - Return Book
    void push(string book)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow! Library stack is full.\n";
            return;
        }

        books[++top] = book;
        cout << "Book returned successfully.\n";
    }

    // Pop - Arrange Book
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! No books in stack.\n";
            return;
        }

        cout << "Arranged/Removed Book: " << books[top] << endl;
        top--;
    }

    // Peek - Top Book
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top Book: " << books[top] << endl;
    }

    // Display Stack
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nBooks in Stack (Top to Bottom):\n";

        for (int i = top; i >= 0; i--)
        {
            cout << books[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice;
    string book;

    do
    {
        cout << "\n===== Library Stack Menu =====\n";
        cout << "1. Return Book (Push)\n";
        cout << "2. Arrange Book (Pop)\n";
        cout << "3. Top Book (Peek)\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book Name: ";

            // Clear the newline character left in the buffer by cin >> choice
            cin.ignore();

            getline(cin, book);

            s.push(book);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
