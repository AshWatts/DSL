// Double Ended Queue


#include<bits/stdc++.h>
using namespace std;

int que[5];

class Deque
{
    int size=5;
    int front,rear;

public:

    Deque()
    {
        front=-1;
        rear=-1;
    }

    
};




int main()
{
    Deque d;
    int a;

    cout<<"Queue Operations : \n";

    do
    {
    cout<<"1. - Add an Element at Front\n";
    cout<<"2. - Add an Element at Rear\n";
    cout<<"3. - Delete an Element from Front\n";
    cout<<"4. - Delete an Element from Rear\n";
    cout<<"5. - Display the Queue\n";
    cout<<"6. - Exit\n";


    }while(a!=6);
}