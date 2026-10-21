
#include <iostream>
using namespace std;

int main()
{
    int slots[10];
    int n;
    int reg;
    int index;
    int count;

    for(int i=0;i<10;i++)
    {
        slots[i]=-1;
    }

    cout<<"Enter number of vehicles: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter registration number: ";
        cin>>reg;

        index=reg%10;
        count=0;

        while(slots[index]!=-1 && count<10)
        {
            index=(index+1)%10;
            count++;
        }

        if(count==10)
        {
            cout<<"Parking lot is full. Vehicle "<<reg<<" cannot be parked."<<endl;
        }
        else
        {
            slots[index]=reg;
            cout<<"Vehicle "<<reg<<" parked at slot "<<index<<endl;
        }
    }

    cout<<"\nFinal parking slots:"<<endl;

    for(int i=0;i<10;i++)
    {
        if(slots[i]==-1)
        {
            cout<<"Slot "<<i<<": Empty"<<endl;
        }
        else
        {
            cout<<"Slot "<<i<<": "<<slots[i]<<endl;
        }
    }

    return 0;
}
