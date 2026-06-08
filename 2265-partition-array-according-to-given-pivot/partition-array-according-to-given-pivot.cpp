class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int index = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
                ans[index] = nums[i];
                index++;
            }
            else if(nums[i] == pivot) cnt++;
        }

        while(cnt != 0){
            ans[index] = pivot;
            index++;
            cnt--;
        }

        for(int i=0;i<n;i++){
            if(nums[i] > pivot){
                ans[index] = nums[i];
                index++;
            }
        }

        return ans;
    }
};