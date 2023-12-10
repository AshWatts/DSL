#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string exp) {
  stack<char> s;
  for (int i = 0; i < exp.length(); i++) {
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      s.push(exp[i]);
    } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      if (s.empty()) {
        return false;
      }
      char top = s.top();
      if ((exp[i] == ')' && top != '(') || (exp[i] == ']' && top != '[') || (exp[i] == '}' && top != '{')) {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}

int main() {
  string expression;
  cout << "Enter an expression: ";
  getline(cin, expression);
  if (isBalanced(expression)) {
    cout << "The expression is well parenthesized." << endl;
  } else {
    cout << "The expression is not well parenthesized." << endl;
  }
  return 0;
}
