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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {

//         vector<int> ans;

//         while(head != NULL){
//             ans.push_back(head->val);
//             head = head->next;
//         }

//         vector<int> rev(ans.rbegin(), ans.rend());

//         int i = 0;
//         while(i < ans.size() && ans[i] == rev[i]) i++;

//         return i == ans.size();
//     }
// };
