class Solution {
public:
    int numSubmat(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> height(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    height[j] += 1;
                }
                else height[j] = 0;

                int sum = 0; int h = height[j];
                for(int k=j;k>=0;k--){
                    h = min(h, height[k]);
                    sum += h;
                }
                ans += sum;
            }
        }
        return ans;
    }
};