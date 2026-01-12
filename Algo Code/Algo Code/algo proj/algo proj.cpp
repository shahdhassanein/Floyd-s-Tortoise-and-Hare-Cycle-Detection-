#include <iostream>
#include <unordered_set>
#include <ctime>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Brute-Force Cycle Detection (Using Hash Set)
bool hasCycleBruteForce(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head != nullptr) {
        if (visited.count(head)) {
            return true; // Cycle found
        }
        visited.insert(head);
        head = head->next;
    }
    return false; // No cycle
}

int main() {
    int n;
    cout << "How many nodes in the list? ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of nodes.\\n";
        return 0;
    }

    vector<ListNode*> nodes;
    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    nodes.push_back(head);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> val;
        ListNode* newNode = new ListNode(val);
        current->next = newNode;
        current = newNode;
        nodes.push_back(newNode);
    }

    // Uncomment the line below to manually create a cycle for testing
     /*current->next = nodes[1];*/ // Example: create cycle back to node 2

    // Run cycle detection multiple times to get a measurable time
    int runs = 100000;
    clock_t start = clock();
    bool cycleDetected = false;
    for (int i = 0; i < runs; ++i) {
        cycleDetected = hasCycleBruteForce(head);
    }
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Cycle detection result: " << (cycleDetected ? "Cycle detected" : "No cycle found") << endl;
    cout << "Average time per run: " << (elapsed / runs) * 1e6 << " microseconds " << endl;

    return 0;
}
