class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
            sum += nums[i] * i;
        }

        long long ans = sum;
        for(int i=1;i<n;i++){
            sum = (sum + totalSum) - (n * nums[n-i]); 
            ans = max(ans, sum);
        }
        
        return (int)ans;
    }
};