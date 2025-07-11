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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr && list2 != nullptr)
            return list2;
        else if (list2 == nullptr && list1 != nullptr)
            return list1;
        else {
            ListNode* res;
            ListNode* cur ;
            if (list1->val <= list2->val) {
                res = list1;
                list1 = list1->next;
            } else {
                res = list2;
                list2 = list2->next;
            }
            cur = res;
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                } else {
                    cur->next = list2;
                    list2 = list2->next;
                }
                cur = cur->next;
            }
            if (list1 != nullptr)
                cur->next = list1;
            else
                 cur->next = list2;
            return res;
        }
    }
};