#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Helper function to push nodes and create a circular list
// We'll use a 'head' pointer implementation here
void push(Node** head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head_ref;

    // If list is not empty, find the last node and link it
    if (*head_ref != NULL) {
        Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode; // First node points to itself
    }
    *head_ref = newNode;
}

// Function to display the list as required 
void displayListRepeatingHead(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    // Print the head node's value again
    cout << head->data << endl;
}

int main() {
    Node* head = NULL;

    // Input: 20 -> 100 -> 40 -> 80 -> 60 [cite: 12]
    // We push in reverse order to get the correct list
    push(&head, 60);
    push(&head, 80);
    push(&head, 40);
    push(&head, 100);
    push(&head, 20);

    cout << "Input List: 20 -> 100 -> 40 -> 80 -> 60" << endl;
    cout << "Output: ";
    displayListRepeatingHead(head); // Expected: 20 100 40 80 60 20 [cite: 13]

    return 0;
}