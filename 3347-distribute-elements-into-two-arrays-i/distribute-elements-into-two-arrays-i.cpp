class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left, right;
        left.push_back(nums[0]);
        right.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int l = left.back();
            int r = right.back();
            if(l > r){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }

        vector<int> ans(n);
        int m = left.size();
        for(int i=0;i<m;i++){
            ans[i] = left[i];
        }
        for(int i=m;i<n;i++){
            ans[i] = right[i - m];
        }
        return ans;
    }
};