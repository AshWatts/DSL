#include <iostream>
#include<string.h>
using namespace std;

class PriorityQueue
{
	char cust_name[10];
	int priority;
	int front,rear,size;
public:
	PriorityQueue(){
		front=-1;
		rear=-1;
		size=5;
	}

	void enqueue();
	void display();
	void sort();
	void dequeue();

}Queue[5];

void PriorityQueue::enqueue(){
	rear++;
	cout<<"Enter the name: ";
    cin>>Queue[rear].cust_name;
    cout<<"Enter the priority: ";
	cin>>Queue[rear].priority;
}

void PriorityQueue::display(){
	for(int i=0; i<size;i++){
		cout<<Queue[i].cust_name<<" - "<<Queue[i].priority<<endl;
	}
}

void PriorityQueue::sort()
{
    char tempn[10];
    int temp;
    cout<<"NAME"<<"   "<<"PRIORITY"<<endl;
	for(int i=0;i<size;i++)
    {
	        for(int j=0;j<i;j++)
            {
	            if(Queue[j].priority>Queue[j+1].priority)
                {
	            	//swap elements
	            	strcpy(tempn,Queue[j].cust_name);
	                temp=Queue[j].priority;

	                strcpy(Queue[j].cust_name,Queue[j+1].cust_name);
	                Queue[j].priority=Queue[j+1].priority;

	                strcpy(Queue[j].cust_name,tempn);
	                Queue[j+1].priority=temp;
	            }
	        }
	}
}

void PriorityQueue::dequeue()
{
	front++;
	cout<<"Serving customer : "<<Queue[front].cust_name<<"("<<Queue[front].priority<<")";
}

int main() 
{
	PriorityQueue q;

	cout<<"PRIORITY QUEUE"<<endl;
	q.enqueue();
	q.enqueue();
	q.enqueue();
	q.enqueue();
	q.enqueue();
	cout<<endl;

	q.display();
	cout<<endl;

	cout<<"SORTED QUEUE"<<endl;
	q.sort();
	q.display();
	cout<<endl;

	q.dequeue();

	return 0;
}