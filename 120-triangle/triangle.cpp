class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n);
        for(int j=0;j<triangle[n-1].size();j++){
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int down = triangle[i][j] + front[j];
                int rightDown = triangle[i][j] + front[j+1];

                front[j] = min(down, rightDown);
            }
        }
        return front[0];
    }
};