
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        while (k != 0) {
            temp = head;
            ListNode* prev = NULL;

            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }

            temp->next = head;
            head = temp;
            prev->next = NULL;

            k--;
        }

        return head;
    }
};
