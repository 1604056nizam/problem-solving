class Solution {
public:
    string convertInputString(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                result += tolower(s[i]);
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        string result = convertInputString(s);
        int start = 0, end = result.size() - 1;

        while (start < end) {
            if (result[start] != result[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};