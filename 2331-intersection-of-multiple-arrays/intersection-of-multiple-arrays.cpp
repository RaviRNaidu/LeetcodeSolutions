class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> check(1001, 0);
        for(auto it : nums){
            for(auto i : it){
                check[i]++;
            }
        }

        vector<int> ans;
        for(int i=1;i<1001;i++){
            if(check[i] == n){
                ans.push_back(i);
            }
        }

        return ans;
    }
};