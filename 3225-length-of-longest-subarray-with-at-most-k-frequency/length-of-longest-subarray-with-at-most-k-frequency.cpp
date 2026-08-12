class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mpp;
        int maxFreq = 0;
        int ans = 0;
        while(j < n){
            while(maxFreq > k && i < j){
                int temp = mpp[nums[i]];
                if(temp == maxFreq){
                    maxFreq = temp - 1;
                }
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            mpp[nums[j]]++;
            maxFreq = max(maxFreq, mpp[nums[j]]);
            if(maxFreq <= k) ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};