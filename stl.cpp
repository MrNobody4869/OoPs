#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to represent an item
struct Item {
    int code;          // Item code
    string name;       // Item name
    float cost;        // Item cost
    int quantity;      // Item quantity

    // Function to display item details
    void display() const {
        cout << "Code: " << code << ", Name: " << name 
             << ", Cost: " << cost << ", Quantity: " << quantity << endl;
    }
};

// Comparator function for sorting items by code
bool compareByCode(const Item& a, const Item& b) {
    return a.code < b.code;
}

// Function to search for an item by its code
void searchItem(const vector<Item>& items, int code) {
    auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
        return item.code == code;
    });

    if (it != items.end()) {
        cout << "Item found:\n";
        it->display();
    } else {
        cout << "Item with code " << code << " not found.\n";
    }
}

int main() {
    vector<Item> items;
    int n;

    // Input the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    // Input item details
    for (int i = 0; i < n; ++i) {
        Item item;
        cout << "Enter details for item " << i + 1 << ":\n";
        cout << "Code: ";
        cin >> item.code;
        cin.ignore();  // Ignore newline
        cout << "Name: ";
        getline(cin, item.name);
        cout << "Cost: ";
        cin >> item.cost;
        cout << "Quantity: ";
        cin >> item.quantity;

        items.push_back(item);
    }

    // Sorting items by code
    sort(items.begin(), items.end(), compareByCode);

    // Display sorted items
    cout << "\nItems after sorting by code:\n";
    for (const auto& item : items) {
        item.display();
    }

    // Searching for an item by code
    int searchCode;
    cout << "\nEnter the code of the item to search: ";
    cin >> searchCode;
    searchItem(items, searchCode);

    return 0;
}
