#include <iostream>

using namespace std;

const int MAX_SIZE = 5; // Maximum size of the queue

class CircularQueue 
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    bool isFull() 
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue()
    {
        if (isFull()) 
        {
            cout << "Queue Overflow\n";
            return;
        }
        int data;
        cout << "Enter data to enqueue: ";
        cin >> data;
        if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = data;
        cout << data << " enqueued to queue\n";
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        int data = arr[front];
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX_SIZE;
        }
        return data;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) 
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    void performOperations() 
    {
        char choice;
        do 
        {
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
                    enqueue();
                    break;
                case '2':
                    cout << dequeue() << " dequeued from queue\n";
                    break;
                case '3':
                    display();
                    break;
                case '4':
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } while (choice != '4');
    }
};

int main()
 {
    CircularQueue q;
    q.performOperations();
    return 0;
}
