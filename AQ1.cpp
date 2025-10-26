#include <iostream>

using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

// (a) Insertion as a first node
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
    cout << val << " inserted at the beginning." << endl;
}

// (a) Insertion as a last node
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
        cout << val << " inserted at the end." << endl;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    cout << val << " inserted at the end." << endl;
}

// (a) Insertion after a specific node
void insertAfterNode(int afterVal, int newVal) {
    Node* temp = head;
    // Find the node with data == afterVal
    while (temp != NULL && temp->data != afterVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node " << afterVal << " not found." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newVal;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    } else {
        // If we inserted after the tail, update tail
        tail = newNode;
    }
    cout << newVal << " inserted after " << afterVal << "." << endl;
}

// (b) Deletion of a specific node
void deleteNode(int val) {
    Node* temp = head;

    // Find the node to be deleted
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node " << val << " not found in the list." << endl;
        return;
    }

    // If node is the head
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            // List is now empty
            tail = NULL;
        }
    }
    // If node is the tail
    else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    }
    // If node is in the middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node " << val << " deleted." << endl;
}

// (c) Search for a node
void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Node " << val << " found at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << val << " not found in the list." << endl;
}

// Utility function to display the list
void displayList() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "List (forward): NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, val, afterVal;
    while (true) {
        cout << "\n--- DLL Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Node" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Search Node" << endl;
        cout << "6. Display List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value of node to insert after: ";
                cin >> afterVal;
                cout << "Enter new value to insert: ";
                cin >> val;
                insertAfterNode(afterVal, val);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(val);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;
            case 6:
                displayList();
                break;
            case 7:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}