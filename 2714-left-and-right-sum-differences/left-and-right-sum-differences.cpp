class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0};
        vector<int> rightSum(n,0);
        for(int i=n-2;i>=0;i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }

        vector<int> leftSum(n,0);
        vector<int> ans(n);
        ans[0] = rightSum[0];
        for(int i=1;i<n;i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};