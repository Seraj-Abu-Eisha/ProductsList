//”—«Ã «»Ê⁄Ì‘…
#include <iostream>
#include <string>

using namespace std;

// Product structure
struct Product {
    string name;
    double price;
};


struct Node {
    Product data;
    Node* next;
};


class ProductList {
private:
    Node* head;

public:
  
    ProductList() : head(nullptr) {}

   
    ~ProductList() {
        while (!isEmpty()) {
            Node* del = head;
            head = head->next;
            delete del;
        }
    }


    bool isEmpty() {
        return head == nullptr;
    }

    void insertInOrder(const Product& newProduct) {
        Node* newNode = new Node{ newProduct, nullptr };

        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Product added successfully!\n";
    }

    
    void print() {
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
            cout << ptr->data.name << ", " << ptr->data.price << endl;
        }
    }

    
    void removeMax() {
        if (isEmpty()) {
            cout << "The list is empty. Cannot remove the highest-priced product.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        Node* maxNode = head;
        double maxPrice = head->data.price;

        
        while (current != nullptr) {
            if (current->data.price > maxPrice) {
                maxPrice = current->data.price;
                maxNode = current;
                prev = prev;  
            }
            current = current->next;
        }

        if (prev == nullptr) {
        
            head = head->next;
        }
        else {
  
            prev->next = maxNode->next;
        }

        delete maxNode;
        cout << "Highest-priced product removed successfully!\n";
    }
};

int main() {
    int choice;
    ProductList productList;

  
    productList.insertInOrder({ "mouse", 15.5 });
    productList.insertInOrder({ "USB", 8.5 });
    productList.insertInOrder({ "monitor", 500 });
    productList.insertInOrder({ "kb", 30 });

    do {
        cout << "1. Add new product\n"
            << "2. Remove the product with the highest price\n"
            << "3. Print all products\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Product newProduct;
            cout << "Enter product name: ";
            cin >> newProduct.name;
            cout << "Enter product price: ";
            cin >> newProduct.price;
            productList.insertInOrder(newProduct);
            break;
        }
        case 2:
            productList.removeMax();
            break;
        case 3:
            productList.print();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}