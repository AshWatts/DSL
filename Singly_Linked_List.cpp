#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class sll
{
    private:
    node *head;

    public:

    void create()
    {
        node *temp, *New;
        int val;
        char ans;
        bool flag=true;

        do
        {
            cout<<"Enter data : ";
            cin>>val;

            New = new node;

            if(New==NULL)
            {
                cout<<"Unable to create";
            }
            New->data=val;
            New->next=NULL;
            
            if(flag==true)
            {
                head=New;
                temp=head;
                flag=false;
            }

            else
            {
                temp->next=New;
                temp=New;
            }

            cout<<"Do you want to continue(y/n)? ";
            cin>>ans;
        }while(ans=='y' || ans=='Y');
    }

    int show()
    {
        node *temp;
        temp=head;
        if(temp==NULL)
        {
            cout<<"List is empty!";
            return 0;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<"   ";
            temp=temp->next;
        }
        cout<<endl;
        return 0;
    }

    void insert_at_head()
    {
        node *temp, *New;
        New=new node;
        cout<<"Enter element to be added at head : ";
        cin>>New->data;
        if(head==NULL)
        {
            head=New;
        }
        else
        {
            temp=head;
            head=New;
            New->next=temp;
        }
    }

    void insert_at_position()
    {
        int k,x;
        node *temp, *New;
        New=new node;
        cout<<"Enter element to be added : ";
        cin>>x;
        New->data=x;

        if(head==NULL)
        {
            head=New;
        }
        else
        {
            cout<<"Enter element after which "<<x<<" is to be added : ";
            cin>>k;
            temp=head;
            do
            {
                if(temp->data==k)
                {
                    New->next=temp->next;
                    temp->next=New;
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }while(temp!=NULL);
        }
    }

    void insert_at_end()
    {
        node *temp, *New;
        New=new node;

        cout<<"Enter element to be added at end : ";
        cin>>New->data;

        if(head==NULL)
        {
            head=New;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=New;
            New->next=NULL;
        }
    }

    void del()
    {
        int k;
        node *temp, *prev;

        cout<<"Enter element to be deleted : ";
        cin>>k;

        temp=head;

        while(temp!=NULL)
        {
            if(temp->data==k)
            {
                break;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }
        if(temp==NULL)
        {
            cout<<"Element absent!";
        }
        else
        {
            if(temp==head)
            {
                head=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }
            delete temp;
            cout<<"Element deleted!\n";
        }
    }

    int find()
    {
        node *temp;
        int k;
        bool find=false;

        cout<<"Enter element to be searched for : ";
        cin>>k;

        temp=head;

        if(temp==NULL)
        {
            cout<<"List is empty";
        }
        while(temp!=NULL && find==false)
        {
            if(temp->data==k)
            {
                find=true;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(find==false)
        {
            cout<<"Element is absent!";
        }
        else
        {
            cout<<"Found!";
        }
    }
};



int main()
{
    sll s;
    s.create();
    s.insert_at_head();
    s.insert_at_position();
    s.insert_at_end();
    s.show();
    s.del();
    s.show();
    s.find();
}