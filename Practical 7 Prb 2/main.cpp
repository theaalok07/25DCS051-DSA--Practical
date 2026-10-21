
#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node* next;
};

Node* front=NULL;
Node* rear=NULL;

void arrive(int patient)
{
    Node* newNode=new Node;
    newNode->patient=patient;
    newNode->next=NULL;

    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }

    cout<<"Patient arrived: "<<patient<<endl;
    cout<<"Front patient: "<<front->patient<<endl;
}

void attend()
{
    if(front==NULL)
    {
        cout<<"Error: No patients waiting."<<endl;
        cout<<"Front patient: None"<<endl;
    }
    else
    {
        Node* temp=front;
        cout<<"Patient attended: "<<front->patient<<endl;
        front=front->next;

        if(front==NULL)
        {
            rear=NULL;
        }

        delete temp;

        if(front==NULL)
        {
            cout<<"Front patient: None"<<endl;
        }
        else
        {
            cout<<"Front patient: "<<front->patient<<endl;
        }
    }
}

int main()
{
    int choice;
    int patient;

    do
    {
        cout<<"\n1. Arrive"<<endl;
        cout<<"2. Attend"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter patient number: ";
            cin>>patient;
            arrive(patient);
        }
        else if(choice==2)
        {
            attend();
        }
        else if(choice!=3)
        {
            cout<<"Invalid choice."<<endl;
        }

    }while(choice!=3);

    return 0;
}

