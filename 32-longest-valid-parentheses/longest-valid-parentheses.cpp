class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<int, char>> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push({i, s[i]});
            }
            else{
                if(st.empty() || st.top().second == ')'){
                    st.push({i, s[i]});
                }
                else{
                    st.pop();
                    if(st.empty()){
                        ans = max(ans, i + 1);
                    }
                    else{
                        ans = max(ans, i - st.top().first);
                    }
                }
            }
        }
        return ans;
    }
};