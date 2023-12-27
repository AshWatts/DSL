#include <iostream>
using namespace std;

int queue[5];

class Deque
{
	int front,rear;
	int size=5;
	public:
	Deque()
	{
		front=-1;
		rear=-1;
		for(int i=0;i<size;i++)
		{
			queue[i]=0;
		}
	}

	void insert_rear(int val)
	{
		if(rear!=size-1)
		{
			rear++;
			queue[rear]=val;
			cout<<"Inserted Value : "<<val<<endl<<endl;
		}
		else
		{
			cout<<"Queue is Full!"<<endl;
		}
	}

	void insert_front(int val)
	{
		if(front!=-1)
		{
			queue[front]=val;
			front--;
		}
		else
		{
			cout<<"Queue is Full!"<<endl;
		}
	}

	void del_front()
	{
		if(rear!=front)
		{
			front++;
			cout<<"Deleted Value : "<<queue[front]<<endl<<endl;
			queue[front]=0;
		}
		else
		{
			cout<<"Queue is Empty!"<<endl;
		}
	}

	void del_rear()
	{
		if(rear!=front)
		{
			cout<<"Deleted Value : "<<queue[rear]<<endl<<endl;
			queue[rear]=0;
			rear--;
		}
		else
		{
			cout<<"Queue is Empty!"<<endl;
		}
	}

	void display()
	{
		cout<<"Queue Contents : \n";

		if(front==rear)
		{
			cout<<"Empty!"<<endl;
		}

		else
		{
			for(int i=0;i<size;i++)
			{
				if(i==0)
				{
					cout<<"| ";
				}

				cout<<queue[i]<<" | ";
			}
			cout<<endl<<endl;
		}
	}
};

int main()
{
	Deque q;
	int ch;
	cout << "Double Ended Queue Operations" << endl;

	do
	{
		cout<<"Operations : \n";
		cout<<"1 - Add an element at rear\n";
		cout<<"2 - Add an element at front\n";
		cout<<"3 - Delete an element from front\n";
		cout<<"4 - Delete an element from rear\n";
		cout<<"5 - Display the Queue\n";
		cout<<"6 - Exit\n";
		cout<<"Enter your Choice : ";
		cin>>ch;
		cout<<endl;
		if(ch==1)
		{
			int v;
			cout<<"Enter the Value : ";
			cin>>v;
			q.insert_rear(v);
		}

		else if(ch==2)
		{
			int v;
			cout<<"Enter the Value : ";
			cin>>v;
			q.insert_front(v);
		}

		else if(ch==3)
		{
			q.del_front();
		}

		else if(ch==4)
		{
			q.del_rear();
		}

		else if(ch==5)
		{
			q.display();
		}

		else if(ch==6)
		{
			cout<<"Exiting the Program!";
		}

		else
		{
			cout<<"Enter a Valid Choice!\n\n";
		}
	}
	while(ch!=6);


	return 0;

}
