class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mini = INT_MAX;
        while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] >= nums[l] && nums[mid] <= nums[h]){
                int yo = min(nums[l], nums[h]);
                mini = min(mini, min(nums[mid], yo));
                l++;
                h--;
            }
            else if(nums[mid] >= nums[l]){
                mini = min(mini, min(nums[mid], nums[l]));
                l = mid + 1;
            }
            else{
                mini = min(mini, min(nums[mid], nums[h]));
                h = mid - 1;
            }
        }
        return mini;
    }
};