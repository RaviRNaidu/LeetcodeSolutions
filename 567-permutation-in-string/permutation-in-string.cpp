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
        int n = s1.length();
        int arr1[26] = {0};
        for(int i=0;i<n;i++){
            arr1[s1[i] - 'a']++;
        }

        int windowSize = n;
        for(int i=0;i<s2.length();i++){
            int arr2[26] = {0};
            int windowIndex = 0;
            int index = i;
            while((windowIndex < windowSize) && (index < s2.length())){
                arr2[s2[index] - 'a']++;
                index++;
                windowIndex++;
            }
            if(check(arr1,arr2)){
                return true;
            }
        }
        return false;
    }
};