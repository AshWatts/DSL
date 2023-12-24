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

    void calc(add p1, add p2)
    {
        node *t1, *t2, *t;
        t1=p1.head;
        t2=p2.head;
        float Coef;
        head=new node;

        if(head==NULL)
        {
            cout<<"Unable";
        }

        t=head;

        while(t1!=NULL && t2!=NULL)              
        {
            if(t1->e > t2->e)
            {
                t->e=t1->e;
                t->c=t1->c;
                t1=t1->next;
                t=t->next;
            }
            else if(t1->e < t2->e)
            {
                t->e=t2->e;
                t->c=t2->c;
                t2=t2->next;
                t=t->next;
            }
            else
            {
                Coef=t1->c+t2->c;
                head=attach(t1->e,Coef,head);
                t1=t1->next;
                t2=t2->next;
            }
        }
        while(t1!=NULL)
        {
            t->c=t1->c;
            t->e=t1->e;
            t=t->next;
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            t->c=t2->c;
            t->e=t2->e;
            t=t->next;
            t2=t2->next;
        }
    }

    void attach(int exp, float coef, node *temp)
    {
        
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