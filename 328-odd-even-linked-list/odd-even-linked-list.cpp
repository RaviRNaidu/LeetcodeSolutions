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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* oddMover = odd;
        ListNode* even = head->next;
        ListNode* evenMover = even;
        while(evenMover != NULL && evenMover->next != NULL){
            oddMover->next = oddMover->next->next;
            evenMover->next = evenMover->next->next;
            oddMover = oddMover->next;
            evenMover = evenMover->next;
        }
        oddMover->next = even;
        return head;
    }
};