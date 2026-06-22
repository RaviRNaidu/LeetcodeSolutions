class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        int hash[26] = {0};
        for(int i=0;i<n;i++){
            hash[text[i] - 'a']++;
        }

        int ans = 1e9;
        string b = "balon";
        for(int i=0;i<b.size();i++){
            if(hash[b[i] - 'a'] == 0) return 0;
            else if(b[i] == 'l' || b[i] == 'o'){
                ans = min(ans, hash[b[i] - 'a'] / 2);
            }
            else ans = min(ans, hash[b[i] - 'a']);
        }
        return ans;
    }
};