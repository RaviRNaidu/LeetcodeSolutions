class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i == j){
                    dp[i] = nums[i];
                }
                else{
                    int pickLeft  = nums[i] - dp[j];
                    int pickRight = nums[j] - dp[j-1];
                    
                    dp[j] = max(pickLeft, pickRight);
                }
            }
        }
        int sum = dp[n-1];
        if(sum >= 0) return true;
        return false;
    }
};