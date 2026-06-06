class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0};
        vector<int> rightSum(n,0);
        for(int i=n-2;i>=0;i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }

        int leftSum = 0;
        vector<int> ans(n);
        ans[0] = rightSum[0];
        for(int i=1;i<n;i++){
            leftSum = leftSum + nums[i-1];
            ans[i] = abs(leftSum - rightSum[i]);
        }
        return ans;
    }
};