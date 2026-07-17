class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n);
        for(int j=0;j<triangle[n-1].size();j++){
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector<int> prev(n);
            for(int j=0;j<triangle[i].size();j++){
                int down = triangle[i][j] + front[j];
                int rightDown = triangle[i][j] + front[j+1];

                prev[j] = min(down, rightDown);
            }
            front = prev;
        }
        return front[0];
    }
};