class Solution {
    static bool com(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), com);
        int n = intervals.size();
        int l = intervals[0][0];
        int r = intervals[0][1];
        int cnt = 1;
        for(int i=1;i<n;i++){
            int newl = intervals[i][0];
            int newR = intervals[i][1];
            if(newR <= r && newl >= l){
                continue;
            }
            else{
                cnt++;
                l = newl;
                r = newR;
            }
        }
        return cnt;
    }
};