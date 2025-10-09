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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head1, ListNode* head2){
        ListNode* dup = new ListNode(-1);
        ListNode* mover = dup;
        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                mover->next = head1;
                mover = head1;
                head1 = head1->next;
            }
            else{
                mover->next = head2;
                mover = head2;
                head2 = head2->next;
            }
        }
        if(head1) mover->next = head1;
        else mover->next = head2;

        return dup->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeSort(left, right);
    }
};