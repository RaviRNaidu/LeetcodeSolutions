class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
            }
            else if(s[i] == '*' && ans.length() > 0){
                ans.pop_back();
            }
            else if(s[i] == '#'){
                ans += ans;
            }
            else{
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};