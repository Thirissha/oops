#include <iostream>
#include <vector>
#include <queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for min-heap
struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Create a min-heap
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

    // Push the heads of all lists into the min-heap
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    // Dummy node to simplify code
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // Merge lists until the min-heap is empty
    while (!minHeap.empty()) {
        // Get the node with the minimum value from the min-heap
        ListNode* node = minHeap.top();
        minHeap.pop();

        // Append the node to the merged list
        tail->next = node;
        tail = tail->next;

        // Move to the next node in the list
        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy.next;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    std::vector<ListNode*> lists = {l1, l2, l3};

    ListNode* mergedList = mergeKLists(lists);
    printList(mergedList);

    // Free memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
