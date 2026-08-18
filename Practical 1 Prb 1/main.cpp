#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    
    cout << "Enter number of item: ";
    cin >> n;
    
    cout << "\n";
    
    string items[n];
    
    for (int i=0; i<n; i++) {
        cout << "Enter item " << i+1 << ": ";
        cin >> items[i];
    }
    
    cout << "\n";
    
    cout << "Items: ";
    for (int i=0; i<n; i++) {
        cout << items[i] << " ";
    }
    
    cout << "\n";
    
    int h;
    
    cout << "\nEnter number of hours: ";
    cin >> h;
    
    for (int i=0; i<h; i++) {
        string temp = items[0];
        for (int j=n; j>=0; j--) {
            items[n-j] = items[n-(j-1)];
            items[n] = temp;
        }
        
    }
    
    cout << "\n";
    cout << "Items after " << h << " hours: ";
    
    for (int i=0; i<n; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";
    return 0;
}
