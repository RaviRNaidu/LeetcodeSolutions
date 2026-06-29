class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int m = word.length();
        int ans = 0;
        for(auto it : patterns){
            string temp = it;
            if(word.contains(temp)){
                ans++;
            }
        }
        return ans;
    }
};