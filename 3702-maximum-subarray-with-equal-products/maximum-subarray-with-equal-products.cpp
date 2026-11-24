class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unsigned long long p = 1;
            int g = nums[i];
            int l = nums[i]; 
            for(int j=i;j<n;j++){
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if(p == g * l){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};