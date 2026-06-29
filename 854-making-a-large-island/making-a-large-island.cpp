class disjointSet {
    public:
    vector<int> parent;
    vector<int> size;

    disjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if(up_u == up_v) return;
        else if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n * n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr = (i*n) + j;
                if(grid[i][j] == 0) continue;
                if(i > 0 && grid[i-1][j] == 1){
                    ds.unionBySize(curr, curr - n);
                } 
                if(j > 0 && grid[i][j-1] == 1){
                    ds.unionBySize(curr, curr - 1);
                }
            }
        }

        int ans = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr = (i*n) + j;
                if(grid[i][j] == 1){
                    int check = ds.findUPar(curr);
                    ans = max(ans, ds.size[check]);
                }
                else{
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                            int up = ds.findUPar((nrow * n) + ncol);
                            st.insert(up);
                        }
                    }
                    int sum = 1;
                    for(auto it : st){
                        sum += ds.size[it];
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};