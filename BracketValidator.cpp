#include <iostream>
#include <stack>
using namespace std;

bool validateParanthesisBalanced(string expr){
  stack<char> vstack;
  char ch;

  // traversing the expression
  for(int iIndex = 0; iIndex < expr.length(); iIndex++){
    if(expr[iIndex] == '{' || expr[iIndex] == '[' || expr[iIndex] == '('){
      // push the element to stack
      vstack.push(expr[iIndex]);
      continue;
    }
    // if current character is not opening
    // bracket, then it must be closing. So stack
    // cannot be empty at this point.

    if(vstack.empty())
      return false;

    switch (expr[iIndex]){
      case ')':
          // Store the top element in a char
          ch = vstack.top();
          vstack.pop();
          if ( ch == '{' || ch == '[')
            return false;
          break;

      case '}':
          // Store the top element in a char
          ch = vstack.top();
          vstack.pop();
          if(ch == '[' || ch == '(')
            return false;
          break;
      case ']':
          // Store the top element in a char
          ch = vstack.top();
          vstack.pop();
          if(ch == '{' || ch == '(')
            return false;
          break;
    }
  }
  // check empty stack
  return (vstack.empty());
}

// Driver program to test above function
int main()
{
    string expr = "{()}[]";

    if (validateParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
