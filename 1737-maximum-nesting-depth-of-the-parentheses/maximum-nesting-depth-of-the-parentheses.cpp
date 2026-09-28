class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')'){
                st.push(s[i]);
                ans = max(ans, (int)st.size());
            }
            else if(s[i] == '('){
                st.pop();
            }
        }
        return ans;
    }
};