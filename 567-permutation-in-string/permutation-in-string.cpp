class Solution {
    bool check(int arr1[], int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        for(int i=0;i<s1.length();i++){
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        if(mpp1 == mpp2){
            return true;
        }

        int left = 0;
        
        for(int right = s1.length();right<s2.length();right++){
            mpp2[s2[right]]++;
            mpp2[s2[left]]--;

            if(mpp2[s2[left]] == 0){
                mpp2.erase(s2[left]);
            }

            left++;

            if(mpp1 == mpp2){
                return true;
            }
        }
        return false;
    }
};
