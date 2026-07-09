class DisjointSet{
    public:
    vector<int> parent, size;

    public:
    DisjointSet(int n){
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i=0;i<n-1;i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                ds.unionBySize(i, i+1);
            }
        }

        int m = queries.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++){
            int par1 = ds.findUPar(queries[i][0]);
            int par2 = ds.findUPar(queries[i][1]);
            if(par1 == par2){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }

        return ans;
    }
};