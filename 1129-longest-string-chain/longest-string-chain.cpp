class Solution {
    static bool com(string &s, string &t){
        return s.size() < t.size();
    }

    bool check(string&s, string& t){
        int n = s.size();
        int m = t.size();
        if(n+1 != m) return false;

        int i = 0;
        int j = 0;
        bool check = false;
        while(i < n){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                if(check) return false;
                check = true;
                j++;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 1;
        sort(words.begin(), words.end(), com);
        vector<int> prev(n+2, 0);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n+1;j++){
                int notTake = prev[j];
                int take = 0;
                if(j == n+1 || check(words[i-1], words[j-1])){
                    take = 1 + prev[i];
                }
                prev[j] = max(notTake, take);
            }
        }
        ans = max(ans, prev[n+1]);
        return ans;
    }
};