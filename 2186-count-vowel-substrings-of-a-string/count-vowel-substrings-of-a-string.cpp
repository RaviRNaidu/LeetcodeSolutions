class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;
        unordered_map<char, int> mpp;
        for(int i=0;i<n;i++){
            if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u'){
                continue;
            }
            mpp.clear();
            for(int j=i;j<n;j++){
                if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'){
                    mpp[word[j]]++;
                    if(mpp.size() == 5){
                        ans++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};