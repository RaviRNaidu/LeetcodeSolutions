class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> pSol;
        int n = s.size();
        int len = n;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=i;j<n;j++){
                if(cnt > k) break;
                if(s[j] == '1'){
                    cnt++;
                }
                if(cnt == k){
                    if(len > j-i+1){
                        len = j-i+1;
                        pSol.clear();
                        pSol.push_back(s.substr(i, j-i+1));
                    }
                    else if(len == j-i+1){
                        pSol.push_back(s.substr(i, j-i+1));
                    }
                }
            }
        }
        if(pSol.empty()) return "";
        string ans = pSol[0];
        for(auto it : pSol){
            ans = min(ans, it);
        }
        return ans;
    }
};