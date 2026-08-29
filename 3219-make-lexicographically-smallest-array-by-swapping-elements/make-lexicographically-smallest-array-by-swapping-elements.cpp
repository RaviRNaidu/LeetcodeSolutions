class disjointSet{
    public:
    vector<int> parent, size;

    disjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        size.resize(n, 1);
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int uparU = findUPar(u);
        int uparV = findUPar(v);

        if(uparU == uparV) return;

        else if(size[uparU] < size[uparV]){
            parent[uparU] = uparV;
            size[uparV] += size[uparU];
        }
        else{
            parent[uparV] = uparU;
            size[uparU] += size[uparV];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for(int i=0;i<n;i++){
            pairs[i] = {nums[i], i};
        }

        sort(pairs.begin(), pairs.end());

        disjointSet ds(n);

        for(int i=1;i<n;i++){
            if(pairs[i].first - pairs[i-1].first <= limit){
                ds.unionBySize(pairs[i-1].second, pairs[i].second);
            }
        }

        unordered_map<int, vector<int>> mppVal;
        unordered_map<int, vector<int>> mppIdx;
        for(int i=0;i<n;i++){
            int root = ds.findUPar(i);
            mppVal[root].push_back(nums[i]);
            mppIdx[root].push_back(i);
        }

        vector<int> solution(n);
        for(auto& it : mppVal){
            auto& value = it.second;
            auto& index = mppIdx[it.first];

            sort(index.begin(), index.end());
            sort(value.begin(), value.end());

            for(int k=0;k<value.size();k++){
                solution[index[k]] = value[k];
            }
        }

        return solution;
    }
};