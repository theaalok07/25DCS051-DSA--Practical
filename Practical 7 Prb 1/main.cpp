
#include <iostream>
using namespace std;
#define MAX 5

int tokenQueue[MAX];
int front=-1;
int rear=-1;

void join(int token)
{
    if((rear+1)%MAX==front)
    {
        cout<<"Error: Queue is full."<<endl;
    }
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%MAX;
        }

        tokenQueue[rear]=token;
        cout<<"Token issued: "<<token<<endl;
    }

    if(front==-1)
    {
        cout<<"Front token: None"<<endl;
    }
    else
    {
        cout<<"Front token: "<<tokenQueue[front]<<endl;
    }
}

void serve()
{
    if(front==-1)
    {
        cout<<"Error: Queue is empty."<<endl;
    }
    else
    {
        cout<<"Token served: "<<tokenQueue[front]<<endl;

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }

    if(front==-1)
    {
        cout<<"Front token: None"<<endl;
    }
    else
    {
        cout<<"Front token: "<<tokenQueue[front]<<endl;
    }
}

int main()
{
    int choice;
    int token;

    do
    {
        cout<<"\n1. Join"<<endl;
        cout<<"2. Serve"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter token number: ";
            cin>>token;
            join(token);
        }
        else if(choice==2)
        {
            serve();
        }
        else if(choice!=3)
        {
            cout<<"Invalid choice."<<endl;
        }

    }while(choice!=3);

    return 0;
}
