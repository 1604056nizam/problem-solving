class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subResult;

        helperFunc(s, 0, subResult, result);
        return result;
    }

    void helperFunc(string& s, int startIndex, vector<string>& subResult, vector<vector<string>>&result) {
        if(startIndex == s.size()) {
            result.push_back(subResult);
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            if(isPalindrome(s, startIndex, i)) {
                subResult.push_back(s.substr(startIndex, i - startIndex + 1));
                helperFunc(s, i + 1, subResult, result);
                subResult.pop_back();
            }
        }

    }

    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};