#include<iostream>
#include<stack>

using namespace std;

bool IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precidence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(stack <char> s, string infix)
{
    string postfix;
    for(int i=0; i<infix.length(); i++)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while((!s.empty()) && (s.top()!='('))
            {
                postfix += s.top();
                s.pop();
            }
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else if(IsOperator(infix[i]))
        {
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else if(precidence(infix[i]) > precidence(s.top()))
            {
                s.push(infix[i]);
            }
            else if(precidence(infix[i]) == precidence(s.top()))
            {
                s.push(infix[i]);
            }
            else
            {
                while((!s.empty()) && (precidence(infix[i]) <= precidence(s.top())))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
        {
            cout << "Is not an infix expression.";
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix_exp, postfix_exp;
    stack <char> stack;
    cout << "Enter a Infix Expression: ";
    cin >> infix_exp;
    cout << endl;
    cout << "Infix Expression: " << infix_exp;
    postfix_exp = InfixToPostfix(stack , infix_exp);
    cout << endl;
    cout << "Postfix Expression: " << postfix_exp;
}