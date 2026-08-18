#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of colour codes: ";
    cin >> n;

    int colour[n];

    cout << "Enter colour codes (0, 1 or 2):\n";

    for(int i=0; i<n; i++) {
        cout << "Colour " << i+1 << ": ";
        cin >> colour[i];
    }

    int zero=0;
    int one=0;
    int two=0;

    for(int i=0; i<n; i++) {
        if(colour[i]==0) {
            zero++;
        }
        else if(colour[i]==1) {
            one++;
        }
        else if(colour[i]==2) {
            two++;
        }
    }

    int index=0;

    for(int i=0; i<zero; i++) {
        colour[index]=0;
        index++;
    }

    for(int i=0; i<one; i++) {
        colour[index]=1;
        index++;
    }

    for(int i=0; i<two; i++) {
        colour[index]=2;
        index++;
    }

    cout << "\nSorted colour codes: ";

    for(int i=0; i<n; i++) {
        cout << colour[i] << " ";
    }

    cout << "\n";

    return 0;
}
