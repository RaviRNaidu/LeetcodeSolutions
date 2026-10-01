class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '[')){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};