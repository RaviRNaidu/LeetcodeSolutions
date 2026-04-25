class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        string st = strs[0];
        for(int i=1;i<strs.size();i++){
            string comp = strs[i];
            int len = min(st.length(),comp.length());
            string temp = "";
            for(int j=0;j<len;j++){
                if(st[j] == comp[j]){
                    temp += char(st[j]);
                }
                else{
                    break;
                }
            }
            if(temp.length() < ans.length()){
                ans = temp;
            }
        }
        return ans;
    }
};