#include <iostream>
#include <string>

using namespace std;

struct Product {
    string productName;
    double price;
    int quantity;
    Product* next;
};

void AddProduct(Product*& head, string productName, double price, int quantity);
void DisplayProducts(Product* head);


int main() {
    Product* head = nullptr;
    char choice;
    string productName;
    double price;
    int quantity;

    do {
        cout << "     Menu:\n";
        cout << " 1. Add Product\n";
        cout << " 2. Display Products\n";
        cout << " 3. Exit\n";
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            cout << " Enter product name: ";
            cin >> productName;
            cout << " Enter product price: ";
            cin >> price;
            cout << " Enter product quantity: ";
            cin >> quantity;
            AddProduct(head, productName, price, quantity);
            break;
        }
        case '2': {
            system("cls");
            DisplayProducts(head);
            break;
        }
        case '3': {
            cout << "Exiting program.\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');

    while (head != nullptr) {
        Product* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

void AddProduct(Product*& head, string productName, double price, int quantity) {
    Product* newProduct = new Product;
    newProduct->productName = productName;
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->next = nullptr;

    if (head == nullptr) {
        head = newProduct;
    }
    else {
        Product* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newProduct;
    }

}


void DisplayProducts(Product* head) {
    cout << "\n\tProducts:\n";
    Product* current = head;
    while (current != nullptr) {
        cout << "Name: " << current->productName << ", Price: P" << current->price << ", Quantity: " << current->quantity << "\n";
        current = current->next;
    }
}
