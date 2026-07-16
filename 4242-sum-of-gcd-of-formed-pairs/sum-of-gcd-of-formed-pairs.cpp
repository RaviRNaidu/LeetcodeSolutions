class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int maxi = nums[0];
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi, nums[i]);
            prefix[i] = gcd(maxi, nums[i]);
        }

        sort(prefix.begin(), prefix.end());
        long long sum = 0;
        for(int i=0;i<(n/2);i++){
            sum += gcd(prefix[i], prefix[n-1-i]);
        }
        return sum;
    }
};