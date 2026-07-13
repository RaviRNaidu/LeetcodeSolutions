class Solution {
    int solution(vector<int>& nums, int st, int end){
        int prev1 = 0;
        int prev2 = nums[st];
        for(int i=st+1;i<=end;i++){
            int pick = nums[i] + prev1;
            int notPick = prev2;
            prev1 = prev2;
            prev2 = max(pick, notPick);
        }
        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solution(nums, 0, n-2), solution(nums, 1, n-1));
    }
};