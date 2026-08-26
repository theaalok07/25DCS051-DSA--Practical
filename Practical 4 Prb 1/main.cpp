#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    int n;

    cout << "Enter number of patients: ";
    cin >> n;

    Node* head=NULL;
    Node* temp=NULL;

    for(int i=0; i<n; i++)
    {
        Node* newNode=new Node;

        cout << "Enter token number " << i+1 << ": ";
        cin >> newNode->data;

        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    int choice;
    int value;
    int position;

    cout << "\nInitial Queue: ";

    temp=head;

    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }

    cout << "\n";

    cout << "\n1. Add patient at front";
    cout << "\n2. Add patient at end";
    cout << "\n3. Add patient at specific position";
    cout << "\n4. Exit";

    cout << "\n\nEnter choice: ";
    cin >> choice;

    if(choice==1)
    {
        cout << "Enter token number: ";
        cin >> value;

        Node* newNode=new Node;

        newNode->data=value;
        newNode->next=head;
        head=newNode;
    }
    else if(choice==2)
    {
        cout << "Enter token number: ";
        cin >> value;

        Node* newNode=new Node;

        newNode->data=value;
        newNode->next=NULL;

        temp=head;

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
        }
    }
    else if(choice==3)
    {
        cout << "Enter token number: ";
        cin >> value;

        cout << "Enter position: ";
        cin >> position;

        if(position==1)
        {
            Node* newNode=new Node;

            newNode->data=value;
            newNode->next=head;
            head=newNode;
        }
        else
        {
            temp=head;

            for(int i=1; i<position-1 && temp!=NULL; i++)
            {
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout << "Invalid position.";
            }
            else
            {
                Node* newNode=new Node;

                newNode->data=value;
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
    }
    else
    {
        cout << "Invalid choice.";
    }

    cout << "\nFinal Queue: ";

    temp=head;

    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }

    cout << "\n";

    return 0;
}
