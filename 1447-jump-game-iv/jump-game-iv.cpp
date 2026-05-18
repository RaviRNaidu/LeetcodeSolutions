class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int index = q.front();
                q.pop();

                if(index == n - 1) return jumps;

                // left
                if(index - 1 >= 0 && !vis[index - 1]){
                    vis[index - 1] = 1;
                    q.push(index - 1);
                }

                // right
                if(index + 1 < n && !vis[index + 1]){
                    vis[index + 1] = 1;
                    q.push(index + 1);
                }

                // same value jumps
                for(auto it : mpp[arr[index]]){

                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }

                // VERY IMPORTANT
                mpp[arr[index]].clear();
            }

            jumps++;
        }

        return -1;
    }
};