class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n == 1){
            ans.push_back(nums[0]);
            return ans;
        }

        ans.push_back(nums[0]);

        vector<int> maxi(n);
        maxi[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i] > maxi[i+1]){
                maxi[i] = nums[i];
            }
            else{
                maxi[i] = maxi[i+1];
            }
        }

        int max = nums[0];
        for(int i=1;i<n;i++){
            if(i == n-1) {
                ans.push_back(nums[i]);
            }
            else if(nums[i] > max){
                ans.push_back(nums[i]);
                max = nums[i];
            }
            else if(nums[i] > maxi[i+1]){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};