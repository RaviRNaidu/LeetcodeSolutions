class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        ans.push_back({arr[0][0], arr[0][1]});
        int n = arr.size();
        for(int i=1;i<n;i++){
            int l = arr[i][0];
            int r = arr[i][1];
            auto it = ans.back();
            if(it[1] + 1 >= l){
                it[1] = max(it[1], r);
                ans.pop_back();
                ans.push_back({it[0], it[1]});
            }
            else{
                ans.push_back({l, r});
            }
        }

        vector<vector<int>> finall;
        for(int i=0;i<ans.size();i++){
            int l = ans[i][0];
            int r = ans[i][1];
            if(l > freeEnd || r < freeStart){
                finall.push_back({l, r});
            }
            else{
                if(l < freeStart){
                    finall.push_back({l, freeStart - 1});
                }
                if(r > freeEnd){
                    finall.push_back({freeEnd + 1, r});
                }
            }
        }
        return finall;
    }
};