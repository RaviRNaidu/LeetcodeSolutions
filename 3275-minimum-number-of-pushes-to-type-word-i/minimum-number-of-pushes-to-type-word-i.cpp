class Solution {
    static bool com(int a, int b){
        return a > b;
    }
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> hash(26, 0);
        for(int i=0;i<n;i++){
            hash[word[i] - 'a']++;
        }

        sort(hash.begin(), hash.end(), com);
        int cnt = 0;
        int ans = 0;
        int mul = 1;
        for(int i=0;i<26;i++){
            ans = ans + (hash[i] * mul);
            cnt++;
            if(cnt == 8){
                cnt = 0;
                mul++;
            }
        }
        return ans;
    }
};