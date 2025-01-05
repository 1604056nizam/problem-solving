class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordListSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        wordListSet.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int distance = q.front().second;
            q.pop();

            for(int i = 0; i < word.size(); i++) {
                char prevCharacter = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(wordListSet.find(word) != wordListSet.end()) {
                        q.push({word, distance + 1});
                        wordListSet.erase(word);
                        if(word == endWord) {
                            return distance + 1;
                        }
                    }
                }
                word[i] = prevCharacter;
            }
        }

        return 0;
    }
};