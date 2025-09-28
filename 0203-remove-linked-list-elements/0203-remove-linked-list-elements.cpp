class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = dummy;
        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; 
            } else {
                current = current->next;
            }
        }

        head = dummy->next;
        delete dummy; 
        return head;
    }
};
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if (head == nullptr)
//             return head;
//         if (head->val == val) {
//             return removeElements(head->next, val);
//         }
//         head->next = removeElements(head->next, val);
//         return head;
//     }
// };