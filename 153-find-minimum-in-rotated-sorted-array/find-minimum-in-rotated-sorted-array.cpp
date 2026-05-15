class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int min = nums[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid] && nums[mid] > nums[high]){
                low = mid + 1;
            }
            else if(nums[low] > nums[mid] && nums[mid] <= nums[high]){
                high = mid;
            }
            else{
                return nums[low];
            }
        }
        return -1;
    }
};