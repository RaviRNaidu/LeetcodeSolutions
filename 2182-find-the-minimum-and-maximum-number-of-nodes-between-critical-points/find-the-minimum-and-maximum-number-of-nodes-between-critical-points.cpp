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
        vector<int> criticalPoints;
        int cnt = 2;
        ListNode* temp = head->next;
        int prev = head->val;
        while(temp->next != NULL){
            if(temp->val > prev && temp->val > temp->next->val){
                criticalPoints.push_back(cnt);
            }
            else if(temp->val < prev && temp->val < temp->next->val){
                criticalPoints.push_back(cnt);
            }
            cnt++;
            prev = temp->val;
            temp = temp->next;
        }

        int m = criticalPoints.size();
        if(m == 0 || m == 1) return {-1, -1};
        int mini = cnt;
        int maxi = criticalPoints[m-1] - criticalPoints[0];
        for(int i=1;i<m;i++){
            mini = min(mini, criticalPoints[i] - criticalPoints[i-1]);
        }
        return {mini, maxi};
    }
};