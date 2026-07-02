class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> mpp1;
        unordered_map<char, vector<int>> mpp2;
        int n = s.size();
        for(int i=0;i<n;i++){
            mpp1[s[i]].push_back(i);
            mpp2[t[i]].push_back(i);
        }

        if(mpp1.size() != mpp2.size()) return false;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            char sh = t[i];
            if(mpp1[ch] != mpp2[sh]) return false;
        }
        return true;
    }
};