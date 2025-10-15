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
    ListNode* findingTail(ListNode* head, int n){
        ListNode* temp = head;
        int k = 0;
        while(temp != NULL){
            k++;
            if(k == n) break;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        if(k % len == 0) return head;
        k = k % len;
        temp->next = head;
        ListNode* newTail = findingTail(head, len - k);
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};