class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        int n = str.length();
        for(int i=0;i<n;i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char pop = st.top();
                st.pop();
                switch(pop){
                    case '(':
                        if(str[i] != ')'){
                            return false;
                        }
                        break;
                    case '{':
                        if(str[i] != '}'){
                            return false;
                        }
                        break;
                    case '[':
                        if(str[i] != ']'){
                            return false;
                        }
                        break;
                };
            }
        }
        if(st.empty()){
            return true;
        }
        else return false;
    }
};