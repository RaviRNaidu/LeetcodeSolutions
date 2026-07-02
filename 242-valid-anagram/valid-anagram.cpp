class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;
        int hash[26] = {0};
        for(int i=0;i<n;i++){
            hash[s[i] - 'a']++;
        }
        for(int i=0;i<n;i++){
            hash[t[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(hash[i] > 0) return false;
        }
        return true;
    }
};