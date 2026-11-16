class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(n > k){
            int n = s.size();
            if(n <= k) break;
            string news = "";
            for(int i=0;i<n;i+=k){
                int newSum = 0;
                for(int j=i;j<n && j<i+k;j++){
                    newSum += s[j] - '0';
                }
                news += to_string(newSum);
            }
            s = news;
        }
        return s;
    }
};