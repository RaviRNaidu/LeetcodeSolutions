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
    ListNode* reverseHelper(ListNode* head){
        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* mid;
        ListNode* s = head;
        ListNode* f = head->next;
        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        mid = s->next;
        s->next = NULL;

        mid = reverseHelper(mid);
        ListNode* temp = head;
        while(temp != NULL && mid != NULL){
            ListNode* next = temp->next;
            temp->next = mid;
            temp = next;
            
            next = mid->next;
            mid->next = temp;
            mid = next;
        }
    }
};