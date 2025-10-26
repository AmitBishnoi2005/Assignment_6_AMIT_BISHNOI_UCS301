#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if list is circular
bool isCircular(Node* head) {
    if (head == NULL) {
        return false; // An empty list isn't circular
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Pointers met, a cycle exists
            // To be truly "circular", the cycle must involve the head.
            // But for this problem, we just check if the "fast" pointer
            // can eventually get back to the "head".
            // A simpler check: if fast == head, it's definitely circular.
            // If they meet anywhere, it's a loop.
            return true;
        }
    }

    // If fast reaches NULL, there is no cycle
    return false;
}

int main() {
    // Example 1: Circular List 
    Node* head1 = new Node{2, NULL};
    head1->next = new Node{4, NULL};
    head1->next->next = new Node{6, NULL};
    head1->next->next->next = new Node{7, NULL};
    head1->next->next->next->next = new Node{5, NULL};
    head1->next->next->next->next->next = head1; // Loop back to head

    if (isCircular(head1)) {
        cout << "List 1 is Circular: True" << endl; // Expected: True [cite: 40]
    } else {
        cout << "List 1 is Circular: False" << endl;
    }

    // Example 2: Normal NULL-terminated list
    Node* head2 = new Node{1, NULL};
    head2->next = new Node{2, NULL};
    head2->next->next = new Node{3, NULL};
    
    if (isCircular(head2)) {
        cout << "List 2 is Circular: True" << endl;
    } else {
        cout << "List 2 is Circular: False" << endl; // Expected: False
    }
    
    return 0;
}