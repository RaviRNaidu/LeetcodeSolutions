class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<int> index;
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i]){
                index.push_back(i);
            }
        }

        vector<vector<string>> ans;
        if(index.size() == 0){
            ans.push_back({s1, s2});
            return ans;
        }
        int prev = index[0];
        if(prev != 0){
            ans.push_back({s1.substr(0, prev), s2.substr(0, prev)});
        }

        for(int i=1;i<index.size();i++){
            if(index[i] - prev > 1){
                ans.push_back({s1.substr(prev+1, index[i] - prev - 1), s2.substr(prev+1, index[i] - prev - 1)});
            }
            prev = index[i];
        }

        if(prev != n-1){
            ans.push_back({s1.substr(prev+1), s2.substr(prev+1)});
        }

        return ans;
    }
};