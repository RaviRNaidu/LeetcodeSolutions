class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);

        for(int i=n-1;i>=0;i--){
            if(islower(word[i])){
                if(lastLower[word[i] - 'a'] == -1){
                    lastLower[word[i] - 'a'] = i;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(isupper(word[i])){
                if(firstUpper[word[i] - 'A'] == -1){
                    firstUpper[word[i] - 'A'] = i;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<26;i++){
            if(lastLower[i] != -1 && firstUpper[i] != -1){
                if(lastLower[i] < firstUpper[i]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};