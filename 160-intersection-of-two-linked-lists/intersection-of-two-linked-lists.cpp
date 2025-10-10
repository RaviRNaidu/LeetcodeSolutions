/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        int L1 = 0;
        while(temp1 != NULL){
            L1++;
            temp1 = temp1->next;
        }

        ListNode* temp2 = headB;
        int L2 = 0;
        while(temp2 != NULL){
            L2++;
            temp2 = temp2->next;
        }
        int diff = abs(L1 - L2);
        temp1 = headA;
        temp2 = headB;
        if(L2 > L1){
            while(diff > 0){
                diff--;
                temp2 = temp2->next;
            }
        }
        else{
            while(diff > 0){
                diff--;
                temp1 = temp1->next;
            }
        }

        while(temp1 != NULL){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};