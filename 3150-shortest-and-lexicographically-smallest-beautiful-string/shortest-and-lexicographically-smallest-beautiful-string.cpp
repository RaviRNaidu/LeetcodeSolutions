class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string pSol = "";
        int n = s.size();
        int len = n + 1;
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
                        pSol = s.substr(i, j-i+1);
                    }
                    else if(len == j-i+1){
                        pSol = min(pSol, s.substr(i, j-i+1));
                    }
                }
            }
        }
        return pSol;
    }
};