#include<iostream>
using namespace std;


int fib(int n)
{
    if(n<=1)
    {
        if(n==0)
        {
            return 0;
        }
        return n;
    }
    return fib(n-1)+fib(n-2);
}


int main()
{
    int m,n;
    cout<<"Enter position of fibonacci element to be found : ";
    cin>>n;
    m=fib(n);
    cout<<"Element : "<<m;
}