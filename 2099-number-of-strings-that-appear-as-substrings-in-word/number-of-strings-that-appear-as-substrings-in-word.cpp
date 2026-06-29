class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int m = word.length();
        int ans = 0;
        for(auto it : patterns){
            string temp = it;
            int size = temp.size();
            for(int i=0;i<m;i++){
                string check = word.substr(i, size);
                if(check == temp){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};