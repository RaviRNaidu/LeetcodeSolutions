class Solution {
public:
    vector<int> buildArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(arr[arr[i]]);
        }
        return ans;
    }
};