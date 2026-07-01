class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        unordered_map<int, pair<int, int>> mpp;
        int cnt = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    mpp[cnt++] = {i,j};
                }
            }
        }
        vector<vector<int>> dis(n, vector<int> (n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;
        int maxDis = n;
        for(auto it : mpp){
            maxDis = min(maxDis, abs(0 - it.second.first) + abs(0 - it.second.second));
        }
        if(!grid[0][0]){
            pq.push({maxDis, {0, 0}});
        }
        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !grid[nrow][ncol]){
                    int currDis = n;
                    for(auto it : mpp){
                        currDis = min(currDis, abs(nrow - it.second.first) + abs(ncol - it.second.second));
                    }
                    currDis = min(currDis, dist);
                    if(currDis > dis[nrow][ncol]){
                        dis[nrow][ncol] = currDis;
                        pq.push({currDis, {nrow, ncol}});
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};