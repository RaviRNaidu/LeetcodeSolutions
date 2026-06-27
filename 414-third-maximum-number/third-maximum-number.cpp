class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long maxi = nums[0];
        long long secMaxi = LLONG_MIN;
        long long thirdMaxi = LLONG_MIN;
        for(int i=1;i<n;i++){
            if(nums[i] == maxi || nums[i] == secMaxi || nums[i] == thirdMaxi) continue;
            if(nums[i] > maxi){
                thirdMaxi = secMaxi;
                secMaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secMaxi){
                thirdMaxi = secMaxi;
                secMaxi = nums[i];
            }
            else if(nums[i] > thirdMaxi){
                thirdMaxi = nums[i];
            }
        }
        if(thirdMaxi == LLONG_MIN) return (int)maxi;
        return (int)thirdMaxi;
    }
};