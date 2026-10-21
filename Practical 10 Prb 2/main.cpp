
#include <iostream>
using namespace std;

struct Node
{
    int code;
    Node* next;
};

Node* shelves[10];

void insert(int code)
{
    int index=code%10;

    Node* newNode=new Node;
    newNode->code=code;
    newNode->next=NULL;

    if(shelves[index]==NULL)
    {
        shelves[index]=newNode;
    }
    else
    {
        newNode->next=shelves[index];
        shelves[index]=newNode;
    }
}

void display()
{
    for(int i=0;i<10;i++)
    {
        cout<<"Shelf "<<i<<": ";

        Node* temp=shelves[i];

        if(temp==NULL)
        {
            cout<<"Empty";
        }

        while(temp!=NULL)
        {
            cout<<temp->code<<" -> ";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
    }
}

int main()
{
    int n;
    int code;

    for(int i=0;i<10;i++)
    {
        shelves[i]=NULL;
    }

    cout<<"Enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter book code: ";
        cin>>code;
        insert(code);
    }

    cout<<"\nFinal shelf contents:"<<endl;
    display();

    return 0;
}
