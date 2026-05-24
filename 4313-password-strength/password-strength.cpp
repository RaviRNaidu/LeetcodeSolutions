class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> mpp;
        int ans = 0;
        for(int i=0;i<password.size();i++){
            if(password[i] >= 'a' && password[i] <= 'z'){
                if(mpp.find(password[i]) == mpp.end()){
                    ans += 1;
                }
            }
            else if(password[i] >= 'A' && password[i] <= 'Z'){
                if(mpp.find(password[i]) == mpp.end()){
                    ans += 2;
                }
            }
            else if(password[i] >= '0' && password[i] <= '9'){
                if(mpp.find(password[i]) == mpp.end()){
                    ans += 3;
                }
            }
            else{
                if(mpp.find(password[i]) == mpp.end()){
                    ans += 5;
                }
            }
            mpp[password[i]] = 1;
        }
        return ans;
    }
};