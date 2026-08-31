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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = INT_MAX;
        int stCp = -1;
        int prevCp = -1;
        int cnt = 2;
        ListNode* temp = head->next;
        int prev = head->val;
        while(temp->next != NULL){
            if(temp->val > prev && temp->val > temp->next->val){
                if(stCp == -1) stCp = cnt;
                if(prevCp != -1) mini = min(mini, cnt - prevCp);
                prevCp = cnt;
            }
            else if(temp->val < prev && temp->val < temp->next->val){
                if(stCp == -1) stCp = cnt;
                if(prevCp != -1) mini = min(mini, cnt - prevCp);
                prevCp = cnt;
            }
            cnt++;
            prev = temp->val;
            temp = temp->next;
        }

        if(stCp == -1 || prevCp == -1 || mini == INT_MAX) return {-1, -1};
        return {mini, prevCp - stCp};
    }
};