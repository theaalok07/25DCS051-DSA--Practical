#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    int marks[n];

    cout << "Enter marks:\n";

    for(int i=0; i<n; i++) {
        cout << "Student " << i+1 << ": ";
        cin >> marks[i];
    }

    int bubble[n];
    int selection[n];
    int insertion[n];

    for(int i=0; i<n; i++) {
        bubble[i]=marks[i];
        selection[i]=marks[i];
        insertion[i]=marks[i];
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(bubble[j]>bubble[j+1]) {
                int temp=bubble[j];
                bubble[j]=bubble[j+1];
                bubble[j+1]=temp;
            }
        }
    }

    for(int i=0; i<n-1; i++) {
        int minIndex=i;

        for(int j=i+1; j<n; j++) {
            if(selection[j]<selection[minIndex]) {
                minIndex=j;
            }
        }

        int temp=selection[i];
        selection[i]=selection[minIndex];
        selection[minIndex]=temp;
    }

    for(int i=1; i<n; i++) {
        int temp=insertion[i];
        int j=i-1;

        while(j>=0 && insertion[j]>temp) {
            insertion[j+1]=insertion[j];
            j--;
        }

        insertion[j+1]=temp;
    }

    cout << "\nBubble Sort: ";
    for(int i=0; i<n; i++) {
        cout << bubble[i] << " ";
    }

    cout << "\nSelection Sort: ";
    for(int i=0; i<n; i++) {
        cout << selection[i] << " ";
    }

    cout << "\nInsertion Sort: ";
    for(int i=0; i<n; i++) {
        cout << insertion[i] << " ";
    }

    cout << "\n";

    return 0;
}
