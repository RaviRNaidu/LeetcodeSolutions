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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* left = head;
        ListNode* right = head->next->next;
        while(right != NULL && right->next != NULL){
            left = left->next;
            right = right->next->next;
        }
        ListNode* del = left->next;
        left->next = del->next;
        delete del;
        return head;
    }
};