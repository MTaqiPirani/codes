#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPrefix(stack <char> s,string infix)
{
    string prefix;
    reverse(infix.begin(),infix.end());

    for(int i=0; i<infix.length(); i++)
    {
        if(infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if(infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for(int j=0; j<infix.length(); j++)
    {
        if((infix[j] >= 'a' && infix[j] <= 'z') || (infix[j] >= 'A' && infix[j] <= 'Z'))
        {
            prefix += infix[j];
        }
        else if(infix[j] == '(')
        {
            s.push(infix[j]);
        }
        else if(infix[j] == ')')
        {
            while((!s.empty()) && (s.top() != '('))
            {
                prefix += s.top();
                s.pop();
            }
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else if(IsOperator(infix[j]))
        {
            if(s.empty())
            {
                s.push(infix[j]);
            }
            else
            {
                if(precedence(infix[j]) > precedence(s.top()))
                {
                    s.push(infix[j]);
                }
                else if(precedence(infix[j]) == precedence(s.top()) && (infix[j] == '^'))
                {
                    while((precedence(infix[j]) == precedence(s.top()) && (infix[j] == '^')))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[j]);
                }
                else if(precedence(infix[j]) == precedence(s.top()))
                {
                    s.push(infix[j]);
                }
                else
                {
                    while((!s.empty()) && (precedence(infix[j]) < precedence(s.top())))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[j]);
                }
            }

        }
        else
        {
            cout << "Is not a Infix Expression.";
        }
    }
    while(!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(),prefix.end());

    return prefix;
}

int main()
{
    string infix_exp, prefix_exp;
    cout << "Enter a infix expression: ";
    cin >> infix_exp;
    stack <char> stack;
    cout << "Infix Expression: " << infix_exp;
    prefix_exp = InfixToPrefix(stack , infix_exp);
    cout << endl << "Prefix Expression: " << prefix_exp;
}