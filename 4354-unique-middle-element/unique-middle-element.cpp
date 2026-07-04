class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        int num = nums[mid];
        for(int i=0;i<n;i++){
            if(nums[i] == num && i != mid){
                return false;
            }
        }
        return true;
    }
};