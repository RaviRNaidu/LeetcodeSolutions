class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        stack<char> st;
        while(i < n){
            if(s[i] == '('){
                st.push('(');
                i++;
            }
            else{
                int cnt = 0;
                while(i < n && s[i] != '('){
                    cnt++;
                    if(cnt == 2){
                        if(st.empty() || st.top() == ')'){
                            st.push(')');
                        }
                        else{
                            st.pop();
                        }
                        cnt = 0;
                    }
                    i++;
                }
                if(cnt == 1){
                    ans++;
                    if(st.empty() || st.top() == ')'){
                        st.push(')');
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }

        while(!st.empty()){
            if(st.top() == '('){
                ans += 2;
            }
            else{
                ans += 1;
            }
            st.pop();
        }

        return ans;
    }
};