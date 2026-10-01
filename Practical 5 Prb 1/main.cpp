#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

void display(Node* head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->song<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int countSongs(Node* head)
{
    int count=0;
    Node* temp=head;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;
}

void addBeginning(Node*& head,string song)
{
    Node* newNode=new Node;
    newNode->song=song;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL)
    {
        head->prev=newNode;
    }

    head=newNode;
}

void addEnd(Node*& head,string song)
{
    Node* newNode=new Node;
    newNode->song=song;
    newNode->next=NULL;

    if(head==NULL)
    {
        newNode->prev=NULL;
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
}

void insertAfter(Node* head,string currentSong,string song)
{
    Node* temp=head;

    while(temp!=NULL && temp->song!=currentSong)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Song not found."<<endl;
        return;
    }

    Node* newNode=new Node;
    newNode->song=song;

    newNode->prev=temp;
    newNode->next=temp->next;

    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }

    temp->next=newNode;
}

void removeFirst(Node*& head)
{
    if(head==NULL)
    {
        cout<<"Playlist is empty."<<endl;
        return;
    }

    Node* temp=head;
    head=head->next;

    if(head!=NULL)
    {
        head->prev=NULL;
    }

    delete temp;
}

int main()
{
    Node* head=NULL;
    int choice;
    string song,currentSong;

    do
    {
        cout<<"\n1. Add at beginning"<<endl;
        cout<<"2. Add at end"<<endl;
        cout<<"3. Insert after song"<<endl;
        cout<<"4. Remove first song"<<endl;
        cout<<"5. Count songs"<<endl;
        cout<<"6. Display playlist"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter song: ";
            cin>>song;

            addBeginning(head,song);
            display(head);
        }
        else if(choice==2)
        {
            cout<<"Enter song: ";
            cin>>song;

            addEnd(head,song);
            display(head);
        }
        else if(choice==3)
        {
            cout<<"Enter current song: ";
            cin>>currentSong;

            cout<<"Enter new song: ";
            cin>>song;

            insertAfter(head,currentSong,song);
            display(head);
        }
        else if(choice==4)
        {
            removeFirst(head);
            display(head);
        }
        else if(choice==5)
        {
            cout<<"Number of songs: "<<countSongs(head)<<endl;
        }
        else if(choice==6)
        {
            display(head);
        }

    }while(choice!=7);

    return 0;
}
