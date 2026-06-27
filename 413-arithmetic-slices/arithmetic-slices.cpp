class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int prev = nums[i];
            bool first = true;
            int diff;
            for(int j=i+1;j<n;j++){
                if(first){
                    diff = nums[j] - prev;
                    prev = nums[j];
                    first = false;
                }
                else{
                    int newDiff = nums[j] - prev;
                    prev = nums[j];
                    if(newDiff != diff) break;
                }

                if(j - i + 1 >= 3){
                    ans++;
                }
            }
        }
        return ans;
    }
};