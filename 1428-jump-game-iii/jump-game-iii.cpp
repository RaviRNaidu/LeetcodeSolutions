class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index] == 0) return true;
            if(vis[index] != 0) continue;

            vis[index] = 1;
            
            int sum = index + arr[index];
            if(sum < n) q.push(sum);
            int sub = index - arr[index];
            if(sub >= 0) q.push(sub);
        }
        return false;
    }
};