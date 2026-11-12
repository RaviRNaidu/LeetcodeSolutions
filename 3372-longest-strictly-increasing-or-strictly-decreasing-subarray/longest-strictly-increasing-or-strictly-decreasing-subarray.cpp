class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n-1;i++){
            int f = nums[i];
            int s = nums[i+1];
            bool sorted = true;
            if(f > s){
                sorted = false;
                ans = max(ans, 2);
            }
            else if(f == s) continue;
            else ans = max(ans, 2);

            for(int j=i+2;j<n;j++){
                if(sorted){
                    if(nums[j] > s){
                        ans = max(ans, j-i+1);
                        s = nums[j];
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(nums[j] < s){
                        ans = max(ans, j-i+1);
                        s = nums[j];
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};