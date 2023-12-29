#include<iostream>
using namespace std;


int fact(int n)
{
    int a,b;
    if(n==0)
    {
        return 1;
    }
    a=n;
    b=fact(n-1);
    int f = a*b;
    return f;
}


int main()
{
    int m,n;
    cout<<"Enter number whose factorial is to be found : ";
    cin>>n;
    if(n<0)
    {
        cout<<"No factorial for negative numbers!";
        return 0;
    }
    m=fact(n);
    cout<<"Factorial : "<<m;
}