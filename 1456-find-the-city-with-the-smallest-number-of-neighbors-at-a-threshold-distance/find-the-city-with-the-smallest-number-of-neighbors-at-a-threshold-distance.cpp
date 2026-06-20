class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n, 1e9));
        for(int i=0;i<n;i++){
            dis[i][i] = 0;
        }

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];

            dis[u][v] = d;
            dis[v][u] = d;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k] == 1e9 || dis[k][j] == 1e9) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int mini = n;
        int index = -1;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(dis[i][j] <= distanceThreshold) sum++;
            }
            if(sum <= mini){
                mini = sum;
                index = i;
            }
        }
        return index;
    }
};