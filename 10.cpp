#include <bits/stdc++.h>

using namespace std;

// Function to check if the given character is an operator
bool isOperator(char c) 
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) 
{
  stack<char> s;
  string postfix;
  for (char c : infix) 
  {
    if (c == '(') 
    {
      s.push(c);
    } 
    else if (c == ')') 
    {
      while (!s.empty() && s.top() != '(') 
      {
        postfix += s.top();
        s.pop();
      }
      s.pop();
    } 
    else if (isOperator(c)) 
    {
      while (!s.empty() && s.top() != '(' && isOperator(c) <= isOperator(s.top())) 
      {
        postfix += s.top();
        s.pop();
      }
      s.push(c);
    } 
    else 
    {
      postfix += c;
    }
  }
  while (!s.empty()) 
  {
    postfix += s.top();
    s.pop();
  }
  return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) 
{
  stack<int> s;
  for (char c : postfix) 
  {
    if (isdigit(c)) 
    {
      s.push(c - '0');
    } 
    else if (isOperator(c)) 
    {
      int operand2 = s.top();
      s.pop();
      int operand1 = s.top();
      s.pop();
      int result = 0;
      switch (c) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          result = operand1 / operand2;
          break;
      }
      s.push(result);
    }
  }
  return s.top();
}

int main() 
{
  string infixExpression;
  cout << "Enter infix expression: ";
  cin >> infixExpression;

  // Convert infix expression to postfix expression
  string postfixExpression = infixToPostfix(infixExpression);

  // Evaluate postfix expression
  int result = evaluatePostfix(postfixExpression);

  // Print the result
  cout << "Result: " << result << endl;

  return 0;
}
