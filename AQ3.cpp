#include <iostream>

using namespace std;

// Node for DLL
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

// Node for CLL
struct CLLNode {
    int data;
    CLLNode* next;
};

// (i) Function to find size of Doubly Linked List 
int getDLLSize(DLLNode* head) {
    int count = 0;
    DLLNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// (ii) Function to find size of Circular Linked List 
int getCLLSize(CLLNode* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    CLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    
    return count;
}

// Helper to create a test DLL
DLLNode* createTestDLL() {
    DLLNode* head = new DLLNode{1, NULL, NULL};
    DLLNode* n2 = new DLLNode{2, NULL, head};
    DLLNode* n3 = new DLLNode{3, NULL, n2};
    head->next = n2;
    n2->next = n3;
    return head;
}

// Helper to create a test CLL
CLLNode* createTestCLL() {
    CLLNode* head = new CLLNode{10, NULL};
    CLLNode* n2 = new CLLNode{20, NULL};
    CLLNode* n3 = new CLLNode{30, NULL};
    head->next = n2;
    n2->next = n3;
    n3->next = head; // Make it circular
    return head;
}

int main() {
    // Test DLL
    DLLNode* dllHead = createTestDLL();
    cout << "Size of Doubly Linked List: " << getDLLSize(dllHead) << endl;

    // Test CLL
    CLLNode* cllHead = createTestCLL();
    cout << "Size of Circular Linked List: " << getCLLSize(cllHead) << endl;

    return 0;
}