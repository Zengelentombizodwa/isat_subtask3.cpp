#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int numMagwinyas;
    double totalCost;
};

vector<Order> orders;

void addOrder() {
    Order newOrder;
    cout << "Enter Order ID: ";
    cin >> newOrder.orderID;
    cout << "Enter Customer Name: ";
    cin >> newOrder.customerName;
    cout << "Enter Number of Magwinyas Ordered: ";
    cin >> newOrder.numMagwinyas;
    newOrder.totalCost = newOrder.numMagwinyas * 5.0; // assume each Magwinya costs 5
    orders.push_back(newOrder);
    cout << "Order added successfully!\n";
}

void displayOrders() {
    if (orders.empty()) {
        cout << "No orders to display.\n";
        return;
    }
    cout << "All Orders:\n";
    for (auto &o : orders) {
        cout << "Order ID: " << o.orderID
             << ", Customer: " << o.customerName
             << ", Number of Magwinyas: " << o.numMagwinyas
             << ", Total: " << o.totalCost << "\n";
    }
}

void findOrderByID() {
    int id;
    cout << "Enter Order ID to find: ";
    cin >> id;
    bool found = false;
    for (auto &o : orders) {
        if (o.orderID == id) {
            cout << "Order ID: " << o.orderID
                 << ", Customer: " << o.customerName
                 << ", Number of Magwinyas: " << o.numMagwinyas
                 << ", Total: " << o.totalCost << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Order with Order ID " << id << " not found.\n";
}

void calculateTotalRevenue() {
    double total = 0;
    for (auto &o : orders) {
        total += o.totalCost;
    }
    cout << "Total revenue: " << total << "\n";
}

int main() {
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

        switch (choice) {
            case 1: addOrder(); break;
            case 2: displayOrders(); break;
            case 3: findOrderByID(); break;
            case 4: calculateTotalRevenue(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
