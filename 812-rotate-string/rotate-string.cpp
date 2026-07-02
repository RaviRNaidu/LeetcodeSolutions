class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        vector<int> index;
        for(int i=0;i<n;i++){
            if(goal[0] == s[i]){
                index.push_back(i);
            }
        }

        if(index.size() == 0) return false;

        for(int j=0;j<index.size();j++){
            bool flag = true;
            for(int i=0;i<n;i++){
                if(goal[i] != s[(index[j] + i) % n]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};