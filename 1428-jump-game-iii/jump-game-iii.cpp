class Solution {
    bool recursion(int index, vector<int> &arr, int n, vector<int> &vis){
        if(index < 0 || index >= n) return false;
        if(vis[index] != 0) return false;
        if(arr[index] == 0) return true;

        vis[index] = 1;
        bool sum = recursion(index + arr[index], arr, n, vis);
        bool sub = recursion(index - arr[index], arr, n, vis);

        return (sum || sub);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return recursion(start, arr, n, vis);
    }
};