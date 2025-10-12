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
    ListNode* findKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL){
                if(prev)prev->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);
            
            if(temp == head){
                head = kthNode;
            }
            else{
                prev->next = kthNode;
            }
            
            prev = temp;
            temp = nextNode;
        }

        return head;
    }
};