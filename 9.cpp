#include<bits/stdc++.h>
using namespace std;

bool isexp(string e)
{
  stack <char> s;
  for(int i=0;i<e.length();i++)
  {
    if(e[i]=='(' || e[i]=='{' || e[i]=='[')
    {
      s.push(e[i]);
    }
    else if(e[i]==')' || e[i]=='}' || e[i]==']')
    {
      if(s.empty())
      {
        return false;
      }
      char top=s.top();
      if((e[i]==')' && top!='(') || (e[i]=='}' && top!='{') || (e[i]==']' && top!='['))
      {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}


int main()
{
  string exp;
  cout<<"Enter the Expression : ";
  cin>>exp;
  if(isexp(exp))
  {
    cout<<"Well Parenthesized";
  }
  else
  {
    cout<<"Not well Parenthesized";
  }
  return 0;
}