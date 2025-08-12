class Solution {
    vector<int> printrow(int row){
        vector<int> temp;
        int res = 1;
        temp.push_back(res);
        for(int col=1;col<row;col++){
            res = res * (row - col);
            res = res / col;
            temp.push_back(res);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(printrow(i));
        }
        return ans;
    }
};