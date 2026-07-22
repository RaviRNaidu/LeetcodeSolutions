class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<bool> prev((sum/2)+1, false);
        prev[0] = true;

        for(int i=1;i<=n;i++){
            for(int s=sum/2;s>0;s--){
                int take = false;
                int notTake = prev[s];
                if(nums[i-1] <= s){
                    take = prev[s - nums[i-1]];
                }
                prev[s] = take || notTake;
            }
        }
        return prev[sum/2];
    }
};