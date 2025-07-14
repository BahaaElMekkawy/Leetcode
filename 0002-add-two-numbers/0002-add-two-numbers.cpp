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

// Approach:
// Simulate digit-by-digit addition (like manual addition) from left to right.
// Each input list represents a number in reverse order (least significant digit first).
//
// We iterate both linked lists in parallel using pointers (l1 and l2),
// and we keep track of a carry value from the previous digit.
//
// At each iteration:
//   - We sum l1->val (if available), l2->val (if available), and the current carry.
//   - Create a new node with value (sum % 10) to store the current digit.
//   - Update carry to (sum / 10).
//
// To build the result linked list:
//   - We use two pointers: `head` and `tail`.
//     - `head` points to the first node (used for return).
//     - `tail` always points to the last node in the list.
//   - If `head == nullptr`, we are adding the first node, so we set:
//       head = newNode;
//       tail = newNode;
//   - Otherwise, we link it to the end: tail->next = newNode; then update tail.
//
// Note:
//   - Each new node is created with `next = nullptr` by default,
//     so we don't need to explicitly write `tail->next = nullptr` at the end.
//   - This approach avoids using any built-in number types (like int/long),
//     so it works for very large numbers safely.
//
// Example:
//   l1: [2 -> 4 -> 3]  (342)
//   l2: [5 -> 6 -> 4]  (465)
//   → result: [7 -> 0 -> 8]  (807)
class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            if (!head) 
                head =tail =newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }



};

/*
    //Limitation 
    // 1.overflow as the list can be up to 100 node, so int or even long will fail 
    //extra work as we get the number and then reverse it in.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        int firstNumber = getNumberFormLS(l1);
        int secondNumber = getNumberFormLS(l2);
        int resNumber = firstNumber + secondNumber;

        if (resNumber == 0) {
            return new ListNode(0);
        }

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (resNumber > 0) {
            int digit = resNumber % 10;
            current->next = new ListNode(digit);
            current = current->next;
            resNumber /= 10;
        }

        return dummy->next;
    }

    int getNumberFormLS(ListNode* head) {
        int number = 0;
        int digit = 10;
        while (head) {
            number = number * digit + head->val;
            // digit *= 10;
            head = head->next;
        }
        return reverseNumber(number);
    }

    int reverseNumber(int number) {
        int lastDigit = 0;
        int x = 0;
        while (number != 0) {
            lastDigit = number % 10;
            x = x * 10 + lastDigit;
            number /= 10;
        }
        return x;
    }
    */