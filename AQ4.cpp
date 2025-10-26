#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Function to check for palindrome
bool isPalindrome(Node* head, Node* tail) {
    if (head == NULL) {
        // An empty list is a palindrome
        return true;
    }

    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    
    // If we are here, all checked characters matched
    return true;
}

// Helper function to build the list
void push(Node** head_ref, Node** tail_ref, char c) {
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = NULL;
    newNode->prev = *tail_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        (*tail_ref)->next = newNode;
    }
    *tail_ref = newNode;
}

int main() {
    // Example 1: "L" "E" "V" "E" "L" [cite: 19, 21, 22, 23, 24, 25]
    Node* head1 = NULL;
    Node* tail1 = NULL;
    push(&head1, &tail1, 'L');
    push(&head1, &tail1, 'E');
    push(&head1, &tail1, 'V');
    push(&head1, &tail1, 'E');
    push(&head1, &tail1, 'L');

    if (isPalindrome(head1, tail1)) {
        cout << "List 1 (LEVEL) is: True" << endl; // Expected: True [cite: 29]
    } else {
        cout << "List 1 (LEVEL) is: False" << endl;
    }

    // Example 2: "H" "E" "L" "L" "O"
    Node* head2 = NULL;
    Node* tail2 = NULL;
    push(&head2, &tail2, 'H');
    push(&head2, &tail2, 'E');
    push(&head2, &tail2, 'L');
    push(&head2, &tail2, 'L');
    push(&head2, &tail2, 'O');

    if (isPalindrome(head2, tail2)) {
        cout << "List 2 (HELLO) is: True" << endl;
    } else {
        cout << "List 2 (HELLO) is: False" << endl; // Expected: False
    }

    return 0;
}