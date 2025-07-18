/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if (k == 0)
            return head;
        ListNode* newTail = head;
        ListNode* newHead;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }
        newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};