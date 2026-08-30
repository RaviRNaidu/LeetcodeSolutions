class Solution {
    int calLeft(int idxMini, int idxMax){
        int sum = 0;
        if(idxMini < idxMax){
            sum = idxMini + 1;
            sum += (idxMax - idxMini);
        }
        else{
            sum = idxMax + 1;
            sum += (idxMini - idxMax);
        }
        return sum;
    }

    int calRight(int idxMini, int idxMax, int n){
        int sum = 0;
        if(idxMini > idxMax){
            sum = n - idxMini;
            sum += (idxMini - idxMax);
        }
        else{
            sum = n - idxMax;
            sum += (idxMax - idxMini);
        }
        return sum;
    }

    int helper(int idxMini, int idxMaxi, int n){
        int sum = 0;
        if(idxMini + 1 < n - idxMini){
            sum += idxMini + 1;
            if(idxMaxi > idxMini){
                sum += min(idxMaxi - idxMini, n - idxMaxi);
            }
        }
        else{
            sum += n - idxMini;
            if(idxMaxi < idxMini){
                sum += min(idxMini - idxMaxi, idxMaxi + 1);
            }
        }
        return sum;
    }
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int idxMini = -1;
        int idxMax = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] < mini){
                mini = nums[i];
                idxMini = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                idxMax = i;
            }
        }
        int ans = INT_MAX;
        ans = min(ans, calLeft(idxMini, idxMax));
        ans = min(ans, calRight(idxMini, idxMax, n));
        ans = min(ans, helper(idxMini, idxMax, n));
        return ans;
    }
};