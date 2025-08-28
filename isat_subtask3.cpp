#include <iostream>
using namespace std;

int main() {
    // Arrays to store details of up to 50 orders
    int orderID[50];          // store order IDs
    string customer[50];      // store customer names
    int magwinyas[50];        // store number of magwinyas ordered
    int total[50];            // store total cost for each order
    int count = 0;            // keeps track of how many orders have been added
    int choice;               // user's menu choice

    do {
        // Display the main menu
        cout << "\nOrder Management System\n";
        cout << "1. Add a new order\n";
        cout << "2. Display all orders\n";
        cout << "3. Find an order by Order ID\n";
        cout << "4. Calculate total revenue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            // Add a new order
            cout << "Enter Order ID: ";
            cin >> orderID[count];
            cout << "Enter Customer Name: ";
            cin >> customer[count];
            cout << "Enter Number of Magwinyas: ";
            cin >> magwinyas[count];
            cout << "Enter Total Cost: ";
            cin >> total[count];

            cout << "Order added successfully!\n";
            count++;  // Increase the count of orders
        }
        else if (choice == 2) {
            // Display all orders
            if (count == 0) {
                cout << "No orders to display.\n"; // No orders yet
            } else {
                cout << "\nAll Orders:\n";
                for (int i = 0; i < count; i++) {
                    // Print each order in a readable format
                    cout << "Order ID: " << orderID[i]
                         << ", Customer: " << customer[i]
                         << ", Number of Magwinyas: " << magwinyas[i]
                         << ", Total: " << total[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            // Find a specific order by its ID
            int id;
            cout << "Enter Order ID to find: ";
            cin >> id;
            bool found = false; // flag to track if we find the order

            for (int i = 0; i < count; i++) {
                if (orderID[i] == id) {
                    // Order found, display details
                    cout << "Order ID: " << orderID[i]
                         << ", Customer: " << customer[i]
                         << ", Number of Magwinyas: " << magwinyas[i]
                         << ", Total: " << total[i] << endl;
                    found = true;
                    break; // stop searching since we found it
                }
            }
            if (!found) {
                cout << "Order with ID " << id << " not found.\n";
            }
        }
        else if (choice == 4) {
            // Calculate total revenue from all orders
            int revenue = 0;
            for (int i = 0; i < count; i++) {
                revenue += total[i]; // sum up all total costs
            }
            cout << "Total revenue: " << revenue << endl;
        }
        else if (choice == 5) {
            // Exit the program
            cout << "Exiting program...\n";
        }
        else {
            // Handle invalid input
            cout << "Invalid choice, try again.\n";
        }

    } while (choice != 5); // repeat until user chooses to exit

    return 0;
}
