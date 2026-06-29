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
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr = (i*n) + j;
                if(grid[i][j] == 1){
                    int check = ds.findUPar(curr);
                    ans = max(ans, ds.size[check]);
                }
                else{
                    int sum = 0;
                    unordered_map<int, int> mpp;
                    if(i > 0 && grid[i-1][j] == 1){
                        int up_Up = ds.findUPar(curr - n);
                        if(mpp.find(up_Up) == mpp.end()){
                            sum += ds.size[up_Up];
                            mpp[up_Up]++;
                        }
                    }
                    if(j < n-1 && grid[i][j+1] == 1){
                        int right_Up = ds.findUPar(curr + 1);
                        if(mpp.find(right_Up) == mpp.end()){
                            sum += ds.size[right_Up];
                            mpp[right_Up]++;
                        }
                    }
                    if(i < n-1 && grid[i+1][j] == 1){
                        int down_Up = ds.findUPar(curr + n);
                        if(mpp.find(down_Up) == mpp.end()){
                            sum += ds.size[down_Up];
                            mpp[down_Up]++;
                        }
                    }
                    if(j > 0 && grid[i][j-1] == 1){
                        int left_Up = ds.findUPar(curr - 1);
                        if(mpp.find(left_Up) == mpp.end()){
                            sum += ds.size[left_Up];
                            mpp[left_Up]++;
                        }
                    }
                    ans = max(ans, sum + 1);
                }
            }
        }
        return ans;
    }
};