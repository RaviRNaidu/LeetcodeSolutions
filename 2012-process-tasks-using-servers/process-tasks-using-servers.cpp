class Solution {
    void release(long long time, priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>& busy,
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>& free, vector<int>& servers){
        while(!busy.empty() && busy.top().first <= time){
            int idx = busy.top().second;
            busy.pop();
            free.push({servers[idx], idx});
        }
    }
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for(int i=0;i<m;i++){
            free.push({servers[i], i});
        }

        int n = tasks.size();
        vector<int> ans(n);
        long long time = 0;
        for(int i=0;i<n;i++){
            time = max(time, (long long)i);
            release(time, busy, free, servers);

            if(free.empty()){
                time = busy.top().first;
                release(time, busy, free, servers);
            }

            long long idx = free.top().second;
            free.pop();
            ans[i] = idx;
            busy.push({time + tasks[i], idx});
        }
        return ans;
    }
};