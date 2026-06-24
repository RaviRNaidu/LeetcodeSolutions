class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second == x) return it.first;
        }

        return -1;
    }
};