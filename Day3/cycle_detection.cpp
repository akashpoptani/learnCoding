#include <iostream>
#include <vector>  // Add this to use std::vector

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // move slow by 1
        fast = fast->next->next;     // move fast by 2

        if (slow == fast) {
            return true;             // cycle detected
        }
    }

    return false;  // no cycle found
}

// Helper to create nodes and optionally create a cycle
Node* createListWithCycle(const std::vector<int>& vals, int posCycleStart) {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* cycleStartNode = nullptr;

    for (size_t i = 0; i < vals.size(); ++i) {
        Node* newNode = new Node(vals[i]);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        if ((int)i == posCycleStart) {
            cycleStartNode = newNode;
        }
    }

    if (tail && cycleStartNode)
        tail->next = cycleStartNode;  // create cycle

    return head;
}
// Print list up to maxNodes to avoid infinite printing on cycles
void printList(Node* head, int maxNodes = 10) {
    int count = 0;
    while (head && count < maxNodes) {
        std::cout << head->val;
        head = head->next;
        if (head) std::cout << " -> ";
        count++;
    }
    if (head) std::cout << "... (cycle suspected)";
    std::cout << std::endl;
}

int main() {
    Node* listNoCycle = createListWithCycle({1, 2, 3, 4, 5}, -1);
    Node* listWithCycle = createListWithCycle({1, 2, 3, 4, 5}, 2);  // cycle start at index 2 (value 3)

    std::cout << "List without cycle: ";
    printList(listNoCycle);

    std::cout << "List with cycle: ";
    printList(listWithCycle);  // will print maxNodes then stop

    std::cout << "List without cycle has cycle? " << (hasCycle(listNoCycle) ? "Yes" : "No") << std::endl;
    std::cout << "List with cycle has cycle? " << (hasCycle(listWithCycle) ? "Yes" : "No") << std::endl;

    // Note: List with cycle not freed here for simplicity
    // Be careful with run-time loops on cyclic lists!

    return 0;
}
