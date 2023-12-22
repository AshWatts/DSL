#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node *prev, *next;
};

class dll
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
            New->prev=NULL;
            
            if(flag==true)
            {
                head=New;
                temp=head;
                flag=false;
            }

            else
            {
                temp->next=New;
                New->prev=temp;
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

    void insert_at_end()
    {

    }

    void insert_at_head()
    {

    }

    void insert_at_position()
    {

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
                if(head->next==NULL && head->prev==NULL)
                {
                    head=NULL;
                }
                else
                {
                    head=temp->next;
                    head->prev=NULL;
                }
            }
            else
            {
                prev=temp->prev;
                if(temp->next!=NULL)
                {
                    (temp->next)->prev=prev;
                    prev->next=temp->next;
                }
            }
            delete temp;
            cout<<"Element deleted!\n";
        }
    }
};


int main()
{
    dll d;
    d.create();
    // d.insert_at_head();
    // d.insert_at_position();
    // d.insert_at_end();
    d.show();
    d.del();
    d.show();   
}