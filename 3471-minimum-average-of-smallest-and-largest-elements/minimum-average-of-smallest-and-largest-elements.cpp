class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double mini = INT_MAX;
        for(int i=0;i<n/2;i++){
            double ans = (double)(nums[n-1-i] + nums[i]) / 2;
            mini = min(mini, ans);
        }
        return mini;
    }
};