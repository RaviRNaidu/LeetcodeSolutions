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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head->next == NULL && n == 1) return NULL;
        ListNode* fast = head;
        int index = n;
        while(fast != NULL && index != 0){
            fast = fast->next;
            index--;
        }
        if(fast == NULL){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        ListNode* slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return head;
    }
};