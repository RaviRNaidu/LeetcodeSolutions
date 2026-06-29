class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int m = word.length();
        unordered_map<string, int> mpp;
        for(auto it : patterns){
            mpp[it]++;
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            if(mpp.empty()) break;
            string temp = "";
            for(int j=i;j<m;j++){
                temp += word[j];
                if(mpp.count(temp) > 0){
                    ans += mpp[temp];
                    mpp.erase(temp);
                }
            }
        }
        return ans;
    }
};