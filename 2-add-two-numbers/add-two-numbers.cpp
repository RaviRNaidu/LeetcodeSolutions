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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* mover = dummy;
        while(temp1 != NULL && temp2 != NULL){
            int sum = (temp1->val + temp2->val + carry);
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else carry = 0;
            ListNode* newNode = new ListNode(sum);
            mover->next = newNode;
            mover = newNode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int sum = temp1->val + carry;
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else carry = 0;
            ListNode* newNode = new ListNode(sum);
            mover->next = newNode;
            mover = newNode;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else carry = 0;
            ListNode* newNode = new ListNode(sum);
            mover->next = newNode;
            mover = newNode;
            temp2 = temp2->next;
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            mover->next = newNode;
            mover = newNode;
        }
        return dummy->next;
    }
};