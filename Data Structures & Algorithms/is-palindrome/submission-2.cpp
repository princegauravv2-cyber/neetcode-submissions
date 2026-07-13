class Solution {
public:
    char tolower(char c) {
        if(c >= 65 && c <= 90)
            c = c + 32;
        return c;
    }
    bool isAlpha(char c) {
        return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && !isAlpha(s[i])) i++;
            while(i < j && !isAlpha(s[j])) j--;
            if(i < j && tolower(s[i]) != tolower(s[j]))
                return false;
            i++; j--;
        }
        return true;
    }
};
