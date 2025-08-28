#include <iostream>
using namespace std;

int main() {
    int orderID[50];          // store order IDs
    string customer[50];      // store customer names
    int magwinyas[50];        // store number of magwinyas
    int total[50];            // store total cost entered by user
    int count = 0;            // number of orders saved
    int choice;

    do {
        cout << "\nOrder Management System\n";
        cout << "1. Add a new order\n";
        cout << "2. Display all orders\n";
        cout << "3. Find an order by Order ID\n";
        cout << "4. Calculate total revenue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Order ID: ";
            cin >> orderID[count];
            cout << "Enter Customer Name: ";
            cin >> customer[count];
            cout << "Enter Number of Magwinyas: ";
            cin >> magwinyas[count];
            cout << "Enter Total Cost: ";
            cin >> total[count];
            cout << "Order added successfully!\n";
            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No orders to display.\n";
            } else {
                cout << "\nAll Orders:\n";
                for (int i = 0; i < count; i++) {
                    cout << "Order ID: " << orderID[i]
                         << ", Customer: " << customer[i]
                         << ", Number of Magwinyas: " << magwinyas[i]
                         << ", Total: " << total[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Order ID to find: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (orderID[i] == id) {
                    cout << "Order ID: " << orderID[i]
                         << ", Customer: " << customer[i]
                         << ", Number of Magwinyas: " << magwinyas[i]
                         << ", Total: " << total[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Order with ID " << id << " not found.\n";
            }
        }
        else if (choice == 4) {
            int revenue = 0;
            for (int i = 0; i < count; i++) {
                revenue += total[i];
            }
            cout << "Total revenue: " << revenue << endl;
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice, try again.\n";
        }

    } while (choice != 5);

    return 0;
}
