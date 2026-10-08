class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] == '('){
                    ans += s[i];
                    st.push(s[i]);
                }
                else{
                    if(st.size() > 1){
                        ans += s[i];
                    }
                    st.pop();
                }
            }
        }
        return ans;
    }
};