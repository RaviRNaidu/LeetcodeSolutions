class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mpp;
        int sum = 0;
        mpp[0].push_back(0);
        for(int i=0;i<n;i++){
            sum += nums[i];
            mpp[sum].push_back(i+1);
            if(sum == x) ans = min(ans, i+1);
        }
        if(sum < x) return -1;

        int sum2 = 0;
        for(int i=n-1;i>=0;i--){
            mpp.erase(sum);
            sum -= nums[n-1];
            sum2 += nums[i];
            if(sum2 > x) break;
            if(mpp.find(x-sum2) != mpp.end()){
                for(auto it : mpp[x-sum2]){
                    ans = min(ans, n-i+it);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};