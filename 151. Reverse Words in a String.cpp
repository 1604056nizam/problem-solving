class Solution {
public:
    string reverseWords(string s) {

        string word = "", result = "";
        stack<string> reverseWords;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (word.size()) {
                    reverseWords.push(word);
                }
                word = "";
                continue;
            }
            word += s[i];
        }

        if (word.size())
            reverseWords.push(word);
        word = "";

        while (!reverseWords.empty()) {
            word = reverseWords.top();
            result += word;
            reverseWords.pop();
            if (reverseWords.size())
                result += " ";
        }

        return result;
    }
};