class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int prev = nums[0];
        int cnt = 1;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] == prev){
                if(cnt + 1 <= k){
                    ans.push_back(nums[i]);
                    cnt++;
                }
                else{
                    continue;
                }
            }
            else{
                prev = nums[i];
                cnt = 1;
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};