#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    string bookID[n];
    cout << "Enter Book IDs:\n";

    for(int i=0; i<n; i++)
    {
        cout << "Book " << i+1 << ": ";
        cin >> bookID[i];
    }

    int found = 0;

    cout << "\nBooks borrowed more than once:\n";

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(bookID[i]==bookID[j])
            {
                cout << bookID[i] << endl;
                found = 1;
                break;
            }
        }
    }

    if(found==0)
    {
        cout << "No duplicate book IDs found.";
    }

    return 0;
}
