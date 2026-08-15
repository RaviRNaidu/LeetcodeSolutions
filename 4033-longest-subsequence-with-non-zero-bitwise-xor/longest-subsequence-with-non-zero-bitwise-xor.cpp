class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xorr = xorr ^ nums[i];
        }
        if(xorr) return n;
        else{
            for(int i=0;i<n;i++){
                xorr = xorr ^ nums[i];
                if(xorr) return n-1;
            }
        }
        return 0;
    }
};