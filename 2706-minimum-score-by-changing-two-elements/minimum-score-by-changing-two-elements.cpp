class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return 0;
        nth_element(nums.begin(), nums.begin() + 2, nums.end());
        int mini = min(nums[0], nums[1]);
        int smini = max(nums[0], nums[1]);
        int tmini = nums[2];
        nth_element(nums.begin(), nums.begin() + 2, nums.end(), greater());
        int tmaxi = nums[2];
        int smaxi = min(nums[0], nums[1]);
        int maxi = max(nums[0], nums[1]);
        int ans = min(maxi - tmini, tmaxi - mini);
        return min(ans, smaxi - smini);
    }
};