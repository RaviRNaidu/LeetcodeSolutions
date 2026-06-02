class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int finalAns = INT_MAX;
        int n = ls.size();
        int m = ws.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int finish1 = max(ls[i] + ld[i], ws[j]) + wd[j];
                int finish2 = max(ws[j] + wd[j], ls[i]) + ld[i];

                finalAns = min(finalAns, min(finish1, finish2));
            }
        }
        return finalAns;
    }
};