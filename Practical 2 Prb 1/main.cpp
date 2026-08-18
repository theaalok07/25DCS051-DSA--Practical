#include <iostream>
#include <string>
using namespace std;

int main() {
    int noOfVehicle;
    
    cout << "Enter the number of vehicles in the parking lot: ";
    cin >> noOfVehicle;
    cout << "\n";
    
    string numberPlate[noOfVehicle];
    
    cout << "Enter number plates of every parked vehicle: \n";
    
    for (int i=0; i<noOfVehicle; i++) {
        cout << "Vehicle No. " << i+1 << ": ";
        cin >> numberPlate[i];
    }
    
    cout << "\n";
    cout << "These are the available number plates: \n";
    
    for (int i=0; i<noOfVehicle; i++) {
        cout << i+1 << ". " << numberPlate[i] << " ";
    }
    
    cout << "\n\n";
    
    string targetPlate;
    
    cout << "Enter target plate number: ";
    cin >> targetPlate;
    
    for (int i=0; i<noOfVehicle; i++) {
        if (targetPlate==numberPlate[i]) {
            cout << "Vehicle found at position: " << i+1;
        }
        else {
            cout << "Vehicle not found!";
            break;
        }
    }
    
    cout << "\n";
    return 0;
}
