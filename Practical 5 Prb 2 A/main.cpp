//Singly Circular Linked List
#include <iostream>
using namespace std;

struct Node
{
    int student;
    Node* next;
};

void display(Node* head)
{
    if(head==NULL)
    {
        cout<<"Circle is empty."<<endl;
        return;
    }

    Node* temp=head;

    do
    {
        cout<<temp->student<<" ";
        temp=temp->next;
    }while(temp!=head);

    cout<<endl;
}

void insertBeginning(Node*& head,int student)
{
    Node* newNode=new Node;
    newNode->student=student;

    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
        return;
    }

    Node* temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    newNode->next=head;
    temp->next=newNode;
    head=newNode;
}

void insertAtPosition(Node*& head,int student,int position)
{
    if(position==1 || head==NULL)
    {
        insertBeginning(head,student);
        return;
    }

    Node* newNode=new Node;
    newNode->student=student;

    Node* temp=head;

    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;

        if(temp==head)
        {
            cout<<"Invalid position."<<endl;
            delete newNode;
            return;
        }
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteAtPosition(Node*& head,int position)
{
    if(head==NULL)
    {
        cout<<"Circle is empty."<<endl;
        return;
    }

    if(position==1)
    {
        if(head->next==head)
        {
            delete head;
            head=NULL;
            return;
        }

        Node* temp=head;
        Node* last=head;

        while(last->next!=head)
        {
            last=last->next;
        }

        head=head->next;
        last->next=head;

        delete temp;
        return;
    }

    Node* temp=head;

    for(int i=1;i<position-1;i++)
    {
        temp=temp->next;

        if(temp==head)
        {
            cout<<"Invalid position."<<endl;
            return;
        }
    }

    Node* deleteNode=temp->next;

    if(deleteNode==head)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    temp->next=deleteNode->next;
    delete deleteNode;
}

void passToken(Node* head,int times)
{
    if(head==NULL)
    {
        cout<<"Circle is empty."<<endl;
        return;
    }

    Node* temp=head;

    for(int i=0;i<times;i++)
    {
        temp=temp->next;
    }

    cout<<"Token is at student: "<<temp->student<<endl;
}

int main()
{
    Node* head=NULL;
    int choice;
    int student,position,times;

    do
    {
        cout<<"\n1. Join student"<<endl;
        cout<<"2. Leave student"<<endl;
        cout<<"3. Display circle"<<endl;
        cout<<"4. Pass token"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter student: ";
            cin>>student;

            cout<<"Enter position: ";
            cin>>position;

            insertAtPosition(head,student,position);
            display(head);
        }
        else if(choice==2)
        {
            cout<<"Enter position: ";
            cin>>position;

            deleteAtPosition(head,position);
            display(head);
        }
        else if(choice==3)
        {
            display(head);
        }
        else if(choice==4)
        {
            cout<<"Enter number of passes: ";
            cin>>times;

            passToken(head,times);
        }

    }while(choice!=5);

    return 0;
}
