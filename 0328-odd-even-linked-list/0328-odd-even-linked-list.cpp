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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        ListNode* firstOdd = head;
        ListNode* firstEven = head->next;

        ListNode* curOdd = head;
        ListNode* curEven = head->next;

        while (curOdd->next!=nullptr && curEven->next!=nullptr) {
            curOdd->next = curEven->next;
            curOdd = curOdd->next;

            curEven->next = curOdd->next;
            curEven = curEven->next;
        }
        curOdd->next = firstEven;

        return firstOdd;
    }
};