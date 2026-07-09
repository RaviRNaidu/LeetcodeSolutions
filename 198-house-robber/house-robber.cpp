class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = nums[0];
        for(int i=2;i<=n;i++){
            int take = nums[i-1] + first;
            int notTake = second;
            first = second;
            second = max(take, notTake);
        }
        return second;
    }
};