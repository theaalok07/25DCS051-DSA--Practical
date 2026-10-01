#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char stack[100];
int top=-1;

void push(char value)
{
    top++;
    stack[top]=value;
}

char pop()
{
    char value=stack[top];
    top--;
    return value;
}

char peek()
{
    return stack[top];
}

int precedence(char op)
{
    if(op=='+' || op=='-')
    {
        return 1;
    }
    else if(op=='*' || op=='/')
    {
        return 2;
    }
    else if(op=='^')
    {
        return 3;
    }

    return 0;
}

string infixToPostfix(string infix)
{
    string postfix="";

    for(int i=0;i<infix.length();i++)
    {
        char ch=infix[i];

        if(isdigit(ch))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=-1 && peek()!='(')
            {
                postfix+=pop();
            }

            pop();
        }
        else
        {
            while(top!=-1 && precedence(peek())>=precedence(ch))
            {
                postfix+=pop();
            }

            push(ch);
        }
    }

    while(top!=-1)
    {
        postfix+=pop();
    }

    return postfix;
}

int calculate(int a,int b,char op)
{
    if(op=='+')
    {
        return a+b;
    }
    else if(op=='-')
    {
        return a-b;
    }
    else if(op=='*')
    {
        return a*b;
    }
    else if(op=='/')
    {
        return a/b;
    }

    return 0;
}

int evaluatePostfix(string postfix)
{
    int values[100];
    int valueTop=-1;

    for(int i=0;i<postfix.length();i++)
    {
        char ch=postfix[i];

        if(isdigit(ch))
        {
            valueTop++;
            values[valueTop]=ch-'0';
        }
        else
        {
            int b=values[valueTop];
            valueTop--;

            int a=values[valueTop];
            valueTop--;

            int result=calculate(a,b,ch);

            valueTop++;
            values[valueTop]=result;
        }
    }

    return values[valueTop];
}

int main()
{
    string infix;

    cout<<"Enter infix expression: ";
    cin>>infix;

    string postfix=infixToPostfix(infix);

    cout<<"Postfix expression: "<<postfix<<endl;
    cout<<"Result: "<<evaluatePostfix(postfix)<<endl;

    return 0;
}
