class Solution {
    bool isAlphaNum(char c){
        if(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9') return true;

        return false;
    }

public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;

        while(i<=j){
            if(!isAlphaNum(s[i]) && !isAlphaNum(s[j])){
                i++;
                j--;
                cout<<"a";
            } else if(!isAlphaNum(s[i])){
                i++;
                cout<<"b";
            } else if(!isAlphaNum(s[j])){
                j--;
                cout<<"c";
            } else{
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }

                i++;
                j--;
            }
        }

        return true;
    }
};
