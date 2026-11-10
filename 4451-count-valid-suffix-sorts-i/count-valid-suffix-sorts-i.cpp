class Solution {
    bool check(vector<int>& nums, vector<int>& target, int n){
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mpp.find(target[i]) == mpp.end()){
                return false;
            }
            mpp[target[i]]--;

            if(mpp[target[i]] == 0){
                mpp.erase(target[i]);
            }
        }

        if(!mpp.empty()) return false;
        return true;
    }
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        bool flag = check(nums, target, n);
        if(!flag) return 0;
        int index = n-1;
        int prev = target[n-1];
        for(int i=n-2;i>=0;i--){
            if(target[i] >= prev){
                prev = target[i];
                index = i;
            }
            else{
                break;
            }
        }

        bool check = false;
        for(int i=0;i<index;i++){
            if(nums[i] != target[i]){
                check = true;
                break;
            }
        }

        if(check){
            return 0;
        }

        int ans = 0;
        for(int i=index;i<n;i++){
            ans++;
            if(nums[i] != target[i]){
                break;
            }
        }
        return ans;
    }
};