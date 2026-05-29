class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n = prerequisites.size();
        vector<int> inDeg(numCourses, 0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDeg[prerequisites[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
            ans.push_back(node);
        }

        if(ans.size() != numCourses) return false;
        return true;
    }
};