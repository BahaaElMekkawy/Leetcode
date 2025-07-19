/*
 * Approach:
 * - Initialize two pointers: `newHead` for the result list and `tail` to track the last node.
 * - Use a variable `sum` to accumulate values between zeros.
 * - Traverse the original list:
 *     - If the current node value is not 0, add it to `sum`.
 *     - If the value is 0 and `sum != 0`:
 *         - Create a new node with `sum` and append it to the result list.
 *         - Reset `sum` to 0.
 * - Return `newHead`.
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        int sum = 0;
        while (head) {
            if (head->val != 0) {
                sum += head->val;
            } else {
                if (sum != 0 || newHead != nullptr) {
                    ListNode* temp = new ListNode(sum);
                    if (!newHead) {
                        newHead = tail = temp;
                    } else {
                        tail->next = temp;
                        tail = temp;
                    }
                }
                sum = 0;
            }
            head = head->next;
        }
        return newHead;
    }
};