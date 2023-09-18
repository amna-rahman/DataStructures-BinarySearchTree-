
#include <iostream>
#include <string>

// Node structure represents a node in the binary search tree
class Node {
private:
    int empID;
    std::string name;
    double salary;
    Node* left;
    Node* right;

public:
    Node(int id, std::string n, double s) {
        empID = id;
        name = n;
        salary = s;
        left = nullptr;
        right = nullptr;
    }

    // Getter methods for accessing private member variables
    int getEmpID() {
        return empID;
    }

    std::string getName() {
        return name;
    }

    double getSalary() {
        return salary;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }

    friend class BST;  // Declare BST class as a friend to access private members
};

// Binary Search Tree (BST) class
class BST {
private:
    Node* root;  // Pointer to the root node of the BST

    // Helper method to print the BST in order (in-order traversal)
    void printInOrder(Node* node) {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->getLeft());
        std::cout << "ID: " << node->getEmpID() << ", Name: " << node->getName() << ", Salary: " << node->getSalary() << std::endl;
        printInOrder(node->getRight());
    }

public:
    // Constructor to initialize the BST
    BST() {
        root = nullptr;
    }

    // Public method to print the BST in order
    void printInOrder() {
        printInOrder(root);
    }

    // Public method to search for a node in the BST based on employee ID
    Node* search(int id) {
        Node* current = root;

        while (current != nullptr && current->getEmpID() != id) {
            if (id < current->getEmpID()) {
                current = current->getLeft();
            } else {
                current = current->getRight();
            }
        }

        return current;
    }

    // Public method to insert a new node into the BST
    void insert(int id, std::string name, double salary) {
        Node* newNode = new Node(id, name, salary);

        if (root == nullptr) {
            root = newNode;  // If the BST is empty, set the new node as the root
        } else {
            Node* current = root;

            while (true) {
                if (id < current->getEmpID()) {
                    if (current->getLeft() == nullptr) {
                        current->left = newNode;  // Insert new node as the left child
                        break;
                    }
                    current = current->getLeft();
                } else {
                    if (current->getRight() == nullptr) {
                        current->right = newNode;  // Insert new node as the right child
                        break;
                    }
                    current = current->getRight();
                }
            }
        }
    }
};

int main() {
    BST bst;  // Create an instance of the Binary Search Tree

    // Hard-coded initial record (replace with your VUID details)
    int initialID = 220406761;  // Replace with your VUID

    int initialEmpID = initialID % 1000;     // Last three digits of initialID
    double initialSalary = initialID % 100000;  // Last five digits of initialID

    bst.insert(initialEmpID, "Amna", initialSalary);  // Insert the initial record into the BST

    while (true) {
        // Print the menu options for the user
        std::cout << "Enter 1 to check the existing record" << std::endl;
        std::cout << "Enter 2 to insert a new employee record" << std::endl;
        std::cout << "Enter 3 to search for an employee record" << std::endl;
        std::cout << "Enter 4 to exit" << std::endl;

        int choice;
        std::cin >> choice;  // Read the user's choice

        if (choice == 1) {
            std::cout << "Employee records:" << std::endl;
            bst.printInOrder();  // Print all the records in the BST in order
        } else if (choice == 2) {
            std::cout << "Enter employee ID: ";
            int initialID;
            std::cin >> initialID;

            int id = initialID % 1000;     // Last three digits of initialID
            double salary = initialID % 100000;  // Last five digits of initialID

            std::cout << "Enter employee name: ";
            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);

            bst.insert(id, name, salary);  // Insert the new employee record into the BST
            std::cout << "Employee record inserted successfully." << std::endl;
        } else if (choice == 3) {
            std::cout << "Enter employee ID to search: ";
            int id;
            std::cin >> id;

            Node* result = bst.search(id);  // Search for the employee record in the BST
            if (result != nullptr) {
                std::cout << "Employee found:" << std::endl;
                std::cout << "ID: " << result->getEmpID() << ", Name: " << result->getName() << ", Salary: " << result->getSalary() << std::endl;
            } else {
                std::cout << "Employee not found." << std::endl;
            }
        } else if (choice == 4) {
            break;  // Exit the program
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

