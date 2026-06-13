class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        for(int i=0;i<n;i++){
            string str = words[i];
            int sum = 0;
            for(int j=0;j<str.length();j++){
                sum = (sum + weights[str[j] - 97]) % 26;
            }
            char c = 122 - sum;
            ans += c;
        }
        return ans;
    }
};