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
    ListNode* reverse(ListNode* head){
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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while(p2 != NULL && p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p1->next = reverse(p1->next);
        

        ListNode* right = p1->next;
        ListNode* left = head;
        int ans = 0;
        while(left != p1->next){
            int sum = right->val + left->val;
            ans = max(ans, sum);
            right = right->next;
            left = left->next;
        }

        return ans;
    }
};