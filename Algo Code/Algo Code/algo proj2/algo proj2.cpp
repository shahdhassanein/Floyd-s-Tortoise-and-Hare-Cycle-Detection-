#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

// Recursive helper for Tortoise and Hare
bool hasCycleRecursive(ListNode* slow, ListNode* fast) {
    // Base cases
    if (!fast || !fast->next) return false;  // End reached, no cycle
    if (slow == fast) return true;           // Cycle found

    // Recurse with slow = slow->next, fast = fast->next->next
    return hasCycleRecursive(slow->next, fast->next->next);
}

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    return hasCycleRecursive(head, head->next);
}

// Utility to create a list with cycle for testing
ListNode* createListWithCycle() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    fifth->next = third; // Creates cycle here

    return head;
}

int main() {
    ListNode* head = createListWithCycle();
    std::cout << (hasCycle(head) ? "Cycle detected" : "No cycle") << std::endl;
    return 0;
}
