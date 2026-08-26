#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void reversePrint(Node* temp)
{
    if(temp==NULL)
    {
        return;
    }

    reversePrint(temp->next);
    cout << temp->data << " ";
}

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

    int value;

    cout << "\nEnter token number to delete: ";
    cin >> value;

    if(head==NULL)
    {
        cout << "Queue is empty.";
    }
    else if(head->data==value)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        temp=head;

        while(temp->next!=NULL && temp->next->data!=value)
        {
            temp=temp->next;
        }

        if(temp->next==NULL)
        {
            cout << "Token not found.";
        }
        else
        {
            Node* deleteNode=temp->next;
            temp->next=deleteNode->next;
            delete deleteNode;
        }
    }

    cout << "\n\nForward Queue: ";

    temp=head;

    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }

    cout << "\n\nReverse Queue: ";

    reversePrint(head);

    cout << "\n";

    return 0;
}
