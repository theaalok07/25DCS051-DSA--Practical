#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top=-1;

void push(int tray)
{
    if(top==MAX-1)
    {
        cout<<"Error: Stack is full."<<endl;
    }
    else
    {
        top++;
        stack[top]=tray;
        cout<<"Tray placed."<<endl;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Error: Stack is empty."<<endl;
    }
    else
    {
        cout<<"Tray taken: "<<stack[top]<<endl;
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        cout<<"Stack is empty."<<endl;
        return;
    }

    cout<<"Current stack: ";

    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int choice;
    int tray;

    do
    {
        cout<<"\n1. Place tray"<<endl;
        cout<<"2. Take tray"<<endl;
        cout<<"3. Display stack"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter tray number: ";
            cin>>tray;

            push(tray);
            display();
        }
        else if(choice==2)
        {
            pop();
            display();
        }
        else if(choice==3)
        {
            display();
        }

    }while(choice!=4);

    return 0;
}
