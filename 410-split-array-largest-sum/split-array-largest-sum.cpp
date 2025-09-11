class Solution {
    int subarrays(vector<int> arr, int max){
        int subarray = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            if(sum + arr[i] <= max){
                sum += arr[i];
            }
            else{
                subarray ++;
                sum = arr[i];
            }
        }
        return subarray;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int high = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            high = max(high,nums[i]);
            sum += nums[i];
        }

        while(high <= sum){
            int mid = (high + sum) / 2;
            int subarray = subarrays(nums, mid);
            if(subarray > k){
                high = mid + 1;
            }
            else{
                sum = mid - 1;
            }
        }
        return high;
    }
};