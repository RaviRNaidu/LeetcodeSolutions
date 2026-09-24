class Solution {
    void nextpermutation(vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, unordered_map<int, int>& mpp, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(auto it : nums){
            if(mpp[it] == 1){
                mpp[it] = 0;
                temp.push_back(it);
                nextpermutation(temp, nums, ans, mpp, n);
                temp.pop_back();
                mpp[it] = 1;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it] = 1;
        }
        vector<int> temp;
        nextpermutation(temp, nums, ans, mpp, n);
        return ans;
    }
};