
#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

void insert(int id)
{
    int index=id%SIZE;
    int jump=7-(id%7);
    int count=0;

    while(table[index]!=-1 && count<SIZE)
    {
        index=(index+jump)%SIZE;
        count++;
    }

    if(count==SIZE)
    {
        cout<<"Hash table is full. Cannot insert "<<id<<endl;
    }
    else
    {
        table[index]=id;
        cout<<"Student ID "<<id<<" inserted at slot "<<index<<endl;
    }
}

void display()
{
    cout<<"\nFinal hash table:"<<endl;

    for(int i=0;i<SIZE;i++)
    {
        if(table[i]==-1)
        {
            cout<<"Slot "<<i<<": Empty"<<endl;
        }
        else
        {
            cout<<"Slot "<<i<<": "<<table[i]<<endl;
        }
    }
}

int main()
{
    int n;
    int id;

    for(int i=0;i<SIZE;i++)
    {
        table[i]=-1;
    }

    cout<<"Enter number of students: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter student ID: ";
        cin>>id;
        insert(id);
    }

    display();

    return 0;
}
