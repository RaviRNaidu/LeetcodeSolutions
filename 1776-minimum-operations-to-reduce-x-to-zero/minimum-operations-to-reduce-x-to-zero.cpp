class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        int ans = n+1;
        int subSum = 0;
        int l = 0;
        int r = 0;
        while(r <= n){
            while(subSum > (sum - x) && l < r){
                subSum -= nums[l];
                l++;
            }
            if(subSum == (sum - x)) ans = min(ans, n - (r-l)); 
            if(r < n)subSum += nums[r];
            r++;
        }
        if(ans == n+1) return -1;
        return ans;
    }
};