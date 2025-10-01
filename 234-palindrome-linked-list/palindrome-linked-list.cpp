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
    ListNode* reverseNode(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = reverseNode(slow->next);
        ListNode* left = head;
        while(right != NULL){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};