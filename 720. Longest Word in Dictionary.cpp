class Solution {
public:
    string longestWord(vector<string>& words) {

        unordered_set<string> builtWords;
        string result = "";

        sort(words.begin(), words.end());

        for(auto word: words) {
            if(word.size() == 1 || builtWords.count(word.substr(0, word.size() - 1))) {
                builtWords.insert(word);

                if(word.size() > result.size()) {
                    result = word;
                }
            }
        } 
        return result;
        
    }
};