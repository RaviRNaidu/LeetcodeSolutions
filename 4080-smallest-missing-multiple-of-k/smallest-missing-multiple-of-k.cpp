class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        
        int temp = k;
        while(true){
            if(mpp.find(temp) == mpp.end()){
                return temp;
            }
            temp += k;
        }

        return -1;
    }
};