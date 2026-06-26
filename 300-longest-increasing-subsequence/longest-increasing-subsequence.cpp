class Solution {
    int memoization(vector<int> &arr, int n){
        vector<int> prev(n+1, 0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1, 0);
            for(int j=i;j<=n;j++){
                int notTake = prev[j];
                int take = 0;
                if(j == n || arr[j] > arr[i - 1]){
                    take = 1 + prev[i-1];
                }
                curr[j] = max(notTake, take);
            }
            prev = curr;
        }
        return prev[n];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = memoization(nums, n);
        return ans;
    }
};