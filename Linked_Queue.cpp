#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node 
{
    int data;
    Node* next;
};

// Queue class implementation
class Queue 
{
private:
    Node* front;
    Node* rear;

public:
    Queue() 
    {
        front = rear = nullptr;
    }

    void enqueue() 
    {
        int data;
        cout << "Enter data to enqueue: ";
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << data << " enqueued to queue\n";
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow\n";
            return -1;
        }

        int data = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) 
        {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    Queue q;
    char choice;

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case '1':
                q.enqueue();
                break;
            case '2':
                cout << q.dequeue() << " dequeued from queue\n";
                break;
            case '3':
                q.display();
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != '4');

    return 0;
}
