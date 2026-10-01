//Doubly Circualr Linked List
#include <iostream>
using namespace std;

struct Node
{
    int student;
    Node* prev;
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
        newNode->prev=head;
        return;
    }

    Node* last=head->prev;

    newNode->next=head;
    newNode->prev=last;

    last->next=newNode;
    head->prev=newNode;

    head=newNode;
}

void insertAtPosition(Node*& head,int student,int position)
{
    if(position==1 || head==NULL)
    {
        insertBeginning(head,student);
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

    Node* newNode=new Node;
    newNode->student=student;

    newNode->next=temp->next;
    newNode->prev=temp;

    temp->next->prev=newNode;
    temp->next=newNode;
}

void deleteAtPosition(Node*& head,int position)
{
    if(head==NULL)
    {
        cout<<"Circle is empty."<<endl;
        return;
    }

    Node* temp=head;

    for(int i=1;i<position;i++)
    {
        temp=temp->next;

        if(temp==head)
        {
            cout<<"Invalid position."<<endl;
            return;
        }
    }

    if(temp->next==temp)
    {
        delete temp;
        head=NULL;
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    if(temp==head)
    {
        head=temp->next;
    }

    delete temp;
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
