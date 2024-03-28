#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* pre = dummy;
    ListNode* cur = head;

    int count = 0;
    while (cur) {
        count++;
        if (count % k == 0) {
           ListNode* reverse(ListNode* pre, ListNode* next) {
   
            cur = pre->next;
        } else {
            cur = cur->next;
        }
    }

    return dummy->next;
}

ListNode* reverse(ListNode* pre, ListNode* next) {
    ListNode* last = pre->next;
    ListNode* cur = last->next;

    while (cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
    }

    return last;
}

// Utility function to create a linked list
ListNode* createLinkedList(int arr[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Utility function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    ListNode* head = createLinkedList(arr, n);
    std::cout << "Original linked list: ";
    printLinkedList(head);

    head = reverseKGroup(head, k);

    std::cout << "Modified linked list: ";
    printLinkedList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
