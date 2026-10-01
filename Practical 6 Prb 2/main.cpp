#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top=NULL;

void visit(string page)
{
    Node* newNode=new Node;

    newNode->page=page;
    newNode->next=top;

    top=newNode;

    cout<<"Visited: "<<page<<endl;
}

void back()
{
    if(top==NULL)
    {
        cout<<"No history left."<<endl;
    }
    else
    {
        Node* temp=top;

        cout<<"Going back from: "<<top->page<<endl;

        top=top->next;

        delete temp;
    }
}

void display()
{
    if(top==NULL)
    {
        cout<<"No history."<<endl;
        return;
    }

    cout<<"History: ";

    Node* temp=top;

    while(temp!=NULL)
    {
        cout<<temp->page<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main()
{
    int choice;
    string page;

    do
    {
        cout<<"\n1. Visit page"<<endl;
        cout<<"2. Back"<<endl;
        cout<<"3. Display history"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter page: ";
            cin>>page;

            visit(page);
            display();
        }
        else if(choice==2)
        {
            back();

            if(top!=NULL)
            {
                cout<<"Current page: "<<top->page<<endl;
            }
            else
            {
                cout<<"Current page: None"<<endl;
            }
        }
        else if(choice==3)
        {
            display();
        }

    }while(choice!=4);

    return 0;
}
