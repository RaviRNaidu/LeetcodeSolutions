class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            char ch = chars[i];
            int cnt = 0;
            while(i < n && chars[i] == ch){
                cnt++;
                i++;
            }
            if(cnt == 1){
                chars[index++] = ch;
            }
            else{
                chars[index++] = ch;
                string count = to_string(cnt);
                for(char ch : count){
                    chars[index++] = ch;
                }
            }
            i--;
        }
        return index;
    }
};