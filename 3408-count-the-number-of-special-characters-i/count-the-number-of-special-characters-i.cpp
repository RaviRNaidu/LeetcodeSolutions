class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mpp;
        int n = word.size();
        int cnt = 0;
        unordered_map<char, int> ans;
        for(int i=0;i<n;i++){
            if(ans.find(toupper(word[i])) != ans.end()){
                continue;
            } 
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(mpp.find(toupper(word[i])) != mpp.end()){
                    cnt++;
                    ans[toupper(word[i])]++;
                    mpp.erase(toupper(word[i]));
                }
                else{
                    mpp[word[i]]++;
                }
            }
            else{
                if(mpp.find(tolower(word[i])) != mpp.end()){
                    cnt++;
                    ans[toupper(word[i])]++;
                    mpp.erase(tolower(word[i]));
                }
                else{
                    mpp[word[i]]++;
                }
            }
        }
        return cnt;
    }
};