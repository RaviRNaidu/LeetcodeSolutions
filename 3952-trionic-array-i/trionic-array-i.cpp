class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] >= nums[1] || nums[n-1] <= nums[n-2]) return false;
        int p = -1;
        int q = -1;
        for(int i=1;i<n-1;i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                if(p != -1) return false;
                p = i;
            }
            else if(nums[i-1] > nums[i] && nums[i] < nums[i+1]){
                if(q != -1) return false;
                q = i;
            }
        }
        if(p == -1 || q == -1 || q <= p) return false;
        for(int i = 1; i <= p; i++){
            if(nums[i] <= nums[i-1]) return false;
        }

        // [p...q]
        for(int i = p+1; i <= q; i++){
            if(nums[i] >= nums[i-1]) return false;
        }

        // [q...n-1]
        for(int i = q+1; i < n; i++){
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};