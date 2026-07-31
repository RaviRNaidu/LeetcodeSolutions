class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> hash(26, 0);
        for(int i=0;i<n;i++){
            hash[word[i] - 'a']++;
        }

        sort(hash.rbegin(), hash.rend());

        int ans = 0;
        int cnt = 0;
        int mul = 1;
        for(int i=0;i<26;i++){
            ans += (hash[i] * mul);
            cnt++;

            if(cnt == 8){
                cnt = 0;
                mul++;
            }
        }
        
        return ans;
    }
};