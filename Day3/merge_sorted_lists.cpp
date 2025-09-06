#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Function to merge two sorted linked lists and return merged head
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy(0);          // Dummy node as start of merged list
    Node* current = &dummy; // Pointer for building the merged list

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1; // Append l1 node
            l1 = l1->next;      // Advance l1
        } else {
            current->next = l2; // Append l2 node
            l2 = l2->next;      // Advance l2
        }
        current = current->next; // Move current forward
    }

    // Attach remaining nodes from either l1 or l2
    current->next = (l1 != nullptr) ? l1 : l2;

    return dummy.next; // Head of merged list (skip dummy)
}

// Helper function to create linked list from values
Node* createList(const std::vector<int>& vals) {
    Node dummy(0);
    Node* current = &dummy;
    for (int v : vals) {
        current->next = new Node(v);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Clean up list memory
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create two sorted linked lists
    Node* list1 = createList({1, 3, 5, 7});
    Node* list2 = createList({2, 4, 4, 8, 10});

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    // Merge lists
    Node* merged = mergeSortedLists(list1, list2);
    std::cout << "Merged list: ";
    printList(merged);

    // Clean up memory
    deleteList(merged);

    return 0;
}