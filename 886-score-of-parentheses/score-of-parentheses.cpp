class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int v = st.top();
                st.pop();
                v = max(2 * v, 1);
                st.top() += v;
            }
        }
        return st.top();
    }
};