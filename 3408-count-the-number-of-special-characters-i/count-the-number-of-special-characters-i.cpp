class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);

        for(auto it : word){
            if(islower(it)){
                lower[it - 'a'] = 1;
            }
            else{
                upper[it - 'A'] = 1;
            }
        }

        for(int i=0;i<26;i++){
            if(upper[i] && lower[i]) cnt++;
        }

        return cnt;
    }
};