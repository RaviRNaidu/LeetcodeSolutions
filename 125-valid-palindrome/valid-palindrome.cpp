class Solution {
public:
    bool isalnum(char c){
        if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            return true;
        }
        else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int last = n-1;
        while(start < last){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[last])){
                last--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[last])){
                return false;
            }
            start++;
            last--;
        }
        return true;
    }
};