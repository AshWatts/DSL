// Job Queue


#include<bits/stdc++.h>
using namespace std;

int Queue[5];

class que
{
    int front,rear;

    int size=5;

public:

    que()
    {
        front=-1;
        rear=-1;
    }

    int insert(int val)
    {
        if(rear==4)
        {
            cout<<"Queue is Full"<<endl;
            return 0;
        }

        rear++;
        Queue[rear]=val;
        cout<<"Entered Value is "<<val<<endl;
    }

    int remove()
    {
        if(front==rear)
        {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }

        front++;
        cout<<"Deleted Value is "<<Queue[front]<<endl;
    }

    int display()
    {
        if(front==rear)
        {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }

        for(int i=front+1;i<=rear;i++)
        {
            cout<<Queue[i]<<"   ";
        }

        cout<<endl;
    }
};


int main()
{

    que q;
    int a;

    cout<<"Queue Operations : \n";
    cout<<"1. - Add an Element\n";
    cout<<"2. - Delete an Element\n";
    cout<<"3. - Display the Queue\n";
    cout<<"4. - Exit\n";

    do
    {
    cout<<"Choose an option : ";
    cin>>a;

    if(a==1)
    {
        int v;
        cout<<"Enter the element to be added : ";
        cin>>v;
        q.insert(v);
    }

    else if(a==2)
    {
        q.remove();
    }

    else if(a==3)
    {
        q.display();
    }

    else if(a==4)
    {
        cout<<"Exiting the Project!";
    }

    else
    {
        cout<<"Enter a Valid Choice!"<<endl;
    }

    }while(a!=4);
}