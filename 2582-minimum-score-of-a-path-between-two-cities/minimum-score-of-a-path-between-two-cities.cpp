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

        if(up_u == up_v){
            return;
        }
        else if(size[up_u] < size[up_v]){
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
        }
        else{
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n+1);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2]; 
            ds.unionBySize(u, v);
        }

        int p = ds.findUPar(1);
        int ans = INT_MAX;
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2]; 
            
            if(ds.findUPar(u) == p){
                ans = min(ans, d);
            }
        }
        return ans;
    }
};