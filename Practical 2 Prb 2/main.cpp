#include <iostream>
using namespace std;

int iterativeSearch(int bookCode[], int n, int target) {
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if(bookCode[mid]==target) {
            return mid;
        }
        else if(bookCode[mid]<target) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }

    return -1;
}

int recursiveSearch(int bookCode[], int low, int high, int target) {
    if(low>high) {
        return -1;
    }

    int mid=low+(high-low)/2;

    if(bookCode[mid]==target) {
        return mid;
    }
    else if(bookCode[mid]<target) {
        return recursiveSearch(bookCode,mid+1,high,target);
    }
    else {
        return recursiveSearch(bookCode,low,mid-1,target);
    }
}

int main() {
    int noOfBooks;

    cout << "Enter the number of books: ";
    cin >> noOfBooks;

    cout << "\n";

    int bookCode[noOfBooks];

    cout << "Enter book codes in sorted order:\n";

    for(int i=0; i<noOfBooks; i++) {
        cout << "Book No. " << i+1 << ": ";
        cin >> bookCode[i];
    }

    cout << "\n";

    cout << "These are the available book codes:\n";

    for(int i=0; i<noOfBooks; i++) {
        cout << i+1 << ". " << bookCode[i] << " ";
    }

    cout << "\n\n";

    int targetCode;

    cout << "Enter target book code: ";
    cin >> targetCode;

    int iterativeResult=iterativeSearch(bookCode,noOfBooks,targetCode);

    if(iterativeResult!=-1) {
        cout << "Iterative search: Book found at position: " << iterativeResult+1 << "\n";
    }
    else {
        cout << "Iterative search: Book not found.\n";
    }

    int recursiveResult=recursiveSearch(bookCode,0,noOfBooks-1,targetCode);

    if(recursiveResult!=-1) {
        cout << "Recursive search: Book found at position: " << recursiveResult+1 << "\n";
    }
    else {
        cout << "Recursive search: Book not found.\n";
    }

    return 0;
}
