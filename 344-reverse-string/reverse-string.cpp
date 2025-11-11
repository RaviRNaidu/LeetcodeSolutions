class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st = 0;
        int end = n-1;
        while(st < end){
            char temp = s[st];
            s[st] = s[end];
            s[end] = temp;
            st++;
            end--;
        }
        
        cout<<"[";
        for(int i=0;i<n;i++){
            cout<<s[i]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
};