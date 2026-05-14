class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int max = n-1;
        vector<int> hash(n,0);
        for(int i=0;i<n;i++){
            if(nums[i] > max){
                return false;
            }
            if(nums[i] != n-1 && hash[nums[i]] != 0){
                return false;
            }
            hash[nums[i]] += 1;
        }
        if(hash[n-1] > 2) return false;
        return true;
    }
};