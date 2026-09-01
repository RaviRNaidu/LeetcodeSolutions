class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int maxGap = 0;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            maxGap = max(maxGap, nums[i] - nums[i-1]);
        }

        return maxGap;
    }
};