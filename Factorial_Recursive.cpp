#include<iostream>
using namespace std;


int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
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