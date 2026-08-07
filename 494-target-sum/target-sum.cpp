class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int d) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum - d < 0 || ((sum - d) % 2)) return 0;
        int target = (sum - d) / 2;

        vector<int> prev(target+1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;
        for(int i=1;i<n;i++){
            vector<int> curr(target+1, 0);
            for(int j=0;j<=target;j++){
                int notTake = prev[j];
                int take = 0;
                if(nums[i] <= j){
                    take = prev[j - nums[i]];
                }
                curr[j] = notTake + take;
            }
            prev = curr;
        }
        int ans = prev[target];
        return ans;
    }
};