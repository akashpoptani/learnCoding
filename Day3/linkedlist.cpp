#include <iostream>
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

void pushFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void deleteValue(Node*& head, int val) {
    Node *current = head, *prev = nullptr;
    while (current) {
    // std::cout << head << "  " << head->val << std::endl;
        if (current->val == val) {
            if (prev) prev->next = current->next;
            else head = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;
    pushFront(head, 3); // List: 3
    pushFront(head, 2); // List: 2 -> 3
    pushFront(head, 1); // List: 1 -> 2 -> 3
    printList(head);    // Prints list
    // std::cout << head << "  " << head->val << std::endl;
    deleteValue(head, 2); // Removes '2'
    // std::cout << head << "  " << head->val << std::endl;
    // head->val = 8;
    // head->next->val = head->next->next->val;
    printList(head);    // Prints List: 1 -> 3
    deleteValue(head, 4);
    printList(head);    // Prints list again
    pushFront(head, 5); // List: 5 -> 1 -> 3
    pushFront(head, 1); // List: 1 -> 5 -> 1 -> 3
    printList(head);    // Prints list again
    deleteValue(head, 1); // List: 1 -> 5 -> 1 -> 3
    printList(head);    // Prints list again
    return 0;
}