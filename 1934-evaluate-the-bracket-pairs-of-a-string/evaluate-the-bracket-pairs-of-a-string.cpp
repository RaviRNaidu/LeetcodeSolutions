class Solution {
    void helper(string& temp, unordered_map<string, string>& mpp){
        if(mpp.find(temp) != mpp.end()){
            temp = mpp[temp];
        }
        else{
            temp = "?";
        }
    }
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto& it : knowledge){
            mpp[it[0]] = it[1];
        }

        int n = s.size();
        string ans = "";
        int i = 0;
        while(i < n){
            if(s[i] != '('){
                ans += s[i];
            }
            else{
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                helper(temp, mpp);
                ans += temp;
            }
            i++;
        }
        return ans;
    }
};