class Solution {
    int lowerBound(vector<int> &arr, int n, int target){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back() < nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                int index = lowerBound(ans, ans.size(), nums[i]);
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};