#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    char x;
    do
    {
        int n;
        cout<<"Enter element : ";
        cin>>n;
        s.push(n);
        cout<<"Do you want to add more elements?(y/n) : ";
        cin>>x;
    }while(x=='y');

    cout<<endl;

    
    char z;
    cout<<"Do you want to delete an element?(y/n) : ";
    cin>>z;
    if(z=='y')
    {
        do
        {
            int a;
            a=s.top();
            cout<<"Deleted element is : "<<a<<endl;
            s.pop();
            cout<<"Do you want to delete more elements?(y/n) : ";
            cin>>x;
        }while(x=='y');
    }
}