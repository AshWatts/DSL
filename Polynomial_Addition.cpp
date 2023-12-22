#include<iostream>
using namespace std;


class node
{
    public:
    float c;
    int e;
    node *next;
};

class add
{
    private:
    node *head;

    public:
    void create()
    {
        node *temp, *New;
        float coef;
        int exp;
        char ans;
        bool flag=true;

        do
        {
            cout<<"Enter coeffecient and exponent : ";
            cin>>coef>>exp;

            New = new node;

            if(New==NULL)
            {
                cout<<"Unable to create";
            }
            New->e=exp;
            New->c=coef;
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
        while(temp->next!=NULL)
        {
            cout<<temp->c<<"x^"<<temp->e<<" + ";
            temp=temp->next;
        }
        cout<<temp->c<<"x^"<<temp->e;
        cout<<endl;
        return 0;
    }

    int calc(add p1, add p2)
    {
        node *t1, *t2, *temp;
        t1=p1.head;
        t2=p2.head;
        head=new node;

        if(head==NULL)
        {
            cout<<"Unable";
        }

        temp=head;

        while(t1!=NULL && t2!=NULL)
        {
            
        }
    }

};


int main()
{
    add a,b,c;
    cout<<"Enter 1st Polynomial : \n";
    a.create();
    cout<<endl;
    cout<<"Enter 2nd Polynomial : \n";
    b.create();
    cout<<endl;
    cout<<"1st Polynomial : ";
    a.show();
    cout<<endl;
    cout<<"2nd Polynomial : ";
    b.show();
    cout<<endl;
    c.calc(a,b);
    cout<<"Addition is : ";
    c.show();
    return 0;
}