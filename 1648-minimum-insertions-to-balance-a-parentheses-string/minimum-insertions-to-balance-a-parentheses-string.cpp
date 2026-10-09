class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        string temp = "";
        while(i < n){
            if(s[i] == '('){
                temp += s[i];
                i++;
            }
            else{
                int cnt = 0;
                while(i < n && s[i] != '('){
                    cnt++;
                    if(cnt == 2){
                        temp += ')';
                        cnt = 0;
                    }
                    i++;
                }
                if(cnt == 1){
                    ans++;
                    temp += ')';
                }
            }
        }

        stack<char> st;
        for(auto it : temp){
            if(it == '('){
                st.push(it);
            }
            else{
                if(st.empty() || st.top() == ')'){
                    st.push(it);
                }
                else{
                    st.pop();
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